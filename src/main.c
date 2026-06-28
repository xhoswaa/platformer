#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<stdint.h>
#include"types.h"
#include"common.h"

#define PLAYER_FRC 2500.0f
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
        .entity = {
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
            .vx = 0,
            .vy = 0,
            .ax = 0,
            .ay = 1500.0f,
            .dmp = 8.0f,
        },
        .inp_frc = 0,
        .inp_frc_max = 5.0f,
    };
    objects[object_count++] = (Object){
        .rect = {
            .x = 0,
            .y = 500,
            .w = 800,
            .h = 100,
        },
        .hitbox = {
            .sh_x = 0,
            .sh_y = 0,
            .w = 800,
            .h = 100,
        },
    };
    
    Uint64 last_time = SDL_GetTicksNS();

    bool isrunning = true;
    while (isrunning) {

        Uint64 cur_time = SDL_GetTicksNS();
        float delta_time = (cur_time - last_time) / 1000000000.0f;
        last_time = cur_time;

        // player.old_x = player.rect.x;
        // player.old_y = player.rect.y;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isrunning = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
        }
        handle_input(&player, PLAYER_FRC);

        upd_physics((Entity*)&player, player.inp_frc, objects, object_count, delta_time);
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_entities(renderer, (Entity*)&player, 1, true);
        render_entities(renderer, entities, entity_count, true);
        render_objects(renderer, objects, object_count, true);
        SDL_RenderPresent(renderer);
    }
    return 0;
}