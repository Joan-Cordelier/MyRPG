/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map_utils.c
*/

#include "my.h"

static void free_all(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int **array_to_int_array(char *buffer)
{
    char **array = my_str_to_word_array(buffer, " ,\n");
    int **map = malloc(sizeof(int *) * 35);
    int x = 0;
    int y = 0;

    for (int i = 0; i < 35; i++)
        map[i] = malloc(sizeof(int) * 60);
    for (int i = 0; i < 34; i++)
        for (int j = 0; j < 60; j++)
            map[i][j] = 0;
    for (int i = 1; array[i] != NULL; i++) {
        if (i % 60 == 0) {
            x++;
            y = 0;
        }
        map[x][y] = atoi(array[i]);
        y++;
    }
    free_all(array);
    return map;
}

void add_map(char *str, map_t **map)
{
    map_t *new = malloc(sizeof(map_t));

    memset(new, 0, sizeof(map_t));
    new->exit_player = NULL;
    new->map = fond(str, 5, 5);
    new->name = strdup(str);
    new->next = NULL;
    new->prev = NULL;
    new->rectangle = NULL;
    new->start_mob = (sfVector2f){0, 0};
    new->start_player = (sfVector2f){0, 0};
    new->txt_map = NULL;
    new->next = *map;
    if (new->next != NULL)
        new->next->prev = new;
    *map = new;
}

static int is_possible(int **txt_map, int x, int y)
{
    if (x - 1 < 0 || x + 1 >= 34 || y - 1 < 0 || y + 1 >= 60)
        return 0;
    if (txt_map[x - 1][y] == 1 || txt_map[x + 1][y] == 1 ||
        txt_map[x][y - 1] == 1 || txt_map[x][y + 1] == 1 ||
        txt_map[x + 1][y + 1] == 1 || txt_map[x - 1][y - 1] == 1 ||
        txt_map[x - 1][y + 1] == 1 || txt_map[x + 1][y - 1] == 1)
        return 0;
    return 1;
}

static int get_status(int x, int y)
{
    if (x == 33 || x == 0 || y == 0 || y == 59)
        return SHOOT;
    return PLAYER;
}

void add_rectangle(rectangle_t **rectangle, int **txt_map, int x, int y)
{
    rectangle_t *new = NULL;

    if (txt_map[x][y] == 1 || is_possible(txt_map, x, y) == 1)
        return;
    new = malloc(sizeof(rectangle_t));
    memset(new, 0, sizeof(rectangle_t));
    new->prev = NULL;
    new->rec = sfRectangleShape_create();
    sfRectangleShape_setOrigin(new->rec, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(new->rec, (sfVector2f){y * 160, x* 160});
    sfRectangleShape_setSize(new->rec, (sfVector2f){160, 160});
    sfRectangleShape_setOutlineThickness(new->rec, 2);
    sfRectangleShape_setOutlineColor(new->rec, sfGreen);
    sfRectangleShape_setFillColor(new->rec, sfTransparent);
    new->status = get_status(x, y);
    new->next = *rectangle;
    if (new->next != NULL)
        new->next->prev = new;
    *rectangle = new;
}

static void init_cave(map_t *map)
{
    char *buffer = open_read("sprite/map/cave.txt");
    int **txt_map = array_to_int_array(buffer);

    map->start_player = (sfVector2f){1515, 875};
    map->start_mob = (sfVector2f){4300, 3000};
    map->txt_map = array_to_int_array(buffer);
    map->exit_player = sfRectangleShape_create();
    sfRectangleShape_setOrigin(map->exit_player, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(map->exit_player, (sfVector2f){8100, 1325});
    sfRectangleShape_setSize(map->exit_player, (sfVector2f){350, 160});
    sfRectangleShape_setFillColor(map->exit_player, sfTransparent);
    sfRectangleShape_setOutlineThickness(map->exit_player, 2);
    sfRectangleShape_setOutlineColor(map->exit_player, sfGreen);
    map->rectangle = NULL;
    for (int i = 0; i < 34; i++)
        for (int j = 0; j < 60; j++)
            add_rectangle(&map->rectangle, txt_map, i, j);
    init_pnj_cave(map);
}

void init_maps(map_t *map)
{
    if (strcmp(map->name, "sprite/map/cave.png") == 0)
        init_cave(map);
}

void init_map(map_t *map)
{
    char *path[] = {"sprite/map/cave.png", NULL};

    memset(map, 0, sizeof(map_t));
    for (int i = 0; path[i] != NULL; i++)
        add_map(path[i], &map);
    while (map != NULL) {
        init_maps(map);
        map = map->prev;
    }
}
