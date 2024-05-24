/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** pnj.c
*/

#include "my.h"

void check_status(pnj_t *pnj, hero_t *hero)
{
    if (pnj->dialogue[pnj->line] != NULL) {
        sfText_setString(pnj->text, pnj->dialogue[pnj->line]);
        sfText_setFont(pnj->text, pnj->font);
        sfText_setCharacterSize(pnj->text, 45);
        sfText_setFillColor(pnj->text, sfColor_fromRGB(255, 255, 255));
        sfText_setPosition(pnj->text, (sfVector2f){(pnj->posx + 20),
            (pnj->posy + 120)});
        pnj->line++;
        pnj->talk = true;
        hero->moove = false;
        return;
    }
    pnj->talk = false;
    hero->moove = true;
}

void init_pnj_cave(map_t *map)
{
    char *buffer = open_read("dialogue/dialogue.txt");

    map->pnj = malloc(sizeof(pnj_t));
    memset(map->pnj, 0, sizeof(pnj_t));
    map->pnj->pnj = sfSprite_create();
    map->pnj->pnj_texture = sfTexture_createFromFile("sprite/mob_boss/pnj.png",
        NULL);
    map->pnj->posx = map->start_player.x;
    map->pnj->posy = map->start_player.y;
    map->pnj->font = sfFont_createFromFile("police.ttf");
    map->pnj->text = sfText_create();
    map->pnj->dialogue = my_str_to_word_array(buffer, "$");
    sfSprite_setTexture(map->pnj->pnj, map->pnj->pnj_texture, sfTrue);
    sfSprite_setOrigin(map->pnj->pnj, (sfVector2f){0, 0});
    sfSprite_setPosition(map->pnj->pnj,
        (sfVector2f){map->pnj->posx, map->pnj->posy});
    sfSprite_setScale(map->pnj->pnj, (sfVector2f){2, 2});
}
