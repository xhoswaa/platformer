#include<SDL3/SDL.h>
#include"types.h"
#include"common.h"

void handle_input(Player *player)
{
        (*player).inp_frc = 0;
        const bool* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_A])
            (*player).inp_frc -= PLAYER_FRC;
        if (keystate[SDL_SCANCODE_D])
            (*player).inp_frc += PLAYER_FRC;
        if (keystate[SDL_SCANCODE_SPACE]) {
            if ((*player).entity.isgnd)
                (*player).entity.vy = JUMP_V;
        }
}