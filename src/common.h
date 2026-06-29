#ifndef COMMON_H
#define COMMON_H

#include<SDL3/SDL.h>
#include"types.h"

#define LOGICAL_WIDTH 320
#define LOGICAL_HEIGHT 180
#define WINDOW_FLAGS (SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)

#define HITBOXES true

#define PLAYER_FRC 2500.0f
#define JUMP_V -300.0f

void game_init(SDL_Renderer *renderer, World *world);
void handle_input(Player *player);
void upd_physics(Entity* entity, float inp_frc, Object *objects, int count, float dt);
void render_entities(SDL_Renderer *renderer, Entity *entities, int count, bool hitbox);
void render_objects(SDL_Renderer *renderer, Object *objects, int count, bool hitbox);

#endif