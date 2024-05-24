/*
** EPITECH PROJECT, 2024
** loading
** File description:
** loading
*/

#include "my.h"

int load_time(sfSprite *loading, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    float seconds = 0;
    sfTime elapsed;

    while (seconds <= 2.0) {
        sfRenderWindow_drawSprite(window, loading, NULL);
        elapsed = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(elapsed);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
    return 0;
}

void my_loading(sfRenderWindow *window)
{
    sfTexture *loadingTexture = sfTexture_createFromFile("sprite/loading.png", NULL);
    sfSprite *loading = sfSprite_create();
    
    sfSprite_setScale(loading, (sfVector2f){1, 1});
    sfSprite_setTexture(loading, loadingTexture, sfTrue);
    load_time(loading, window);
    sfSprite_destroy(loading);
    sfTexture_destroy(loadingTexture);
}
