/*
** EPITECH PROJECT, 2024
** death
** File description:
** death
*/

#include "my.h"

void dead(hero_t *hero)
{
    hero->player->end = 100;
    hero->player->life = 100;
    hero->player->mana = 100;
    hero->player->nb_fiol = 4;
    hero->posx = 0;
    hero->posy = 0;
}