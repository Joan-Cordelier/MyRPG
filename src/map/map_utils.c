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

static int **array_to_int_array(char *buffer)
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

void set_rect(sfRectangleShape *rect, int x, int y)
{
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(rect, (sfVector2f){y, x});
    sfRectangleShape_setSize(rect, (sfVector2f){480, 160});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setOutlineColor(rect, sfGreen);
}

static void init_cave(map_t *map)
{
    char *buffer = open_read("sprite/map/cave.txt");

    map->start_player = (sfVector2f){1515, 875};
    map->start_mob = (sfVector2f){4300, 3000};
    map->txt_map = array_to_int_array(buffer);
    map->exit_player_prev = sfRectangleShape_create();
    set_rect(map->exit_player_prev, 4 * 160, 8 * 160);
    map->is_prev = true;
    map->exit_player_next = sfRectangleShape_create();
    set_rect(map->exit_player_next, 7 * 160, 50 * 160);
    map->is_next = true;
    map->timeS = sfClock_create();
    map->song = sfSound_create();
    map->song2 = sfSoundBuffer_createFromFile("sprite/song/AtDoomsGate.ogg");
    map->rep = 0;
    sfSound_setBuffer(map->song, map->song2);
    init_pnj_null(map);
}

static void init_spawn(map_t *map)
{
    char *buffer = open_read("sprite/map/spawn.txt");

    map->start_player = (sfVector2f){8000, 480};
    map->start_mob = (sfVector2f){8000, 4800};
    map->txt_map = array_to_int_array(buffer);
    map->exit_player_next = sfRectangleShape_create();
    set_rect(map->exit_player_next, 2 * 160, 31 * 160);
    map->is_next = true;
    map->timeS = sfClock_create();
    map->song = sfSound_create();
    map->song2 = sfSoundBuffer_createFromFile("sprite/song/AtDoomsGate.ogg");
    map->rep = 0;
    sfSound_setBuffer(map->song, map->song2);
    init_pnj_cave(map);
}

static void init_boss(map_t *map)
{
    char *buffer = open_read("sprite/map/boss.txt");

    map->start_player = (sfVector2f){1515, 875};
    map->start_mob = (sfVector2f){4300, 3000};
    map->txt_map = array_to_int_array(buffer);
    map->exit_player_prev = sfRectangleShape_create();
    set_rect(map->exit_player_prev, 4 * 160, 8 * 160);
    map->is_prev = true;
    map->is_next = false;
    map->timeS = sfClock_create();
    map->song = sfSound_create();
    map->song2 = sfSoundBuffer_createFromFile("sprite/song/AtDoomsGate.ogg");
    map->rep = 0;
    sfSound_setBuffer(map->song, map->song2);
    init_pnj_null(map);
}

void init_maps(map_t *map)
{
    if (strcmp(map->name, "sprite/map/cave.png") == 0)
        init_cave(map);
    if (strcmp(map->name, "sprite/map/spawn.png") == 0)
        init_spawn(map);
    if (strcmp(map->name, "sprite/map/boss.png") == 0)
        init_boss(map);
}

void add_map(char *str, map_t **map)
{
    map_t *new = malloc(sizeof(map_t));

    memset(new, 0, sizeof(map_t));
    new->prev = NULL;
    new->map = fond(str, 5, 5);
    new->name = strdup(str);
    init_maps(new);
    new->next = *map;
    if (new->next != NULL)
        new->next->prev = new;
    *map = new;
}

void init_map(map_t *map)
{
    char *path[] = {"sprite/map/spawn.png", "sprite/map/cave.png",
        "sprite/map/boss.png", NULL};

    memset(map, 0, sizeof(map_t));
    for (int i = 0; path[i] != NULL; i++)
        add_map(path[i], &map);
}
