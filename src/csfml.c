/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
*/

#include "my.h"

static sfSprite *fond(char *file, float x, float y)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void move_rect(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 2; n++) {
        rect->left += offset;
        if (rect->left >= max)
            rect->left = 0;
    }
}

static void move_anim(sfClock *clock, hero_t *cible)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(clock);
    if (clock_espl.microseconds > 300000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect(&cible->rect, 140, 280);
        sfClock_restart(clock);
    }
}

static void draw_sprite(window_t *window, hero_t *plyr, sfSprite *back,
    sfSprite *sword)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, back, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, sword, NULL);
}

void my_rpg(window_t *window, hero_t *plyr,
    sfSprite *sword, sfEvent event)
{
    sfClock *anim = sfClock_create();
    sfSprite *back = fond("sprite/map.jpg", 3, 3);

    sfSprite_setOrigin(back, (sfVector2f){75, 50});
    while (sfRenderWindow_isOpen(window->window)) {
        move_anim(anim, plyr);
        if (set_move(event, back, window, plyr) == -1)
            break;
        sfSprite_rotate(sword, 1);
        rotate_png(plyr, window);
        sfRenderWindow_pollEvent(window->window, &event);
        draw_sprite(window, plyr, back, sword);
        sfRenderWindow_display(window->window);
    }
    sfClock_destroy(anim);
    sfSprite_destroy(back);
}

void menu_prcp(window_t *window, char *file, sfEvent event)
{
    hero_t *plyr = hero("sprite/hero_rpg/hero.png", 150, 150);
    sfSprite *sword = fond("sprite/arme/epee-4.png", 1, 1);
    sfVector2f sword_pos = {960, 480};

    sfSprite_setOrigin(plyr->sprite, (sfVector2f){65, 50});
    sfSprite_setPosition(sword, sword_pos);
    sfSprite_setOrigin(sword, (sfVector2f){65, 50});
    my_rpg(window, plyr, sword, event);
    sfSprite_destroy(sword);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
