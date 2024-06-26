/*
** EPITECH PROJECT, 2023
** png
** File description:
** png
*/

#include "my.h"
#include <math.h>

static void create_rectange_shape(hero_t *hero)
{
    hero->colision = sfRectangleShape_create();
    sfRectangleShape_setOrigin(hero->colision, (sfVector2f){50, 60});
    sfRectangleShape_setPosition(hero->colision, hero->pos);
    sfRectangleShape_setSize(hero->colision, (sfVector2f){100, 120});
    sfRectangleShape_setFillColor(hero->colision, sfTransparent);
    sfRectangleShape_setOutlineThickness(hero->colision, 2);
    sfRectangleShape_setOutlineColor(hero->colision, sfGreen);
}

static void crate_stats_sprites(hero_t *hero)
{
    hero->songG2 = sfSoundBuffer_createFromFile("sprite/song/Shotgun.ogg");
    hero->songG = sfSound_create();
    hero->songS2 = sfSoundBuffer_createFromFile("sprite/song/Sword.ogg");
    hero->songS = sfSound_create();
    hero->texHP = sfTexture_createFromFile("sprite/hero_rpg/HP.png", NULL);
    hero->spHP = sfSprite_create();
    hero->texStam = sfTexture_createFromFile(
        "sprite/hero_rpg/Stamina.png", NULL);
    hero->spStam = sfSprite_create();
    hero->texMan = sfTexture_createFromFile("sprite/hero_rpg/Mana.png", NULL);
    hero->spMan = sfSprite_create();
}

static void set_sprite_stat(hero_t *hero)
{
    sfSprite_setTexture(hero->spHP, hero->texHP, sfTrue);
    sfSprite_setTexture(hero->spStam, hero->texStam, sfTrue);
    sfSprite_setTexture(hero->spMan, hero->texMan, sfTrue);
    sfSprite_setTextureRect(hero->spHP, hero->recHP);
    sfSprite_setTextureRect(hero->spStam, hero->recStam);
    sfSprite_setTextureRect(hero->spMan, hero->recMan);
    sfSprite_setScale(hero->spHP, hero->scale);
    sfSprite_setScale(hero->spStam, hero->scale);
    sfSprite_setScale(hero->spMan, hero->scale);
    sfSound_setBuffer(hero->songG, hero->songG2);
    sfSound_setBuffer(hero->songS, hero->songS2);
}

static void create_stat(hero_t *hero)
{
    crate_stats_sprites(hero);
    hero->recHP.top = 0;
    hero->recHP.left = 0;
    hero->recHP.width = 100;
    hero->recHP.height = 100;
    hero->recStam.top = 0;
    hero->recStam.left = 0;
    hero->recStam.width = 100;
    hero->recStam.height = 100;
    hero->recMan.top = 0;
    hero->recMan.left = 0;
    hero->recMan.width = 100;
    hero->recMan.height = 100;
    set_sprite_stat(hero);
}

void init_inventaire(inventaire_t *hero, hero_t *plyr)
{
    plyr->Inv = false;
    hero->recIn.top = 207;
    hero->recIn.left = 80;
    hero->recIn.width = 80;
    hero->recIn.height = 230;
    hero->texIn = sfTexture_createFromFile("sprite/map/inventory.png", NULL);
    hero->spIn = sfSprite_create();
    sfSprite_setTexture(hero->spIn, hero->texIn, sfTrue);
    sfSprite_setTextureRect(hero->spIn, hero->recIn);
    sfSprite_setScale(hero->spIn, (sfVector2f){5, 5});
    sfSprite_setPosition(hero->spIn,
        (sfVector2f){plyr->posx - 40, plyr->posy - 10});
    hero->epee = sfRectangleShape_create();
    hero->gun = sfRectangleShape_create();
    hero->fioleMana = sfRectangleShape_create();
    hero->fioleVie = sfRectangleShape_create();
    set_rect_inv(hero->epee, plyr->posx - 40, plyr->posy - 10);
    set_rect_inv(hero->gun, plyr->posx - 20, plyr->posy - 10);
    set_rect_inv(hero->fioleMana, plyr->posx, plyr->posy - 10);
    set_rect_inv(hero->fioleVie, plyr->posx + 20, plyr->posy - 10);
}

static void create_inv(hero_t *hero)
{
    hero->inv = malloc(sizeof(inventaire_t));
    memset(hero->inv, 0, sizeof(inventaire_t));
    init_inventaire(hero->inv, hero);
}

static void create_hero(hero_t *hero, char *file, int x, int y)
{
    hero->texture = sfTexture_createFromFile(file, NULL);
    hero->sprite = sfSprite_create();
    hero->scale = (sfVector2f){2, 2};
    hero->pos = (sfVector2f){960, 540};
    hero->rect.top = 0;
    hero->rect.left = 0;
    hero->rect.width = x;
    hero->rect.height = y;
    hero->posx = 0;
    hero->posy = 0;
    sfSprite_setTexture(hero->sprite, hero->texture, sfTrue);
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfSprite_setScale(hero->sprite, hero->scale);
    sfSprite_setPosition(hero->sprite, hero->pos);
}

hero_t *init_hero(char *file, int x, int y, int status)
{
    hero_t *hero = malloc(sizeof(hero_t));

    srand(time(NULL));
    memset(hero, 0, sizeof(hero_t));
    create_hero(hero, file, x, y);
    hero->endspe = sfClock_create();
    hero->anim = sfClock_create();
    hero->spatt = sfClock_create();
    hero->status = status;
    hero->moove = true;
    create_rectange_shape(hero);
    create_stat(hero);
    hero_xp(hero);
    create_inv(hero);
    init_player(hero);
    init_weapon(hero);
    return hero;
}
