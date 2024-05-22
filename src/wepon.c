/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** wepon.c
*/

#include "my.h"

void init_weapon(hero_t *hero)
{
    hero->spW = sfSprite_create();
    hero->texW = sfTexture_createFromFile("sprite/arme/mob_sqlt-1.png", NULL);
    sfSprite_setTexture(hero->spW, hero->texW, sfTrue);
    sfSprite_setScale(hero->spW, (sfVector2f){2, 2});
    sfSprite_setOrigin(hero->spW, (sfVector2f){100, 120});
    if (hero->status == PNJ)
        return;
}
