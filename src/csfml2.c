/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** csfml2.c
*/

#include "my.h"

void move_anim(hero_t *cible, int n)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(cible->anim);
    if (clock_espl.microseconds > 300000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect(&cible->rect, 140, 340, n);
        sfClock_restart(cible->anim);
    }
}

void destroy_sprites(sfSprite *mob, sfSprite *back)
{
    sfSprite_destroy(mob);
    sfSprite_destroy(back);
}

void moove_and_set(hero_t *plyr, map_t *map)
{
    /* sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(map->timeS);
    if (map->rep == 0) {
        map->rep++;
        sfSound_play(map->song);
    }
    if (clock_espl.microseconds > 66000000) {
        sfClock_restart(map->timeS);
        map->rep = 0;
    } */
    move_anim(plyr, 3);
    set_move(plyr, map);
}
