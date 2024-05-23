/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** colision_box.c
*/

#include "my.h"

int colisioin_box_mob(sfRectangleShape *box, hero_t *mob)
{
    sfFloatRect rect_mob = sfRectangleShape_getGlobalBounds(mob->colision);
    sfFloatRect rect_ply = sfRectangleShape_getGlobalBounds(box);

    if (sfFloatRect_intersects(&rect_mob, &rect_ply, NULL) == sfTrue) {
        sfRectangleShape_setOutlineColor(box, sfRed);
        sfRectangleShape_setOutlineColor(mob->colision, sfRed);
        return 1;
    } else {
        sfRectangleShape_setOutlineColor(box, sfGreen);
        sfRectangleShape_setOutlineColor(mob->colision, sfGreen);
        return 0;
    }
}
