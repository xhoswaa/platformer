#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include"types.h"
#include"common.h"

void game_init(SDL_Renderer *renderer, World *world)
{
    (*world).player = (Player){
        .entity = {
            .rect = {
                .x = 0.0f,
                .y = 0.0f,
                .w = 32.0f,
                .h = 32.0f,
            },
            .hitbox = {
                .sh_x = 10.0f,
                .sh_y = 10.0f,
                .w = 12.0f,
                .h = 14.0f,
            },
            .texture = IMG_LoadTexture(renderer, "assets/entities/player/player_idle.png"),
            .vx = 0,
            .vy = 0,
            .ax = 0,
            .ay = 1500.0f,
            .dmp = 8.0f,
        },
        .inp_frc = 0,
        .inp_frc_max = 5.0f,
    };
    (*world).objects[(*world).object_count++] = (Object){
        .rect = {
            .x = 0,
            .y = 160,
            .w = 320,
            .h = 20,
        },
        .hitbox = {
            .sh_x = 0,
            .sh_y = 0,
            .w = 800,
            .h = 100,
        },
    };
}