/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** event
*/

#include "my.h"

void poll_event(sfEvent event, window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            break;
        }
    }
}
