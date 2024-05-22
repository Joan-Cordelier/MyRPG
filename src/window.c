/*
** EPITECH PROJECT, 2024
** window.c
** File description:
** window
*/

#include "my.h"

sfRenderWindow *create_window(unsigned int x, unsigned int y,
    unsigned int frame, char *title)
{
    sfVideoMode video_mode = {x, y, frame};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
        title, sfResize | sfClose, NULL);

    sfRenderWindow_setFramerateLimit(window, frame);
    return window;
}

window_t *init_window(unsigned int x, unsigned int y, int frame, char *title)
{
    window_t *window = malloc(sizeof(window_t));

    memset(window, 0, sizeof(window_t));
    window->window = create_window(x, y, frame, title);
    window->frame = frame;
    window->x = x;
    window->y = y;
    window->pos.x = 0;
    window->pos.y = 0;
    window->pos2 = (sfVector2i){sfRenderWindow_getSize(window->window).x,
        sfRenderWindow_getSize(window->window).y};
    return window;
}
