/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** colision.c
*/

#include "my.h"

int is_touching(int x, int y, int **txt_map)
{
    int posx = x / 160;
    int posy = y / 160;

    if (posy >= 34 || posx >= 60) {
        printf("Error to big\n");
        return 1;
    }
    if (posx < 0 || posy < 0) {
        printf("ERROR: to small\n");
        return 1;
    }
    if (txt_map[posy][posx] != 1) {
        return 1;
    }
    return 0;
}

int is_touching_border(int x, int y)
{
    int posx = x / 160;
    int posy = y / 160;

    if (posy > 34 || posx > 60)
        return 1;
    if (posx < 0 || posy < 0)
        return 1;
    if (posx == 34 || posy == 60 || posx == 0 || posy == 0)
        return 1;
    return 0;
}

int map_colision_2(sfRectangleShape *exit, hero_t *plyr, map_t *map)
{
    sfFloatRect rect_ply = sfRectangleShape_getGlobalBounds(plyr->colision);
    sfFloatRect rect_exit = sfRectangleShape_getGlobalBounds(exit);

    if (sfFloatRect_intersects(&rect_exit, &rect_ply, NULL) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(plyr->colision, sfRed);
            sfRectangleShape_setOutlineColor(exit, sfRed);
            return 1;
        }
        return 0;
    } else {
        sfRectangleShape_setOutlineColor(plyr->colision, sfGreen);
        sfRectangleShape_setOutlineColor(exit, sfGreen);
        return 0;
    }
}

static void set_new_map_new(window_t *window, hero_t *plyr, map_t *map,
    hero_t *mob)
{
    set_mob_back_shoot(mob, plyr, map);
    if (map->is_next)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_next, NULL);
    if (map->is_prev)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_prev, NULL);
    sfRenderWindow_drawSprite(window->window, map->pnj->pnj, NULL);
    sfRenderWindow_drawSprite(window->window, map->map, NULL);
}

static void set_new_map_prev(window_t *window, hero_t *plyr, map_t *map,
    hero_t *mob)
{
    set_mob_back_shoot(mob, plyr, map);
    if (map->is_next)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_next, NULL);
    if (map->is_prev)
        sfRenderWindow_drawRectangleShape(window->window,
            map->exit_player_prev, NULL);
    sfRenderWindow_drawSprite(window->window, map->pnj->pnj, NULL);
    sfRenderWindow_drawSprite(window->window, map->map, NULL);
}

map_t *map_colision(window_t *window, hero_t *plyr, map_t *map, hero_t *mob)
{
    if (map->is_next) {
        if (map_colision_2(map->exit_player_next, plyr, map) == 1) {
            sfSound_stop(map->song);
            map->rep = 0;
            map = map->prev;
            set_new_map_new(window, plyr, map, mob);
        }
    }
    if (map->is_prev) {
        if (map_colision_2(map->exit_player_prev, plyr, map) == 1) {
            sfSound_stop(map->song);
            map = map->next;
            set_new_map_prev(window, plyr, map, mob);
        }
    }
    return map;
}

void colision(hero_t *mob, hero_t *plyr, map_t *map)
{
    sfFloatRect rect_mob = sfRectangleShape_getGlobalBounds(mob->colision);
    sfFloatRect rect_ply = sfRectangleShape_getGlobalBounds(plyr->colision);

    if (sfFloatRect_intersects(&rect_mob, &rect_ply, NULL) == sfTrue) {
        sfRectangleShape_setOutlineColor(plyr->colision, sfRed);
        sfRectangleShape_setOutlineColor(mob->colision, sfRed);
        plyr->player->life = plyr->player->life - 0;
        if (plyr->player->life <= 0)
            dead_hero(plyr, map);
        plyr->recHP.width = plyr->recHP.width - 0;
        sfSprite_setTextureRect(plyr->spHP, plyr->recHP);
    } else {
        sfRectangleShape_setOutlineColor(plyr->colision, sfGreen);
        sfRectangleShape_setOutlineColor(mob->colision, sfGreen);
    }
}
