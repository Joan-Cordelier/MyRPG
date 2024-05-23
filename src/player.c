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
    memset(player->player, 0, sizeof(stat_t));
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

void check_spe2(hero_t *plyr, int speed, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ) &&
        is_touching((plyr->posx - speed * 0.5), (plyr->posy + speed * 0.5),
        map->txt_map) == 0) {
        plyr->posy = plyr->posy + speed * 0.5;
        plyr->posx = plyr->posx - speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ) &&
        is_touching((plyr->posx - speed * 0.5), (plyr->posy - speed * 0.5),
        map->txt_map) == 0) {
        plyr->posy = plyr->posy - speed * 0.5;
        plyr->posx = plyr->posx - speed * 0.5;
    }
}

void check_spe(hero_t *plyr, int speed, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD) &&
        is_touching((plyr->posx + speed * 0.5), (plyr->posy - speed * 0.5),
        map->txt_map) == 0) {
        plyr->posy = plyr->posy - speed * 0.5;
        plyr->posx = plyr->posx + speed * 0.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD) &&
        is_touching((plyr->posx + speed * 0.5), (plyr->posy + speed * 0.5),
        map->txt_map) == 0) {
        plyr->posy = plyr->posy + speed * 0.5;
        plyr->posx = plyr->posx + speed * 0.5;
    }
    check_spe2(plyr, speed, map);
}

static int move_plarer2(hero_t *plyr, int speed, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && is_touching(
        plyr->posx, plyr->posy - speed, map->txt_map) == 0) {
        plyr->posy = plyr->posy - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && is_touching(
        plyr->posx, plyr->posy + speed, map->txt_map) == 0) {
        plyr->posy = plyr->posy + speed;
        return 1;
    }
    return 0;
}

static int move_player(hero_t *plyr, int speed, map_t *map)
{
    check_spe(plyr, speed, map);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && is_touching(
        plyr->posx - speed, plyr->posy, map->txt_map) == 0) {
        plyr->posx = plyr->posx - speed;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && is_touching(
        plyr->posx + speed, plyr->posy, map->txt_map) == 0) {
        plyr->posx = plyr->posx + speed;
        return 1;
    }
    return move_plarer2(plyr, speed, map);
}

int set_move(hero_t *plyr, map_t *map)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(plyr->endspe);
    if (sfKeyboard_isKeyPressed(sfKeyA) && plyr->player->end > 0) {
        sfClock_restart(plyr->endspe);
        move_player(plyr, 50, map);
        plyr->player->end = plyr->player->end - 10;
    } else
        move_player(plyr, 10, map);
    if (clock_espl.microseconds > 2000000) {
        plyr->player->end = END;
        sfClock_restart(plyr->endspe);
    }
    plyr->recStam.width = plyr->player->end;
    sfSprite_setTextureRect(plyr->spStam, plyr->recStam);
    return 0;
}
