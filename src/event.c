/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** event
*/

#include "my.h"
#include <math.h>


static void shoot_gun(sfVector2f shoot_positions, window_t *window,
    sfSprite *shoot)
{
    shoot_positions.x = shoot_positions.x + window->button_positions.x;
    shoot_positions.y = shoot_positions.y + window->button_positions.y;
    sfSprite_setPosition(shoot,
        (sfVector2f){shoot_positions.x, shoot_positions.y});
}

static sfVector2i attack(int change, window_t *window,
    sfSprite *shoot, hero_t *plyr)
{
    sfVector2f shoot_positions = sfSprite_getPosition(shoot);
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

static void mouse_button_press(sfEvent event, window_t *window, hero_t *plyr,
    sfSprite *shoot)
{
    if (event.mouseButton.button == sfMouseLeft && window->speed != 1) {
        window->button_positions = attack(window->change, window, shoot, plyr);
        sfSprite_setTextureRect(plyr->spMan, plyr->recMan);
    }
}

sfSprite *poll_event(map_t *map, window_t *window, hero_t *plyr,
    sfSprite *shoot)
{
    sfVector2f shoot_positions = sfSprite_getPosition(shoot);
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed)
            mouse_button_press(event, window, plyr, shoot);
    }
    if (window->speed > 0) {
        shoot_gun(shoot_positions, window, shoot);
        if (shoot_positions.x >= 5760 || shoot_positions.x <= 0 ||
            shoot_positions.y >= 3240 || shoot_positions.y <= 0) {
            window->speed = 0;
        }
        sfRenderWindow_drawSprite(window->window, shoot, NULL);
    }
    return shoot;
}
