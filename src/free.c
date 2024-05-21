/*
** EPITECH PROJECT, 2024
** free
** File description:
** free
*/

#include "my.h"

void my_destroy(hero_t *sprite)
{
    sfClock_destroy(sprite->anim);
    sfClock_destroy(sprite->endspe);
    sfTexture_destroy(sprite->texture);
    sfTexture_destroy(sprite->texHP);
    sfTexture_destroy(sprite->texMan);
    sfTexture_destroy(sprite->texStam);
    sfSprite_destroy(sprite->sprite);
    sfSprite_destroy(sprite->spHP);
    sfSprite_destroy(sprite->spMan);
    sfSprite_destroy(sprite->spStam);
    sfClock_destroy(sprite->anim);
    sfClock_destroy(sprite->endspe);
    sfView_destroy(sprite->run);
    sfTexture_destroy(sprite->texStam);
    sfSprite_destroy(sprite->spStam);
    sfTexture_destroy(sprite->texMan);
    sfSprite_destroy(sprite->spMan);
    sfRectangleShape_destroy(sprite->colision);
}

void my_destroy_w(weapon_t *arme)
{
    sfTexture_destroy(arme->texture);
    sfSprite_destroy(arme->sprite);
}

void my_free(hero_t *sprite, weapon_t *arme)
{
    my_destroy(sprite);
    my_destroy_w(sprite->arme);
    free(sprite->player);
    free(sprite->arme);
    free(sprite);
}
