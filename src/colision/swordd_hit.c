/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** swordd_hit.c
*/

#include "my.h"

void aply_change_hit(hero_t *mob, map_t *map, weapon_t *weapon)
{
    mob->player->life = mob->player->life - weapon->damage;
    if (mob->player->life <= 0 && mob->status == PLAYER)
        dead_hero(mob, map);
    if (mob->player->life <= 0 && mob->status == SQUELETON)
        dead_mob(mob, map);
    mob->recHP.width = mob->recHP.width - weapon->damage;
    sfSprite_setTextureRect(mob->spHP, mob->recHP);
}

void sword_hit(hero_t *plyr, hero_t *mob, map_t *map, int change)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(plyr->spatt);
    if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0) {
        if (colisioin_box_mob(plyr->weapon->colision_w, mob) == 1
            && clock_espl.microseconds > 200000) {
            aply_change_hit(mob, map, plyr->weapon);
            sfClock_restart(plyr->spatt);
        }
        plyr->angle = plyr->angle - 90.0;
    }
    sfSprite_setRotation(plyr->weapon->weapon, plyr->angle);
    sfRectangleShape_setRotation(plyr->weapon->colision_w, plyr->angle);
}
