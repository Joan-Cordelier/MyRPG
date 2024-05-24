/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"
#include <stdio.h>

int create_login_file(char *path)
{
    int file = open(path, O_CREAT | O_WRONLY, 0644);

    if (file == -1) {
        return 84;
    }
    write(file, path, sizeof(char) * strlen(path));
    close(file);
}

void login(char *str, int create)
{
    char *login = NULL;
    size_t buffsize = 0;
    int size = 0;

    if (create == false)
        login = open_read(str);
    else {
        printf("Enter your login: ");
        size = getline(&login, &buffsize, stdin);
        login[strlen(login) - 1] = '\0';
        create_login_file(login);
    }
    printf("You are log as: %s\n", login);
}

int main(int ac, __attribute__((unused)) char **av)
{
    window_t *window = NULL;

    if (ac == 2) {
        login(av[1], false);
        window = init_window(1920, 1080, 60, "My_RPG");
        my_loading(window->window, NULL);
        display_main_menu(window);
        return 0;
    }
    if (ac == 1) {
        login(NULL, true);
        window = init_window(1920, 1080, 60, "My_RPG");
        my_loading(window->window, NULL);
        display_main_menu(window);
        return 0;
    }
    return 0;
}
