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
    player->player->end = END;
    player->player->nb_fiol = NB_FIOL;
    player->player->weap_hnd = EPEE_1;
    player->player->lv_magie = 1;
    player->player->lv_shotgun = 1;
    player->player->lv_sword = 1;
    player->player->niv = 1;
}

void check_spe(int *x, int *y, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y - speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        *y = *y + speed * 0.5;
        *x = *x + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        *y = *y + speed * 0.5;
        *x = *x - speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ)) {
        *y = *y - speed * 0.5;
        *x = *x - speed * 0.5;
    }
}

int move_player(int *x, int *y, int speed)
{
    check_spe(x, y, speed);
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        *x = *x - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        *x = *x + speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        *y = *y - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        *y = *y + speed;
        return 1;
    }
    return 0;
}

int set_move(hero_t *plyr)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(plyr->endspe);
    if (sfKeyboard_isKeyPressed(sfKeyA) && plyr->player->end > 0) {
        sfClock_restart(plyr->endspe);
        move_player(&plyr->posx, &plyr->posy, 50);
        plyr->player->end = plyr->player->end - 10;
    } else
        move_player(&plyr->posx, &plyr->posy, 10);
    if (clock_espl.microseconds > 2000000) {
        plyr->player->end = END;
        sfClock_restart(plyr->endspe);
    }
    plyr->recStam.width = plyr->player->end;
    sfSprite_setTextureRect(plyr->spStam, plyr->recStam);
    return 0;
}

//was line 77

/* if (sfKeyboard_isKeyPressed(sfKeyA) && plyr->player->end >= 0) {
    move_player(&plyr->posx, &plyr->posy, 30);
    plyr->player->end = plyr->player->end - 25;
} else */
/* while (sfRenderWindow_pollEvent(window->window, &event)) {
} */
