/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** pnj.c
*/

#include "my.h"

static char *open_file(char *av, char *buffer)
{
    int size = -1;
    struct stat sb;
    int fd = 0;

    stat(av, &sb);
    buffer = malloc(sizeof(char *) * (sb.st_size +1));
    buffer[sb.st_size] = 0;
    fd = open(av, O_RDONLY);
    if (buffer == NULL || fd == -1 || sb.st_size == 0
    || !S_ISREG(sb.st_mode)) {
        close(fd);
        return NULL;
    }
    read(fd, buffer, sb.st_size);
    close(fd);
    buffer[sb.st_size] = '\0';
    return buffer;
}

int lore(pnj_t *pnj, window_t *window, sfFont *font, sfText *text)
{
    sfText_setFillColor(text, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(text, (sfVector2f){(pnj->posx + 20), (pnj->posy + 120)});
    sfRenderWindow_drawText(window->window, text, NULL);
    return 0;
}

static int display_dial2(pnj_t *pnj, window_t *window, char **dialogue, int i)
{
    sfFont* font = sfFont_createFromFile("police.ttf");
    sfText* text = sfText_create();

    if (i == 2) {
        sfText_setString(text, dialogue[i]);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 45);
        lore(pnj, window, font, text);
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            sfFont_destroy(font);
            sfText_destroy(text);
            i++;
            return i;
        }
    }
    if (i == 3) {
        sfText_setString(text, dialogue[i]);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 45);
        lore(pnj, window, font, text);
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            sfFont_destroy(font);
            sfText_destroy(text);
            i++;
            return i;
        }
    } else {
        sfFont_destroy(font);
        sfText_destroy(text);
        return i;
    }
    return i;
}

static int display_dial(pnj_t *pnj, window_t *window, char **dialogue, int i)
{
    sfFont* font = sfFont_createFromFile("police.ttf");
    sfText* text = sfText_create();

    if (i == 0) {
        sfText_setString(text, dialogue[i]);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 45);
        lore(pnj, window, font, text);
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            sfFont_destroy(font);
            sfText_destroy(text);
            i++;
            return i;
        }
    }
    if (i == 1) {
        sfText_setString(text, dialogue[i]);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 45);
        lore(pnj, window, font, text);
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            sfFont_destroy(font);
            sfText_destroy(text);
            i++;
            return i;
        }
    } else {
        sfFont_destroy(font);
        sfText_destroy(text);
        return display_dial2(pnj, window, dialogue, i);
    }
    return i;
}

void check_status(pnj_t *pnj, hero_t *hero, window_t *window)
{
    char *buffer = 0;
    char **dialogue = 0;

    buffer = open_file("dialogue/dialogue.txt", buffer);
    dialogue = my_str_to_word_array(buffer, "$");
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        printf("%d\n", pnj->status);
        pnj->status = display_dial(pnj, window, dialogue, pnj->status);
    }
}

void init_pnj_cave(map_t *map)
{
    map->pnj = malloc(sizeof(pnj_t));
    memset(map->pnj, 0, sizeof(pnj_t));
    map->pnj->pnj = sfSprite_create();
    map->pnj->pnj_texture = sfTexture_createFromFile("sprite/mob_boss/pnj.png",
        NULL);
    map->pnj->posx = map->start_player.x;
    map->pnj->posy = map->start_player.y;
    map->pnj->status = 0;
    sfSprite_setTexture(map->pnj->pnj, map->pnj->pnj_texture, sfTrue);
    sfSprite_setOrigin(map->pnj->pnj, (sfVector2f){0, 0});
    sfSprite_setPosition(map->pnj->pnj,
        (sfVector2f){map->pnj->posx, map->pnj->posy});
    sfSprite_setScale(map->pnj->pnj, (sfVector2f){2, 2});
}
