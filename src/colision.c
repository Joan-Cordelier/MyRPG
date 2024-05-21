/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** colision.c
*/

#include "my.h"

void colision(hero_t *mob, hero_t *plyr)
{
    sfFloatRect rect_mob = sfRectangleShape_getGlobalBounds(mob->colision);
    sfFloatRect rect_ply = sfRectangleShape_getGlobalBounds(plyr->colision);

    if (sfFloatRect_intersects(&rect_mob, &rect_ply, NULL) == sfTrue) {
        sfRectangleShape_setOutlineColor(plyr->colision, sfRed);
        sfRectangleShape_setOutlineColor(mob->colision, sfRed);
        plyr->player->life = plyr->player->life - DEGAT_MOB;
        if (plyr->player->life <= 0)
            dead(plyr);
    } else {
        sfRectangleShape_setOutlineColor(plyr->colision, sfGreen);
        sfRectangleShape_setOutlineColor(mob->colision, sfGreen);
    }
}
