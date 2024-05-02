/*
** EPITECH PROJECT, 2024
** main
** File description:
** player
*/

#include "my.h"

int check_spe(int *x, int *y, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y - speed / 4;
        *x = *x + speed / 4;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y + speed / 4;
        *x = *x + speed / 4;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        *y = *y + speed / 4;
        *x = *x - speed / 4;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ)) {
        *y = *y - speed / 4;
        *x = *x - speed / 4;
        return 1;
    }
    return 0;
}

int move_player(int *x, int *y, sfEvent event, int speed)
{
    check_spe(x, y, speed);
    if (sfKeyQ == event.key.code) {
        *x = *x - speed;
        return 1;
    }
    if (sfKeyD == event.key.code) {
        *x = *x + speed;
        return 1;
    }
    if (sfKeyZ == event.key.code) {
        *y = *y - speed;
        return 1;
    }
    if (sfKeyS == event.key.code) {
        *y = *y + speed;
        return 1;
    }
    return 0;
}
