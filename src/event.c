/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** event
*/

#include "my.h"
#include <math.h>


static void shoot_gun(sfVector2f shoot_positions, window_t *window,
    hero_t *plyr)
{
    shoot_positions.x = shoot_positions.x + window->button_positions.x;
    shoot_positions.y = shoot_positions.y + window->button_positions.y;
    sfSprite_setPosition(plyr->weapon->bullet,
        (sfVector2f){shoot_positions.x, shoot_positions.y});
    sfRectangleShape_setPosition(plyr->weapon->colision_b,
        (sfVector2f){shoot_positions.x, shoot_positions.y});
}

static sfVector2i attack(int change, window_t *window, hero_t *plyr)
{
    sfVector2f shoot_positions = sfSprite_getPosition(plyr->weapon->bullet);
    float n = 0;
    float x = 0;
    float y = 0;

    if (change == 1 && plyr->recMan.width > 0) {
        plyr->recMan.width = plyr->recMan.width - 20;
        window->speed = 1;
    }
    window->button_positions = mouse(window->window);
    x = window->button_positions.x - shoot_positions.x;
    y = window->button_positions.y - shoot_positions.y;
    n = sqrt(pow(x, 2) + pow(y, 2));
    window->button_positions.x = (x / n) * 20;
    window->button_positions.y = (y / n) * 20;
    return window->button_positions;
}

static void mouse_button_press(sfEvent event, window_t *window, hero_t *plyr)
{
    if (event.mouseButton.button == sfMouseLeft && window->speed != 1 &&
        (plyr->weapon->status == GUN || plyr->weapon->status == SPELL)) {
        window->button_positions = attack(window->change, window, plyr);
        sfSprite_setTextureRect(plyr->spMan, plyr->recMan);
    }
}

static void change_arms(window_t *window, hero_t *plyr)
{
    if (sfKeyboard_isKeyPressed(sfKeyR) && window->change < 1) {
        window->change = window->change + 1;
        plyr->weapon = plyr->weapon->prev;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && window->change > 0) {
        window->change = window->change - 1;
        plyr->weapon = plyr->weapon->next;
    }
}

void poll_event2(sfVector2f shoot_positions, hero_t *plyr, window_t *window,
    hero_t *mob)
{
    if ((plyr->weapon->status == GUN || plyr->weapon->status == SPELL) &&
        window->speed > 0) {
        shoot_gun(shoot_positions, window, plyr);
        if (is_touching_border(shoot_positions.x, shoot_positions.y) == 1 ||
            colisioin_box_mob(plyr->weapon->colision_b, mob) == 1)
            window->speed = 0;
        sfRenderWindow_drawSprite(window->window, plyr->weapon->bullet, NULL);
        sfRenderWindow_drawRectangleShape(window->window,
            plyr->weapon->colision_b, NULL);
    }
    if ((plyr->weapon->status == GUN || plyr->weapon->status == SPELL) &&
        window->speed == 0) {
        sfSprite_setRotation(plyr->weapon->bullet, plyr->angle);
        sfRectangleShape_setRotation(plyr->weapon->colision_b, plyr->angle);
    }
}

void poll_event(map_t *map, window_t *window, hero_t *plyr, hero_t *mob)
{
    sfEvent event;
    sfVector2f shoot_positions;

    if ((plyr->weapon->status == GUN || plyr->weapon->status == SPELL)) {
        if (window->speed == 0)
            sfSprite_setPosition(plyr->weapon->bullet,
                (sfVector2f){plyr->posx, plyr->posy});
        shoot_positions = sfSprite_getPosition(plyr->weapon->bullet);
    }
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            break;
        }
        change_arms(window, plyr);
        if (event.type == sfEvtMouseButtonPressed)
            mouse_button_press(event, window, plyr);
    }
    poll_event2(shoot_positions, plyr, window, mob);
}
