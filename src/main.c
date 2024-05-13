/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

static char *get_login(char **env)
{
    int i = 0;
    int j;
    char *username = NULL;

    for (; strncmp(env[i], "USERNAME", 8) != 0; i++);
    username = malloc(sizeof(char) * (strlen(env[i]) - 8));
    for (j = 9; env[i][j] != '\0'; j++)
        username[j - 9] = env[i][j];
    username[j - 9] = '\0';
    return username;
}

int main(int ac, char **av)
{
    window_t *window = init_window(1920, 1080, 60, "My_RPG");
    sfEvent event;

    if (ac == 1) {
        menu_prcp(window, NULL, event);
        return 0;
    }
    return 0;
}
