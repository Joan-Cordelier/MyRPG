/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** csfml_utils.c
*/

#include "my.h"

sfVector2i mouse(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f final;

    final = sfRenderWindow_mapPixelToCoords(window, mouse_pos,
        sfRenderWindow_getView(window));
    return (sfVector2i){final.x, final.y};
}

sfSprite *fond(char *file, float x, float y)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *change_arms(sfSprite *sword, char **arms,
    int *change)
{
    char *choise = NULL;
    char *file = "sprite/arme/";
    char *pop = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyR) && *change < 1)
        *change = *change + 1;
    if (sfKeyboard_isKeyPressed(sfKeyE) && *change > 0)
        *change = *change - 1;
    choise = strdup(arms[*change]);
    pop = malloc(strlen(file) + strlen(choise) + 2);
    pop = strcpy(pop, file);
    pop = strcat(pop, choise);
    sfSprite_destroy(sword);
    sword = fond(pop, 1, 1);
    sfSprite_setPosition(sword, (sfVector2f){900, 500});
    sfSprite_setOrigin(sword, (sfVector2f){100, 150});
    return sword;
}
