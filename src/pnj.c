/*
** EPITECH PROJECT, 2023
** png
** File description:
** png
*/

#include "my.h"

static sfVector2i mouse(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f final;

    final = sfRenderWindow_mapPixelToCoords(window, mouse_pos,
        sfRenderWindow_getView(window));
    return (sfVector2i){final.x, final.y};
}

void rotate_png(hero_t *plyr, window_t *window)
{
    sfVector2f scale1 = {-2, 2};
    sfVector2f scale2 = {2, 2};
    sfVector2i button_positions = mouse(window->window);

    if (button_positions.x > 940)
        sfSprite_setScale(plyr->sprite, scale1);
    else
        sfSprite_setScale(plyr->sprite, scale2);
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
