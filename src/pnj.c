/*
** EPITECH PROJECT, 2023
** png
** File description:
** png
*/

#include "my.h"
#include <math.h>

void rotate_png(hero_t *plyr, window_t *window, sfVector2i button_positions)
{
    sfVector2f scale1 = {-2, 2};
    sfVector2f scale2 = {2, 2};
    sfVector2f oriplyr = sfSprite_getPosition(plyr->sprite);

    if (button_positions.x > oriplyr.x) {
        sfSprite_setScale(plyr->sprite, scale1);
    } else {
        sfSprite_setScale(plyr->sprite, scale2);
        plyr->angle = plyr->angle * -1;
    }
}

float sword_rotate(hero_t *plyr, window_t *window, sfVector2i button_positions)
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

hero_t *hero(char *file, int x, int y)
{
    hero_t *cible = malloc(sizeof(hero_t));
    sfVector2f scale = {2, 2};
    sfVector2f pos = {960, 540};

    srand(time(NULL));
    cible->texture = sfTexture_createFromFile(file, NULL);
    cible->sprite = sfSprite_create();
    cible->scale = scale;
    cible->pos = pos;
    cible->rect.top = 0;
    cible->rect.left = 0;
    cible->rect.width = x;
    cible->rect.height = y;
    cible->posx = 65;
    cible->posy = 50;
    sfSprite_setTexture(cible->sprite, cible->texture, sfTrue);
    sfSprite_setScale(cible->sprite, cible->scale);
    sfSprite_setPosition(cible->sprite, cible->pos);
    return cible;
}
