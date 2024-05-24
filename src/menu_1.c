/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** menu_1
*/

#include "my.h"

void handle_button_events(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect button_rect = sfText_getGlobalBounds(button->text);

    if (!sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
        button->state = NONE;
        sfText_setColor(button->text, sfWhite);
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->state = CLICKED;
        handle_exit_button_click(button, window);
    } else {
        button->state = HOVER;
        sfText_setColor(button->text, sfYellow);
    }
}

button_t *create_button(const char *name, sfVector2f position, sfFont *font)
{
    button_t *button = malloc(sizeof(button_t));

    button->name = strdup(name);
    button->state = NONE;
    button->text = sfText_create();
    sfText_setString(button->text, name);
    sfText_setFont(button->text, font);
    sfText_setCharacterSize(button->text, 50);
    sfText_setPosition(button->text, position);
    sfText_setColor(button->text, sfWhite);
    return button;
}

void handle_events(window_t *window, button_t **buttons, size_t button_count)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
        }
    }
    for (size_t i = 0; i < button_count; ++i) {
        handle_button_events(buttons[i], window->window);
    }
}

void cleanup(button_t **buttons, size_t button_count)
{
    for (size_t i = 0; i < button_count; ++i) {
        if (buttons[i]->text) {
            sfText_destroy(buttons[i]->text);
        }
        free(buttons[i]->name);
        free(buttons[i]);
    }
}

void display_main_menu(window_t *window)
{
    sfFont *font = sfFont_createFromFile("OldLondon.ttf");
    button_t **buttons = create_menu_buttons(font);
    size_t button_count = 5;

    if (!buttons) {
        printf("Failed to create buttons\n");
        sfFont_destroy(font);
        return;
    }
    while (sfRenderWindow_isOpen(window->window)) {
        handle_events(window, buttons, button_count);
        sfRenderWindow_clear(window->window, sfBlack);
        render_buttons(window->window, buttons, button_count);
        sfRenderWindow_display(window->window);
    }
    cleanup(buttons, button_count);
    sfFont_destroy(font);
}
