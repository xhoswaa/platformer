#include<SDL3/SDL.h>
#include"types.h"

// void render_player(SDL_Renderer *renderer, Player *player, bool hitbox)
// {
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(renderer, &(*player).entity.rect);
//     if (hitbox) {    
//         SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//         SDL_FRect hitbox_rect = {
//             .x = (*player).hitbox.sh_x + (*player).rect.x,
//             .y = (*player).hitbox.sh_y + (*player).rect.y,
//             .w = (*player).hitbox.w,
//             .h = (*player).hitbox.h,
//         };
//         SDL_RenderRect(renderer, &hitbox_rect);
//     }
// }

void render_entities(SDL_Renderer *renderer, Entity *entities, int count, bool hitbox)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < count; i++) {
        SDL_RenderFillRect(renderer, &entities[i].rect);
    }
    if (hitbox) {    
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (int i = 0; i < count; i++) {
            SDL_FRect hitbox_rect = {
                .x = entities[i].hitbox.sh_x + entities[i].rect.x,
                .y = entities[i].hitbox.sh_y + entities[i].rect.y,
                .w = entities[i].hitbox.w,
                .h = entities[i].hitbox.h,
            };
            SDL_RenderRect(renderer, &hitbox_rect);
        }
    }
}

void render_objects(SDL_Renderer *renderer, Object *objects, int count, bool hitbox)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < count; i++) {
        SDL_RenderFillRect(renderer, &objects[i].rect);
    }
    if (hitbox) {    
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (int i = 0; i < count; i++) {
            SDL_FRect hitbox_rect = {
                .x = objects[i].hitbox.sh_x + objects[i].rect.x,
                .y = objects[i].hitbox.sh_y + objects[i].rect.y,
                .w = objects[i].hitbox.w,
                .h = objects[i].hitbox.h,
            };
            SDL_RenderRect(renderer, &hitbox_rect);
        }
    }
}