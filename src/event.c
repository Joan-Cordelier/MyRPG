/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** event
*/

#include "my.h"
#include <math.h>


static void shoot_gun(sfVector2f shoot_positions, window_t *window, sfSprite *shoot)
{
    shoot_positions.x = shoot_positions.x + window->button_positions.x;
    shoot_positions.y = shoot_positions.y + window->button_positions.y;
    sfSprite_setPosition(shoot, (sfVector2f){shoot_positions.x, shoot_positions.y});
}

static sfVector2i attack(int change, window_t *window, sfSprite *shoot)
{
    sfVector2f shoot_positions = sfSprite_getPosition(shoot);
    float n = 0;
    float x = 0;
    float y = 0;

    if (change == 1) {
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

sfSprite *poll_event(sfEvent event, window_t *window, int change, sfSprite *shoot)
{
    sfVector2i button_positions;
    sfVector2f shoot_positions = sfSprite_getPosition(shoot);

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.button == sfMouseLeft && window->speed != 1) {
                window->button_positions = attack(change, window, shoot);
            }
        }
    }
    if (window->speed > 0) {
        shoot_gun(shoot_positions, window, shoot);
        if (shoot_positions.x >= 3000 || shoot_positions.x <= 0 || shoot_positions.y >= 3000 || shoot_positions.y <= 0) {
            window->speed = 0;
        }
        sfRenderWindow_drawSprite(window->window, shoot, NULL);
    }
    return shoot;
}
