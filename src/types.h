#ifndef TYPES_H
#define TYPES_H

#include<SDL3/SDL.h>

typedef struct {
    float sh_x;
    float sh_y;
    float w, h;
} Hitbox;

typedef struct {
    SDL_FRect rect;
    Hitbox hitbox;
    SDL_Texture *texture;
} Object;

typedef struct {
    SDL_FRect rect;
    Hitbox hitbox;
    float vx, vy;
    float ax, ay;
    float dmp;
    bool isgnd;
} Entity;

typedef struct {
    Entity entity;
    float inp_frc;
    float inp_frc_max;
} Player;

#endif