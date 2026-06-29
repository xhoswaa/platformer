#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<stdint.h>
#include"types.h"
#include"common.h"

int main(int argc, char* argv[])
{
    SDL_Event event;
    if(!SDL_Init(SDL_INIT_VIDEO))
        return 1;
    SDL_Window *window = SDL_CreateWindow("platformer", 320, 180, WINDOW_FLAGS);
    if(!window) {SDL_Log("%s", SDL_GetError()); return 1;}
    SDL_Renderer *renderer = SDL_CreateRenderer(window, "opengl");
    if(!renderer) {SDL_Log("%s", SDL_GetError()); return 1;}

    SDL_SetRenderLogicalPresentation(
        renderer,
        LOGICAL_WIDTH,
        LOGICAL_HEIGHT,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );
    
    World world = {
        .object_count = 0,
        .entity_count = 0,
    };
    game_init(renderer, &world);

    bool window_resized = false;
    bool fullscreen = false;
    Uint64 last_time = SDL_GetTicksNS();

    bool isrunning = true;
    while (isrunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_WINDOW_RESIZED) {
                SDL_SetRenderViewport(renderer, NULL);
                SDL_SetRenderLogicalPresentation(
                    renderer,
                    LOGICAL_WIDTH,
                    LOGICAL_HEIGHT,
                    SDL_LOGICAL_PRESENTATION_INTEGER_SCALE
                );
                window_resized = true;
            }
            if (event.type == SDL_EVENT_QUIT) {
                isrunning = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.scancode == SDL_SCANCODE_F11) {
                    fullscreen = !fullscreen;
                    SDL_SetWindowFullscreen(window, fullscreen);
                }
            }
        }
        handle_input(&world.player);

        Uint64 cur_time = SDL_GetTicksNS();
        float delta_time = (cur_time - last_time) / 1000000000.0f;
        last_time = cur_time;
        if (window_resized) {
            window_resized = false;
            delta_time = 0.0f;
        }

        upd_physics(
            (Entity*)&world.player,
            world.player.inp_frc,
            world.objects,
            world.object_count,
            delta_time
        );
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_entities(renderer, (Entity*)&world.player, 1, HITBOXES);
        render_entities(renderer, world.entities, world.entity_count, HITBOXES);
        render_objects(renderer, world.objects, world.object_count, HITBOXES);
        SDL_RenderPresent(renderer);
    }
    return 0;
}