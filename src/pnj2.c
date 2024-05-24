/*
** EPITECH PROJECT, 2023
** png
** File description:
** png
*/

#include "my.h"
#include <math.h>

void hero_xp(hero_t *hero)
{
    hero->clockXP = sfClock_create();
    hero->songXP2 = sfSoundBuffer_createFromFile("sprite/song/Bwowowowow.ogg");
    hero->songXP = sfSound_create();
    hero->texXP = sfTexture_createFromFile("sprite/hero_rpg/XP.png", NULL);
    hero->spXP = sfSprite_create();
    sfSprite_setTexture(hero->spXP, hero->texXP, sfTrue);
    hero->recXP.top = 0;
    hero->recXP.left = 0;
    hero->recXP.width = 0;
    hero->recXP.height = 100;
    hero->XP = 1;
    sfSprite_setScale(hero->spXP, hero->scale);
    sfSprite_setTextureRect(hero->spXP, hero->recXP);
    sfSound_setBuffer(hero->songXP, hero->songXP2);
}
