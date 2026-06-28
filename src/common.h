#ifndef COMMON_H
#define COMMON_H

#include<SDL3/SDL.h>
#include"types.h"

void game_init(World *world);
void handle_input(Player *player, float player_f);
void upd_physics(Entity* entity, float inp_frc, Object *objects, int count, float dt);
void render_entities(SDL_Renderer *renderer, Entity *entities, int count, bool hitbox);
void render_objects(SDL_Renderer *renderer, Object *objects, int count, bool hitbox);

#endif