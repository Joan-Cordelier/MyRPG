/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
*/

#include "my.h"
#include <string.h>

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

void move_rect(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 3; n++) {
        rect->left += offset;
        if (rect->left >= max)
            rect->left = 0;
    }
}

void move_rect2(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 3; n++) {
        rect->height += offset;
        if (rect->height >= max)
            rect->height = 0;
    }
}

static void move_anim(sfClock *clock, hero_t *cible)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(clock);
    if (clock_espl.microseconds > 300000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect(&cible->rect, 140, 340);
        sfClock_restart(clock);
    }
}

static void move_anim2(sfClock *clock, hero_t *cible)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(clock);
    if (clock_espl.microseconds > 300000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect2(&cible->rect, 150, 600);
        sfClock_restart(clock);
    }
}

static void draw_sprite(window_t *window, hero_t *plyr,
    sfSprite *sword, int change)
{
    sfVector2i button_positions = mouse(window->window);

    sfView_setCenter(plyr->run, (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(plyr->sprite,
        (sfVector2f){plyr->posx, plyr->posy});
    sfSprite_setPosition(sword, (sfVector2f){plyr->posx, plyr->posy});
    plyr->angle = sword_rotate(plyr, window, button_positions);
    rotate_png(plyr, window, button_positions, sword);
    if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0)
        plyr->angle = plyr->angle - 90.0;
    sfSprite_setRotation(sword, plyr->angle);
    sfRenderWindow_clear(window->window, sfBlack);
    
}

static sfSprite *change_arms(sfSprite *sword, char **arms,
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

static void show_window(window_t *window, hero_t *plyr, sfSprite *back,
    sfSprite *sword)
{
    sfRenderWindow_setView(window->window, plyr->run);
    sfRenderWindow_drawSprite(window->window, back, NULL);
    sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, sword, NULL);
}

static void enemie(hero_t *mob, hero_t *plyr, window_t *window, sfClock *anim)
{
    if (plyr->posx > mob->posx)
        mob->posx = mob->posx + 7;
    if (plyr->posx < mob->posx)
        mob->posx = mob->posx - 7;
    if (plyr->posy > mob->posy)
        mob->posy = mob->posy + 7;
    if (plyr->posy < mob->posy)
        mob->posy = mob->posy - 7;
    move_anim2(anim, mob);
    sfSprite_setPosition(mob->sprite, (sfVector2f){mob->posx, mob->posy});
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
}

void my_rpg(window_t *window, hero_t *plyr,
    sfSprite *sword, sfEvent event)
{
    sfClock *anim = sfClock_create();
    hero_t *mob = hero("sprite/mob_boss/mob_sqlt.png", 150, 150);
    sfSprite *back = fond("sprite/map.jpg", 3, 3);
    sfSprite *shoot = fond("sprite/fire_ball.png", 1, 1);
    char *arms[] = {"epee-3.png", "shotgun-1.png", NULL};
    int change = 0;

    sfSprite_setOrigin(back, (sfVector2f){0, 0});
    plyr->run = sfView_create();
    sfView_setSize(plyr->run, (sfVector2f){1750, 1000});
    sfSprite_setOrigin(mob->sprite, (sfVector2f){70, 70});
    sfSprite_setOrigin(shoot, (sfVector2f){32, 32});
    sfView_zoom(plyr->run, 1);
    window->speed = 0;
    while (sfRenderWindow_isOpen(window->window)) {
        sword = change_arms(sword, arms, &change);
        if (window->speed == 0)
            sfSprite_setPosition(shoot, (sfVector2f){plyr->posx, plyr->posy});
        move_anim(anim, plyr);
        set_move(back, window, plyr);
        draw_sprite(window, plyr, sword, change);
        show_window(window, plyr, back, sword);
        enemie(mob, plyr, window, anim);
        shoot = poll_event(event, window, change, shoot);
        if (window->speed == 0)
            sfSprite_setRotation(shoot, plyr->angle);
        sfRenderWindow_display(window->window);
    }
    sfSprite_destroy(mob->sprite);
    sfSprite_destroy(shoot);
    sfSprite_destroy(back);
    sfClock_destroy(anim);
}

void menu_prcp(window_t *window, char *file, sfEvent event)
{
    hero_t *plyr = hero("sprite/hero_rpg/hero.png", 140, 140);
    sfSprite *sword = fond("sprite/arme/epee-4.png", 1, 1);

    sfSprite_setOrigin(plyr->sprite, (sfVector2f){70, 70});
    my_rpg(window, plyr, sword, event);
    sfSprite_destroy(plyr->sprite);
    sfRenderWindow_destroy(window->window);
}
