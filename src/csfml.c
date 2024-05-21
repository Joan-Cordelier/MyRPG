/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
*/

#include "my.h"
#include <string.h>


void move_rect(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 3; n++) {
        rect->left += offset;
        if (rect->left >= max)
            rect->left = 0;
    }
}

void move_rect2(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 3; n++) {
        rect->height += offset;
        if (rect->height >= max)
            rect->height = 0;
    }
}

static void move_anim2(hero_t *cible)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(cible->anim);
    if (clock_espl.microseconds > 300000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect2(&cible->rect, 150, 600);
        sfClock_restart(cible->anim);
    }
}

static void draw_sprite(window_t *window, hero_t *plyr,
    sfSprite *sword, int change)
{
    sfVector2i button_positions = mouse(window->window);

    sfView_setCenter(plyr->run, (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(plyr->sprite,
        (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(sword, (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(plyr->spHP,
        (sfVector2f){plyr->posx - 50, plyr->posy - 190});
    sfSprite_setPosition(plyr->spStam,
        (sfVector2f){plyr->posx - 50, plyr->posy - 180});
    sfSprite_setPosition(plyr->spMan,
        (sfVector2f){plyr->posx - 50, plyr->posy - 170});
    plyr->angle = sword_rotate(plyr, window, button_positions);
    rotate_png(plyr, window, button_positions, sword);
    if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0)
        plyr->angle = plyr->angle - 90.0;
    sfSprite_setRotation(sword, plyr->angle);
    sfRenderWindow_clear(window->window, sfBlack);
}

static void show_window(window_t *window, hero_t *plyr, sfSprite *back,
    sfSprite *sword)
{
    sfRenderWindow_setView(window->window, plyr->run);
    sfRenderWindow_drawSprite(window->window, back, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spHP, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spStam, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spMan, NULL);
    sfRenderWindow_drawSprite(window->window, sword, NULL);
}

static void enemie(hero_t *mob, hero_t *plyr, window_t *window)
{
    if (plyr->posx > mob->posx)
        mob->posx = mob->posx + 7;
    if (plyr->posx < mob->posx)
        mob->posx = mob->posx - 7;
    if (plyr->posy > mob->posy)
        mob->posy = mob->posy + 7;
    if (plyr->posy < mob->posy)
        mob->posy = mob->posy - 7;
    move_anim2(mob);
    sfSprite_setPosition(mob->sprite, (sfVector2f){mob->posx, mob->posy});
    sfSprite_setPosition(mob->spHP,
        (sfVector2f){mob->posx - 50, mob->posy - 190});
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, mob->spHP, NULL);
}

static void set_mob_back_shoot(hero_t *mob, hero_t *plyr, sfSprite *back,
    sfSprite *shoot)
{
    sfSprite_setOrigin(back, (sfVector2f){0, 0});
    plyr->run = sfView_create();
    sfView_setSize(plyr->run, (sfVector2f){1750, 1000});
    sfSprite_setOrigin(mob->sprite, (sfVector2f){70, 70});
    sfSprite_setOrigin(shoot, (sfVector2f){32, 32});
    sfView_zoom(plyr->run, 1);
}

void my_rpg(window_t *window, hero_t *plyr,
    sfSprite *sword, sfEvent event)
{
    hero_t *mob = hero("sprite/mob_boss/mob_sqlt.png", 150, 150);
    sfSprite *back = fond("sprite/map.jpg", 3, 3);
    sfSprite *shoot = fond("sprite/fire_ball.png", 1, 1);
    char *arms[] = {"epee-3.png", "shotgun-1.png", NULL};

    set_mob_back_shoot(mob, plyr, back, shoot);
    while (sfRenderWindow_isOpen(window->window)) {
        sword = change_arms(sword, arms, &window->change);
        if (window->speed == 0)
            sfSprite_setPosition(shoot, (sfVector2f){plyr->posx, plyr->posy});
        moove_and_set(plyr, event, window);
        draw_sprite(window, plyr, sword, window->change);
        show_window(window, plyr, back, sword);
        enemie(mob, plyr, window);
        shoot = poll_event(event, window, plyr, shoot);
        if (window->speed == 0)
            sfSprite_setRotation(shoot, plyr->angle);
        sfRenderWindow_display(window->window);
    }
    destroy_sprites(mob->sprite, shoot, back);
}

void menu_prcp(window_t *window, char *file, sfEvent event)
{
    hero_t *plyr = hero("sprite/hero_rpg/hero.png", 140, 140);
    sfSprite *sword = fond("sprite/arme/epee-4.png", 1, 1);

    sfSprite_setOrigin(plyr->sprite, (sfVector2f){70, 70});
    window->change = 0;
    window->speed = 0;
    my_rpg(window, plyr, sword, event);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
