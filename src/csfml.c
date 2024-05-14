/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
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
    for (int n = 0; n <= 3; n++) {
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
        move_rect(&cible->rect, 140, 340);
        sfClock_restart(clock);
    }
}

static void draw_sprite(window_t *window, hero_t *plyr, sfSprite *back,
    sfSprite *sword)
{
    sfVector2i button_positions = mouse(window->window);

    sfView_setCenter(plyr->run, (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(plyr->sprite,
        (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(sword, (sfVector2f){plyr->posx, plyr->posy});
    plyr->angle = sword_rotate(plyr, window, button_positions);
    rotate_png(plyr, window, button_positions, sword);
    sfSprite_setRotation(sword, plyr->angle);
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
    plyr->run = sfView_create();
    sfView_setSize(plyr->run, (sfVector2f){1750, 1000});
    sfView_zoom(plyr->run, 1);
    while (sfRenderWindow_isOpen(window->window)) {
        move_anim(anim, plyr);
        set_move(back, window, plyr);
        poll_event(event, window);
        draw_sprite(window, plyr, back, sword);
        sfRenderWindow_setView(window->window, plyr->run);
        sfRenderWindow_display(window->window);
    }
    sfSprite_destroy(back);
    sfClock_destroy(anim);
}

void menu_prcp(window_t *window, char *file, sfEvent event)
{
    hero_t *plyr = hero("sprite/hero_rpg/hero.png", 150, 150);
    sfSprite *sword = fond("sprite/arme/shotgun-1.png", 1, 1);
    sfVector2f sword_pos = {960, 600};

    sfSprite_setPosition(sword, (sfVector2f){900, 500});
    sfSprite_setPosition(plyr->sprite, sword_pos);
    sfSprite_setOrigin(plyr->sprite, (sfVector2f){70, 70});
    sfSprite_setOrigin(sword, (sfVector2f){100, 150});
    my_rpg(window, plyr, sword, event);
    sfSprite_destroy(sword);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
