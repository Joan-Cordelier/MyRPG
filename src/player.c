/*
** EPITECH PROJECT, 2024
** main
** File description:
** player
*/

#include "my.h"

void init_player(hero_t *player)
{
    player->player = malloc(sizeof(stat_t));
    player->player->life = LIFE;
    player->player->mana = MANA;
    player->player->nb_fiol = NB_FIOL;
    player->player->weap_hnd = EPEE_1;
    player->player->lv_magie = 1;
    player->player->lv_shotgun = 1;
    player->player->lv_sword = 1;
    player->player->niv = 1;
}

void check_spe(int *x, int *y, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD) && 
        *x <= 3000 && *y >= 0) {
        *y = *y - speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD) && 
        *x <= 3000 && *y <= 3000) {
        *y = *y + speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ) && 
        *x >= 0 && *y <= 3000) {
        *y = *y + speed * 0.5;
        *x = *x - speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ) && 
        *x >= 0 && *y >= 0) {
        *y = *y - speed * 0.5;
        *x = *x - speed * 0.5;
    }
}

int move_player(int *x, int *y, int speed)
{
    check_spe(x, y, speed);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && *x >= 0) {
        *x = *x - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && *x <= 3000) {
        *x = *x + speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && *y >= 0) {
        *y = *y - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && *y <= 3000) {
        *y = *y + speed;
        return 1;
    }
    return 0;
}

int set_move(sfSprite *back, window_t *window, hero_t *plyr)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        move_player(&plyr->posx, &plyr->posy, 30);
    } else
        move_player(&plyr->posx, &plyr->posy, 10);
    return 0;
}
