/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** sword_rotate.c
*/

#include "my.h"

void rotate_png(hero_t *plyr, sfVector2i button_positions)
{
    sfVector2f oriplyr = sfSprite_getPosition(plyr->sprite);

    if (button_positions.x > oriplyr.x) {
        sfSprite_setScale(plyr->sprite, (sfVector2f){-2, 2});
        sfSprite_setScale(plyr->weapon->weapon, (sfVector2f){1, 1});
        sfRectangleShape_setScale(plyr->weapon->colision_w,
            (sfVector2f){1, 1});
    } else {
        sfSprite_setScale(plyr->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(plyr->weapon->weapon, (sfVector2f){-1, 1});
        sfRectangleShape_setScale(plyr->weapon->colision_w,
            (sfVector2f){-1, 1});
        plyr->angle = plyr->angle * -1;
    }
}

void rotate_mob(hero_t *plyr, hero_t *mob)
{
    sfVector2f oriplyr = sfSprite_getPosition(mob->sprite);

    if (plyr->posx < oriplyr.x) {
        sfSprite_setScale(mob->sprite, (sfVector2f){-2, 2});
        sfSprite_setScale(mob->weapon->weapon, (sfVector2f){-2, 2});
        sfRectangleShape_setScale(mob->weapon->colision_w,
            (sfVector2f){-1, 1});
        mob->angle = mob->angle * -1;
    } else {
        sfSprite_setScale(mob->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(mob->weapon->weapon, (sfVector2f){2, 2});
        sfRectangleShape_setScale(mob->weapon->colision_w, (sfVector2f){1, 1});
    }
    sfSprite_setRotation(mob->weapon->weapon, mob->angle);
    sfRectangleShape_setRotation(mob->weapon->colision_w, mob->angle);
}

float sword_rotate(hero_t *plyr, sfVector2i button_positions)
{
    float a1 = 0.0;
    float a2 = 0.0;
    float b1 = 0.0;
    float b2 = 0.0;
    float cosinus = 0.0;
    float t = 0.0;
    float pi = 3.14159265359;

    a1 = button_positions.x - plyr->posx;
    a2 = button_positions.y - plyr->posy;
    b1 = plyr->posx - plyr->posx;
    b2 = (plyr->posy * -2) - plyr->posy;
    if ((sqrtf((a1 * a1) + (a2 * a2)) == 0.0) ||
        (sqrtf((b1 * b1) + (b2 * b2)) == 0.0))
        return (0.0);
    cosinus = (a1 * b1 + a2 * b2) / (sqrtf((a1 * a1) + (a2 * a2))
        * sqrtf((b1 * b1) + (b2 * b2)));
    t = acosf(cosinus);
    t = t * 180.0 / pi;
    return t;
}
