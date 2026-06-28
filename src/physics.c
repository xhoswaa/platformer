#include<SDL3/SDL.h>
#include"types.h"

void upd_physics(Entity* entity, float inp_frc, Object *objects, int count, float dt)
{   
    float damping = (*entity).dmp * dt;
    if (damping > 1.0f) damping = 1.0f;
    if (damping < 0.0f) damping = 0.0f;

    (*entity).vx += (inp_frc + (*entity).ax) * dt;
    (*entity).vx *= (1.0f - damping);
    (*entity).vy += (*entity).ay * dt;

    float old_x = (*entity).rect.x;
    (*entity).rect.x += (*entity).vx * dt;  
    for (int i = 0; i < count; i++) {
        SDL_FRect hitbox_rect = {
            .x = (*entity).hitbox.sh_x + (*entity).rect.x,
            .y = (*entity).hitbox.sh_y + (*entity).rect.y,
            .w = (*entity).hitbox.w,
            .h = (*entity).hitbox.h,
        };
        if (SDL_HasRectIntersectionFloat(&hitbox_rect, &objects[i].rect)) {
            (*entity).rect.x = old_x;
            (*entity).vx = 0.0f;
        }
    }

    float old_y = (*entity).rect.y;
    (*entity).rect.y += (*entity).vy * dt;
    for (int i = 0; i < count; i++) {
        SDL_FRect hitbox_rect = {
            .x = (*entity).hitbox.sh_x + (*entity).rect.x,
            .y = (*entity).hitbox.sh_y + (*entity).rect.y,
            .w = (*entity).hitbox.w,
            .h = (*entity).hitbox.h,
        };
        if (SDL_HasRectIntersectionFloat(&hitbox_rect, &objects[i].rect)) {
            (*entity).rect.y = old_y;
            (*entity).vy = 0.0f;
            (*entity).isgnd = true;
        }
        else (*entity).isgnd = false;
    }
}