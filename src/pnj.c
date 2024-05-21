/*
** EPITECH PROJECT, 2023
** png
** File description:
** png
*/

#include "my.h"
#include <math.h>

void rotate_png(hero_t *plyr, window_t *window,
    sfVector2i button_positions, sfSprite *sword)
{
    sfVector2f oriplyr = sfSprite_getPosition(plyr->sprite);
    //sfVector2i button_positions = mouse(window->window);

    if (button_positions.x > oriplyr.x) {
        sfSprite_setScale(plyr->sprite, (sfVector2f){-2, 2});
        sfSprite_setScale(sword, (sfVector2f){1, 1});
    } else {
        sfSprite_setScale(plyr->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(sword, (sfVector2f){-1, 1});
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

static void bar(hero_t *cible)
{
    sfVector2f scale = {2, 2};

    cible->texHP = sfTexture_createFromFile("sprite/hero_rpg/HP.png", NULL);
    cible->spHP = sfSprite_create();
    cible->texStam = sfTexture_createFromFile("sprite/hero_rpg/Stamina.png", NULL);
    cible->spStam = sfSprite_create();
    cible->texMan = sfTexture_createFromFile("sprite/hero_rpg/Mana.png", NULL);
    cible->spMan = sfSprite_create();
    cible->recHP.top = 0;
    cible->recHP.left = 0;
    cible->recHP.width = 100;
    cible->recHP.height = 100;
    cible->recStam.top = 0;
    cible->recStam.left = 0;
    cible->recStam.width = 100;
    cible->recStam.height = 100;
    cible->recMan.top = 0;
    cible->recMan.left = 0;
    cible->recMan.width = 100;
    cible->recMan.height = 100;
    sfSprite_setTexture(cible->spHP, cible->texHP, sfTrue);
    sfSprite_setTexture(cible->spStam, cible->texStam, sfTrue);
    sfSprite_setTexture(cible->spMan, cible->texMan, sfTrue);
    sfSprite_setTextureRect(cible->spHP, cible->recHP);
    sfSprite_setTextureRect(cible->spStam, cible->recStam);
    sfSprite_setTextureRect(cible->spMan, cible->recMan);
    sfSprite_setScale(cible->spHP, cible->scale);
    sfSprite_setScale(cible->spStam, cible->scale);
    sfSprite_setScale(cible->spMan, cible->scale);
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
    cible->endspe = sfClock_create();
    cible->anim = sfClock_create();
    init_player(cible);
    bar(cible);
    sfSprite_setTexture(cible->sprite, cible->texture, sfTrue);
    sfSprite_setTextureRect(cible->sprite, cible->rect);
    sfSprite_setScale(cible->sprite, cible->scale);
    sfSprite_setPosition(cible->sprite, cible->pos);
    return cible;
}
