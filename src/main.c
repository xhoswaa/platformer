#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<stdint.h>
#include"types.h"
#include"common.h"

#define PLAYER_FRC 2500.0f
#define HITBOXES false

int main(int argc, char* argv[])
{
    SDL_Event event;
    if(!SDL_Init(SDL_INIT_VIDEO))
        return 1;
    SDL_Window *window = SDL_CreateWindow("SDL3", 800, 600, 0);
    if(!window) {SDL_Log("%s", SDL_GetError()); return 1;}
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if(!renderer) {SDL_Log("%s", SDL_GetError()); return 1;}
    
    World world = {
        .object_count = 0,
        .entity_count = 0,
    };
    game_init(&world);

    Uint64 last_time = SDL_GetTicksNS();

    bool isrunning = true;
    while (isrunning) {

        Uint64 cur_time = SDL_GetTicksNS();
        float delta_time = (cur_time - last_time) / 1000000000.0f;
        last_time = cur_time;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isrunning = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
        }
        handle_input(&world.player, PLAYER_FRC);

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