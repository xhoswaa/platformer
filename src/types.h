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
    float old_x;
    float old_y;
    float vx;           // velocity X
    float vy;           // velocity Y
    float inp_f;        // input force
    float inp_f_max;    // max input force
    float mov_ax;       // move acceleration X
    float ay;           // acceleration Y
    float dmp;          // damping
} Player;

typedef struct {
    SDL_FRect rect;
    Hitbox hitbox;
    float old_x;
    float old_y;
    float vx;
    float vy;
    float inp_f;
    float inp_f_max;
    float mov_ax;
    float ay;
    float dmp;
} Entity;

typedef struct {
    SDL_FRect rect;
    Hitbox hitbox;
    SDL_Texture *texture;
    int type;
} Object;

#endif