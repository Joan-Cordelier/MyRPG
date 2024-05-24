/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** menu
*/

#include "my.h"

void handle_exit_button_click(button_t *button, sfRenderWindow *window)
{
    if (strcmp(button->name, "Exit") == 0 && button->state == CLICKED) {
        sfRenderWindow_close(window);
    }
}

void render_buttons(sfRenderWindow *window,
    button_t **buttons, size_t button_count)
{
    for (size_t i = 0; i < button_count; ++i) {
        sfRenderWindow_drawText(window, buttons[i]->text, NULL);
    }
}

button_t **create_menu_buttons(sfFont *font)
{
    button_t **buttons = malloc(5 * sizeof(button_t *));

    if (!buttons) {
        return NULL;
    }
    buttons[0] = create_button("Play", (sfVector2f){100, 100}, font);
    buttons[1] = create_button("Load", (sfVector2f){100, 200}, font);
    buttons[2] = create_button("Settings", (sfVector2f){100, 300}, font);
    buttons[3] = create_button("How to Play", (sfVector2f){100, 400}, font);
    buttons[4] = create_button("Exit", (sfVector2f){100, 500}, font);
    return buttons;
}
