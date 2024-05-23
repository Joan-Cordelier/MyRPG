/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** pnj.c
*/

#include "my.h"

void init_pnj_cave(map_t *map)
{
    map->pnj = malloc(sizeof(pnj_t));
    memset(map->pnj, 0, sizeof(pnj_t));
    map->pnj->pnj = sfSprite_create();
    map->pnj->pnj_texture = sfTexture_createFromFile("sprite/mob_boss/pnj.png",
        NULL);
    map->pnj->posx = map->start_player.x;
    map->pnj->posy = map->start_player.y;
    map->pnj->status = 0;
    sfSprite_setTexture(map->pnj->pnj, map->pnj->pnj_texture, sfTrue);
    sfSprite_setOrigin(map->pnj->pnj, (sfVector2f){0, 0});
    sfSprite_setPosition(map->pnj->pnj,
        (sfVector2f){map->pnj->posx, map->pnj->posy});
    sfSprite_setScale(map->pnj->pnj, (sfVector2f){2, 2});
}
