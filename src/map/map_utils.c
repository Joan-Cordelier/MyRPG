/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map_utils.c
*/

#include "my.h"

void add_map(char *str, map_t **map)
{
    map_t *new = malloc(sizeof(map_t));

    new->prev = NULL;
    new->name = strdup(str);
    new->start_player = (sfVector2f){0, 0};
    new->map = fond(str, 5, 5);
    new->start_mob = NULL;
    new->next = *map;
    if (new->next != NULL)
        new->next->prev = new;
    *map = new;
}

static void init_cave(map_t *map)
{
    map->start_player = (sfVector2f){1515, 875};
    map->exit_player = sfRectangleShape_create();
    sfRectangleShape_setOrigin(map->exit_player, (sfVector2f){8100, 1325});
    sfRectangleShape_setSize(map->exit_player, (sfVector2f){350, 20});
    sfRectangleShape_setFillColor(map->exit_player, sfTransparent);
    sfRectangleShape_setOutlineThickness(map->exit_player, 2);
    sfRectangleShape_setOutlineColor(map->exit_player, sfGreen);
}

void init_maps(map_t *map)
{
    if (strcmp(map->name, "sprite/map/cave.png") == 0)
        init_cave(map);
}

void init_map(map_t *map)
{
    char *path[] = {"sprite/map/cave.png", NULL};

    for (int i = 0; path[i] != NULL; i++)
        add_map(path[i], &map);
    while (map != NULL) {
        init_maps(map);
        map = map->prev;
    }
}
