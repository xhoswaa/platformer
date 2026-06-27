#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<stdint.h>
#include"types.h"
#include"common.h"

#define PLAYER_F 2500.0f
#define MAX_OBJ 128
#define MAX_ENT 64

Object objects[MAX_OBJ];
int object_count = 0;
Entity entities[MAX_ENT];
int entity_count = 0;

int main(int argc, char* argv[])
{
    if(!SDL_Init(SDL_INIT_VIDEO))
        return 1;
    SDL_Window *window = SDL_CreateWindow("SDL3", 800, 600, 0);
    if(!window) {SDL_Log("%s", SDL_GetError()); return 1;}
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if(!renderer) {SDL_Log("%s", SDL_GetError()); return 1;}

    SDL_Event event;
    Player player = {
        .rect = {
            .x = 300.0f,
            .y = 300.0f,
            .w = 32.0f,
            .h = 32.0f,
        },
        .hitbox = {
            .sh_x = 5.0f,
            .sh_y = 10.0f,
            .w = 22.0f,
            .h = 22.0f,
        },
        .old_x = 0,
        .old_y = 0,
        .vx = 0,
        .vy = 0,
        .inp_f = 0,
        .inp_f_max = 5.0f,
        .mov_ax = 0,
        .ay = 0.0f,
        .dmp = 8.0f,
    };
    
    Uint64 last_time = SDL_GetTicksNS();

    bool isrunning = true;
    while (isrunning) {

        Uint64 cur_time = SDL_GetTicksNS();
        float delta_time = (cur_time - last_time) / 1000000000.0f;
        last_time = cur_time;

        player.old_x = player.rect.x;
        player.old_y = player.rect.y;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isrunning = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
        }
        player.inp_f = 0;
        const bool* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_A])
            player.inp_f -= PLAYER_F;
        if (keystate[SDL_SCANCODE_D])
            player.inp_f += PLAYER_F;
        if (keystate[SDL_SCANCODE_SPACE])
            player.vy -= 1000.0f;

        float damping = player.dmp * delta_time;
        if (damping > 1.0f) damping = 1.0f;
        if (damping < 0.0f) damping = 0.0f;
        player.vx += (player.inp_f + player.mov_ax) * delta_time;
        player.vx *= (1.0f - damping);
        player.vy += player.ay * delta_time;

        player.rect.x += player.vx * delta_time;
        player.rect.y += player.vy * delta_time;
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_player(renderer, &player, true);
        render_entities(renderer, entities, entity_count, true);
        render_objects(renderer, objects, object_count, true);
        SDL_RenderPresent(renderer);
    }
    return 0;
}