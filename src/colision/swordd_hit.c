/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** swordd_hit.c
*/

#include "my.h"

static void aply_change_hit(hero_t *mob, map_t *map)
{
}

void sword_hit(hero_t *plyr, hero_t *mob, map_t *map, int change)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0) {
        if (colisioin_box_mob(plyr->weapon->colision_w, mob) == 1)
            aply_change_hit(mob, map);
        plyr->angle = plyr->angle - 90.0;
    }
    sfSprite_setRotation(plyr->weapon->weapon, plyr->angle);
    sfRectangleShape_setRotation(plyr->weapon->colision_w, plyr->angle);
}
