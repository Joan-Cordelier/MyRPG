/*
** EPITECH PROJECT, 2024
** death
** File description:
** death
*/

#include "my.h"

void dead(hero_t *hero, map_t *map)
{
    hero->player->end = 100;
    hero->player->life = 100;
    hero->player->mana = 100;
    hero->player->nb_fiol = 4;
    hero->posx = map->start_player.x;
    hero->posy = map->start_player.y;
    hero->recHP.width = 100;
    sfSprite_setTextureRect(hero->spHP, hero->recHP);
    hero->recMan.width = 100;
    sfSprite_setTextureRect(hero->spMan, hero->recMan);
    hero->recStam.width = 100;
    sfSprite_setTextureRect(hero->spStam, hero->recStam);
}
