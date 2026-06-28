#include<SDL3/SDL.h>
#include"types.h"

void handle_input(Player *player, float player_f)
{
        (*player).inp_frc = 0;
        const bool* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_A])
            (*player).inp_frc -= player_f;
        if (keystate[SDL_SCANCODE_D])
            (*player).inp_frc += player_f;
        if (keystate[SDL_SCANCODE_SPACE]) {
            if ((*player).entity.isgnd)
                (*player).entity.vy = -600.0f;
        }
}