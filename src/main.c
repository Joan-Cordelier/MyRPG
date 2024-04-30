/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

int expl_game(char *av, int i)
{
    if (av[i + 1] == 'h') {
        write(1, "USAGE\n\t./my paint\n", 19);
        write(1, "DESCRIPTION\n\tA reproduction of the Paint application\n",
            strlen("DESCRIPTION\n\tA reproduction of the Paint application\n"));
        write(1, "---> Created by Léon and Mike <---\n", strlen("---> Created by Léon and Mike <---\n"));
        return 0;
    } else
        return 84;
}

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

int main(int ac, char **av, char **env)
{
    window_t *window = init_window(1920, 1080, 60, "My_RPG");
    sfEvent event;

    //window->login = get_login(env);
    if (ac == 1) {
        menu_prcp(window, NULL, event);
        return 0;
    }
    /*&for (int i = 0; av[1][i]; i++) {
        if (av[1][i] == '-') {
            return expl_game(av[1], i);
        }
    }*/
    //menu_prcp(window, av[1], event);
    //free(window->login);
    return 0;
}
