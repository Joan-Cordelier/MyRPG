/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** print_inventaire.c
*/

#include "my.h"

void set_rect_inv(sfRectangleShape *rect, int x, int y)
{
    sfRectangleShape_setOrigin(rect, (sfVector2f){15, 55});
    sfRectangleShape_setPosition(rect, (sfVector2f){y, x});
    sfRectangleShape_setSize(rect, (sfVector2f){70, 70});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setOutlineColor(rect, sfGreen);
}

void init_armes(hero_t *plyr)
{
    plyr->inv->txS = sfTexture_createFromFile("sprite/arme/epee-3.png", NULL);
    plyr->inv->spS = sfSprite_create();
    plyr->inv->txG = sfTexture_createFromFile
        ("sprite/arme/shotgun-1.png", NULL);
    plyr->inv->spG = sfSprite_create();
    sfSprite_setTexture(plyr->inv->spS, plyr->inv->txS, sfTrue);
    sfSprite_setTexture(plyr->inv->spG, plyr->inv->txG, sfTrue);
    sfSprite_setScale(plyr->inv->spG, (sfVector2f){0.4, 0.4});
    sfSprite_setScale(plyr->inv->spS, (sfVector2f){0.4, 0.4});
    sfSprite_setPosition(plyr->inv->spS,
        (sfVector2f){plyr->posx - 170, plyr->posy + 370});
    sfSprite_setPosition(plyr->inv->spG,
        (sfVector2f){plyr->posx - 70, plyr->posy + 370});
}

void set_inventaire(hero_t *plyr)
{
    sfSprite_setPosition(plyr->inv->spIn,
        (sfVector2f){plyr->posx - 180, plyr->posy + 350});
    sfRectangleShape_setPosition(plyr->inv->epee,
        (sfVector2f){plyr->posx - 140, plyr->posy + 350 + 80});
    sfRectangleShape_setPosition(plyr->inv->gun,
        (sfVector2f){plyr->posx - 55, plyr->posy + 350 + 80});
    sfRectangleShape_setPosition(plyr->inv->fioleMana,
        (sfVector2f){plyr->posx + 30, plyr->posy + 350 + 80});
    sfRectangleShape_setPosition(plyr->inv->fioleVie,
        (sfVector2f){plyr->posx + 115, plyr->posy + 350 + 80});
    init_armes(plyr);
}

void print_inventaire(window_t *window, hero_t *plyr)
{
    if (plyr->Inv == true) {
        sfRenderWindow_drawSprite(window->window, plyr->inv->spIn, NULL);
        sfRenderWindow_drawRectangleShape(window->window,
            plyr->inv->epee, NULL);
        sfRenderWindow_drawRectangleShape(window->window,
            plyr->inv->gun, NULL);
        sfRenderWindow_drawRectangleShape(window->window,
            plyr->inv->fioleMana, NULL);
        sfRenderWindow_drawRectangleShape(window->window,
            plyr->inv->fioleVie, NULL);
        sfRenderWindow_drawSprite(window->window, plyr->inv->spG, NULL);
        sfRenderWindow_drawSprite(window->window, plyr->inv->spS, NULL);
    }
}
