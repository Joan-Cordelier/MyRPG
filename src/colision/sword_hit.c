/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** swordd_hit.c
*/

#include "my.h"

void level_up(hero_t *plyr)
{
    sfTime clock_espl;

    if (plyr->recXP.width >= 100)
        sfSound_play(plyr->songXP);
    clock_espl = sfClock_getElapsedTime(plyr->clockXP);
    if (plyr->recXP.width >= 100 && clock_espl.microseconds > 2000000) {
        plyr->recXP.width = 0;
        plyr->XP = plyr->XP + 1;
        sfSprite_setTextureRect(plyr->spXP, plyr->recXP);
        sfClock_restart(plyr->clockXP);
        plyr->weapon->damage = plyr->weapon->damage * LEVEL_UP;
        return;
    }
}

void aply_change_hit(hero_t *plyr, hero_t *mob, map_t *map, weapon_t *weapon)
{
    mob->player->life = mob->player->life - weapon->damage + (
        plyr->XP * plyr->XP);
    if (mob->player->life <= 0 && mob->status == PLAYER)
        dead_hero(mob, map);
    if (mob->player->life <= 0 && mob->status == SQUELETON) {
        dead_mob(mob, map);
        plyr->recXP.width = plyr->recXP.width + 50 / plyr->XP;
        sfSprite_setTextureRect(plyr->spXP, plyr->recXP);
        sfClock_restart(plyr->clockXP);
    }
    mob->recHP.width = mob->recHP.width - weapon->damage + (
        plyr->XP * plyr->XP);
    sfSprite_setTextureRect(mob->spHP, mob->recHP);
}

void sword_hit(hero_t *plyr, hero_t *mob, map_t *map, int change)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(plyr->spatt);
    if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0) {
        if (colisioin_box_mob(plyr->weapon->colision_w, mob) == 1
            && clock_espl.microseconds > 500000) {
            aply_change_hit(plyr, mob, map, plyr->weapon);
            sfClock_restart(plyr->spatt);
        }
        plyr->angle = plyr->angle - 90.0;
        sfSound_play(plyr->songS);
    }
    sfSprite_setRotation(plyr->weapon->weapon, plyr->angle);
    sfRectangleShape_setRotation(plyr->weapon->colision_w, plyr->angle);
}

void sword_hit_mob(hero_t *plyr, hero_t *mob, map_t *map, int change)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(plyr->spatt);
    if (colisioin_box_mob(plyr->weapon->colision_w, mob) == 1
        && clock_espl.microseconds > 1000000) {
        aply_change_hit(plyr, mob, map, plyr->weapon);
        sfClock_restart(plyr->spatt);
    }
    plyr->angle = plyr->angle - 90.0;
    sfSound_play(plyr->songS);
    sfSprite_setRotation(plyr->weapon->weapon, plyr->angle);
    sfRectangleShape_setRotation(plyr->weapon->colision_w, plyr->angle);
    plyr->angle = sword_rotate(plyr, (sfVector2i){mob->posx, mob->posy});
    rotate_mob(mob, plyr);
}
