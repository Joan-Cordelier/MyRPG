/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** moove_mobs.c
*/

#include "my.h"

void moove_squeleton(hero_t *plyr, hero_t *mob, map_t *map)
{
    if ((plyr->posx - mob->posx >= -240 && plyr->posx - mob->posx <= 240)
    || (plyr->posy - mob->posy >= -160 && plyr->posy - mob->posy <= 160)) {
        if (plyr->posx > mob->posx && is_touching(mob->posx + 7, mob->posy,
            map->txt_map) == 0)
            mob->posx = mob->posx + 7;
        if (plyr->posx < mob->posx && is_touching(mob->posx - 7, mob->posy,
            map->txt_map) == 0)
            mob->posx = mob->posx - 7;
        if (plyr->posy > mob->posy && is_touching(mob->posx, mob->posy + 7,
            map->txt_map) == 0)
            mob->posy = mob->posy + 7;
        if (plyr->posy < mob->posy && is_touching(mob->posx, mob->posy - 7,
            map->txt_map) == 0)
            mob->posy = mob->posy - 7;
    }
}
