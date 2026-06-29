#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include"types.h"
#include"common.h"

void render_entities(SDL_Renderer *renderer, Entity *entities, int count, bool hitbox)
{
    for (int i = 0; i < count; i++) {
        if (entities[i].texture) { 
            SDL_RenderTexture(renderer, entities[i].texture, NULL, &entities[i].rect);
            SDL_SetTextureScaleMode(entities[i].texture, SDL_SCALEMODE_NEAREST);
        }
        else SDL_RenderFillRect(renderer, &entities[i].rect);
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
        if (objects[i].texture) { 
            SDL_RenderTexture(renderer, objects[i].texture, NULL, &objects[i].rect);
            SDL_SetTextureScaleMode(objects[i].texture, SDL_SCALEMODE_NEAREST);
        }
        else SDL_RenderFillRect(renderer, &objects[i].rect);
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