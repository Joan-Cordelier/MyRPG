/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
*/

#include "my.h"
#include <string.h>


void move_rect(sfIntRect *rect, int offset, int max, int i)
{
    for (int n = 0; n <= i; n++) {
        rect->left += offset;
        if (rect->left >= max)
            rect->left = 0;
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
    sfRectangleShape_setPosition(plyr->colision,
        (sfVector2f){plyr->posx, plyr->posy});
    plyr->angle = sword_rotate(plyr, button_positions);
    rotate_png(plyr, button_positions, sword);
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
    sfRenderWindow_drawRectangleShape(window->window, plyr->colision, NULL);
}

static void draw_coll(hero_t *mob, window_t *window, map_t *map)
{
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, mob->spW, NULL);
    sfRenderWindow_drawSprite(window->window, mob->spHP, NULL);
    sfRenderWindow_drawRectangleShape(window->window, mob->colision, NULL);
    sfRenderWindow_drawRectangleShape(window->window, map->exit_player, 0);
    while (map->rectangle->prev != NULL)
        map->rectangle = map->rectangle->prev;
    for (; map->rectangle->next != NULL; map->rectangle = map->rectangle->next)
        if (map->rectangle->status == SHOOT)
            sfRenderWindow_drawRectangleShape(window->window,
                map->rectangle->rec, NULL);
}

static void set_and_draw(hero_t *mob, window_t *window,
    int set_draw, map_t *map)
{
    if (set_draw == SET) {
        sfSprite_setPosition(mob->sprite, (sfVector2f){mob->posx, mob->posy});
        sfSprite_setPosition(mob->spHP,
            (sfVector2f){mob->posx - 50, mob->posy - 190});
        sfSprite_setPosition(mob->spW,
            (sfVector2f){mob->posx, mob->posy + 10});
        sfRectangleShape_setPosition(mob->colision,
            (sfVector2f){mob->posx, mob->posy});
    }
    draw_coll(mob, window, map);
}

static void enemie(hero_t *mob, hero_t *plyr, window_t *window, map_t *map)
{
    if (plyr->posx > mob->posx)
        mob->posx = mob->posx + 7;
    if (plyr->posx < mob->posx)
        mob->posx = mob->posx - 7;
    if (plyr->posy > mob->posy)
        mob->posy = mob->posy + 7;
    if (plyr->posy < mob->posy)
        mob->posy = mob->posy - 7;
    move_anim(mob, 2);
    set_and_draw(mob, window, SET, map);
    colision(mob, plyr, map);
    mob->angle = sword_rotate(mob, (sfVector2i){plyr->posx, plyr->posy});
    rotate_mob(plyr, mob);
    set_and_draw(mob, window, DRAW, map);
}

static void set_mob_back_shoot(hero_t *mob, hero_t *plyr, map_t *map,
    sfSprite *shoot)
{
    sfSprite_setOrigin(map->map, (sfVector2f){0, 0});
    plyr->run = sfView_create();
    sfView_setSize(plyr->run, (sfVector2f){1750, 1000});
    sfSprite_setOrigin(mob->sprite, (sfVector2f){70, 70});
    sfSprite_setOrigin(shoot, (sfVector2f){32, 32});
    sfView_zoom(plyr->run, 1);
    plyr->posx = map->start_player.x;
    plyr->posy = map->start_player.y;
    mob->posx = map->start_player.x;
    mob->posy = map->start_player.y;
}

map_t *map_check(map_t *map, hero_t *plyr, hero_t *mob, sfSprite *shoot)
{
    init_map(map);
    while (map->prev != NULL)
        map = map->prev;
    set_mob_back_shoot(mob, plyr, map, shoot);
    return map;
}

void my_rpg(window_t *window, hero_t *plyr,
    sfSprite *sword, hero_t *mob)
{
    map_t *map = malloc(sizeof(map_t));
    sfSprite *shoot = fond("sprite/fire_ball.png", 1, 1);
    char *arms[] = {"epee-3.png", "shotgun-1.png", NULL};

    map = map_check(map, plyr, mob, shoot);
    while (sfRenderWindow_isOpen(window->window)) {
        sword = change_arms(sword, arms, &window->change);
        if (window->speed == 0)
            sfSprite_setPosition(shoot, (sfVector2f){plyr->posx, plyr->posy});
        moove_and_set(plyr, map);
        draw_sprite(window, plyr, sword, window->change);
        show_window(window, plyr, map->map, sword);
        enemie(mob, plyr, window, map);
        shoot = poll_event(map, window, plyr, shoot);
        if (window->speed == 0)
            sfSprite_setRotation(shoot, plyr->angle);
        sfRenderWindow_display(window->window);
    }
    destroy_sprites(mob->sprite, shoot, map->map);
}

void menu_prcp(window_t *window)
{
    hero_t *plyr = init_hero("sprite/hero_rpg/hero.png", 140, 140, PLAYER);
    sfSprite *sword = fond("sprite/arme/epee-4.png", 1, 1);
    hero_t *mob = init_hero("sprite/mob_boss/mob_sqlt.png", 150, 150,
        SQUELETON);

    sfSprite_setOrigin(plyr->sprite, (sfVector2f){70, 70});
    window->change = 0;
    window->speed = 0;
    my_rpg(window, plyr, sword, mob);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
