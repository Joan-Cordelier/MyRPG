/*
** EPITECH PROJECT, 2024
** main
** File description:
** player
*/

#include "my.h"

int move_player(int *x, int *y, sfEvent event, int speed)
{
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
