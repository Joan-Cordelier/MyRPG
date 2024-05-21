/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, __attribute__((unused)) char **av)
{
    window_t *window = init_window(1920, 1080, 60, "My_RPG");

    if (ac == 1) {
        menu_prcp(window);
        return 0;
    }
    return 0;
}
