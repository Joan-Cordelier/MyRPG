/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** wepon.c
*/

#include "my.h"

static void create_weapon(weapon_t *new, char *file)
{
    new->weapon_texture = sfTexture_createFromFile(file, NULL);
    new->weapon = sfSprite_create();
    new->colision_w = sfRectangleShape_create();
    sfRectangleShape_setOrigin(new->colision_w, (sfVector2f){30, 130});
    sfRectangleShape_setSize(new->colision_w, (sfVector2f){60, 140});
    sfRectangleShape_setOutlineThickness(new->colision_w, 2);
    sfRectangleShape_setOutlineColor(new->colision_w, sfGreen);
    sfRectangleShape_setFillColor(new->colision_w, sfTransparent);
    sfSprite_setTexture(new->weapon, new->weapon_texture, sfTrue);
    sfSprite_setScale(new->weapon, (sfVector2f){1, 1});
    sfSprite_setOrigin(new->weapon, (sfVector2f){100, 150});
}

static void create_bullet(weapon_t *new, char *file)
{
    if (new->status == GUN)
        new->bullet_texture = sfTexture_createFromFile("sprite/fire_ball.png",
            NULL);
    else
        new->bullet_texture = sfTexture_createFromFile(file, NULL);
    new->bullet = sfSprite_create();
    new->colision_b = sfRectangleShape_create();
    sfRectangleShape_setOrigin(new->colision_b, (sfVector2f){32, 32});
    sfRectangleShape_setSize(new->colision_b, (sfVector2f){32, 32});
    sfRectangleShape_setOutlineThickness(new->colision_b, 2);
    sfRectangleShape_setOutlineColor(new->colision_b, sfGreen);
    sfRectangleShape_setFillColor(new->colision_b, sfTransparent);
    sfSprite_setTexture(new->bullet, new->bullet_texture, sfTrue);
    sfSprite_setScale(new->bullet, (sfVector2f){1, 1});
    sfSprite_setOrigin(new->bullet, (sfVector2f){32, 32});
}

void add_weapon(weapon_t **weapon, char *file, int status)
{
    weapon_t *new = malloc(sizeof(weapon_t));

    memset(new, 0, sizeof(weapon_t));
    new->prev = NULL;
    new->status = status;
    create_weapon(new, file);
    if (new->status == GUN || new->status == SPELL)
        create_bullet(new, file);
    new->next = *weapon;
    if (new->next != NULL)
        new->next->prev = new;
    *weapon = new;
}

void init_weapon(hero_t *hero)
{
    char *hero_weapon[] = {"sprite/arme/epee-3.png",
    "sprite/arme/shotgun-1.png", "sprite/fire_ball.png", NULL};
    char *squelet_weapon[] = {"sprite/arme/mob_sqlt-1.png", NULL};

    if (hero->status == PNJ)
        return;
    if (hero->status == PLYR)
        for (int i = 0; hero_weapon[i] != NULL; i++)
            add_weapon(&hero->weapon, hero_weapon[i], i);
    if (hero->status == SQUELETON)
        for (int i = 0; squelet_weapon[i] != NULL; i++)
            add_weapon(&hero->weapon, squelet_weapon[i], SWORD);
}
