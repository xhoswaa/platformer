#ifndef COMMON_H
#define COMMON_H

#include<SDL3/SDL.h>
#include"types.h"

void render_player(SDL_Renderer *renderer, Player *player, bool hitbox);
void render_entities(SDL_Renderer *renderer, Entity *entities, int count, bool hitbox);
void render_objects(SDL_Renderer *renderer, Object *objects, int count, bool hitbox);

#endif