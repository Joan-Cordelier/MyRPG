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

static void draw_sprite(window_t *window, hero_t *plyr, map_t *map,
    hero_t *mob)
{
    sfVector2i button_positions = mouse(window->window);
    sfVector2f pos = {plyr->posx, plyr->posy};

    sfView_setCenter(plyr->run, (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(plyr->sprite, pos);
    sfSprite_setPosition(plyr->weapon->weapon, pos);
    sfSprite_setPosition(plyr->spHP,
        (sfVector2f){plyr->posx - 50, plyr->posy - 190});
    sfSprite_setPosition(plyr->spStam,
        (sfVector2f){plyr->posx - 50, plyr->posy - 180});
    sfSprite_setPosition(plyr->spMan,
        (sfVector2f){plyr->posx - 50, plyr->posy - 170});
    sfRectangleShape_setPosition(plyr->colision, pos);
    sfRectangleShape_setPosition(plyr->weapon->colision_w, pos);
    plyr->angle = sword_rotate(plyr, button_positions);
    rotate_png(plyr, button_positions);
    sword_hit(plyr, mob, map, window->change);
    sfRenderWindow_clear(window->window, sfBlack);
}

static void show_window(window_t *window, hero_t *plyr, sfSprite *back)
{
    sfRenderWindow_setView(window->window, plyr->run);
    sfRenderWindow_drawSprite(window->window, back, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spHP, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spStam, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->spMan, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->weapon->weapon, NULL);
    sfRenderWindow_drawRectangleShape(window->window, plyr->colision, NULL);
    sfRenderWindow_drawRectangleShape(window->window,
        plyr->weapon->colision_w, NULL);
}

static void draw_ennemie(hero_t *mob, window_t *window, map_t *map)
{
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, mob->weapon->weapon, NULL);
    sfRenderWindow_drawSprite(window->window, mob->spHP, NULL);
    sfRenderWindow_drawRectangleShape(window->window, mob->colision, NULL);
    sfRenderWindow_drawRectangleShape(window->window,
        mob->weapon->colision_w, NULL);
    if (map->is_next)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_next, NULL);
    if (map->is_prev)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_prev, NULL);
    sfRenderWindow_drawSprite(window->window, map->pnj->pnj, NULL);
}

static void set_ennemie(hero_t *mob, window_t *window, map_t *map)
{
    sfSprite_setPosition(mob->sprite, (sfVector2f){mob->posx, mob->posy});
    sfSprite_setPosition(mob->spHP,
        (sfVector2f){mob->posx - 50, mob->posy - 190});
    sfSprite_setOrigin(mob->weapon->weapon, (sfVector2f){100, 120});
    sfSprite_setPosition(mob->weapon->weapon,
        (sfVector2f){mob->posx, mob->posy + 10});
    sfRectangleShape_setPosition(mob->colision,
        (sfVector2f){mob->posx, mob->posy});
    sfRectangleShape_setPosition(mob->weapon->colision_w,
        (sfVector2f){mob->posx, mob->posy});
}

static void enemie(hero_t *mob, hero_t *plyr, window_t *window, map_t *map)
{
    moove_squeleton(plyr, mob, map);
    move_anim(mob, 2);
    set_ennemie(mob, window, map);
    colision(mob, plyr, map);
    mob->angle = sword_rotate(mob, (sfVector2i){plyr->posx, plyr->posy});
    rotate_mob(plyr, mob);
    sword_hit_mob(mob, plyr, map, window->change);
    draw_ennemie(mob, window, map);
}

void set_mob_back_shoot(hero_t *mob, hero_t *plyr, map_t *map)
{
    sfSprite_setOrigin(map->map, (sfVector2f){0, 0});
    plyr->run = sfView_create();
    sfView_setSize(plyr->run, (sfVector2f){1750, 1000});
    sfSprite_setOrigin(mob->sprite, (sfVector2f){70, 70});
    sfView_zoom(plyr->run, 1);
    plyr->posx = map->start_player.x;
    plyr->posy = map->start_player.y;
    mob->posx = map->start_mob.x;
    mob->posy = map->start_mob.y;
}

static map_t *map_check(map_t *map, hero_t *plyr, hero_t *mob)
{
    init_map(map);
    map = map->prev;
    set_mob_back_shoot(mob, plyr, map);
    map->timeS = sfClock_create();
    map->song = sfSound_create();
    map->song2 = sfSoundBuffer_createFromFile("sprite/song/AtDoomsGate.ogg");
    map->rep = 0;
    sfSound_setBuffer(map->song, map->song2);
    return map;
}
void my_rpg(window_t *window, hero_t *plyr, hero_t *mob)
{
    map_t *map = malloc(sizeof(map_t));

    map = map_check(map, plyr, mob);
    while (sfRenderWindow_isOpen(window->window)) {
        moove_and_set(plyr, map);
        map = map_colision(window, plyr, map, mob);
        draw_sprite(window, plyr, map, mob);
        show_window(window, plyr, map->map);
        enemie(mob, plyr, window, map);
        poll_event(map, window, plyr, mob);
        check_status(map->pnj, plyr, window);
        sfRenderWindow_display(window->window);
    }
    destroy_sprites(mob->sprite, map->map);
}

void menu_prcp(window_t *window)
{
    hero_t *plyr = init_hero("sprite/hero_rpg/hero.png", 140, 140, PLAYER);
    hero_t *mob = init_hero("sprite/mob_boss/mob_sqlt.png", 150, 150,
        SQUELETON);

    sfSprite_setOrigin(plyr->sprite, (sfVector2f){70, 70});
    window->change = 0;
    window->speed = 0;
    while (plyr->weapon->next != NULL)
        plyr->weapon = plyr->weapon->next;
    while (mob->weapon->next != NULL)
        mob->weapon = mob->weapon->next;
    my_rpg(window, plyr, mob);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
