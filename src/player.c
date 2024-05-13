/*
** EPITECH PROJECT, 2024
** main
** File description:
** player
*/

#include "my.h"

void check_spe(int *x, int *y, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y - speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y + speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        *y = *y + speed * 0.5;
        *x = *x - speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ)) {
        *y = *y - speed * 0.5;
        *x = *x - speed * 0.5;
    }
}

int move_player(int *x, int *y, int speed)
{
    check_spe(x, y, speed);
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        *x = *x - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        *x = *x + speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        *y = *y - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        *y = *y + speed;
        return 1;
    }
    return 0;
}

int set_move(sfSprite *back, window_t *window, hero_t *plyr)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        move_player(&plyr->posx, &plyr->posy, 30);
    } else
        move_player(&plyr->posx, &plyr->posy, 10);
    return 0;
}
