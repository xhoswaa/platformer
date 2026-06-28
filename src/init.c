#include<SDL3/SDL.h>
#include"types.h"

void game_init(World *world)
{
    (*world).player = (Player){
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
    (*world).objects[(*world).object_count++] = (Object){
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
}