/*
** EPITECH PROJECT, 2024
** loading
** File description:
** loading
*/

#include "my.h"

int load_time(sfSprite *loading, sfRenderWindow *window, hero_t *player)
{
    sfClock *clock = sfClock_create();
    float seconds = 0;
    sfTime elapsed;

    while (seconds <= 0.5) {
        if (player != NULL) {
            sfSprite_setPosition(loading,
                (sfVector2f){player->posx - 950, player->posy - 500});
        }
        sfRenderWindow_drawSprite(window, loading, NULL);
        elapsed = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(elapsed);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
    return 0;
}

void my_loading(sfRenderWindow *window, hero_t *player)
{
    sfTexture *loadingTexture = sfTexture_createFromFile("sprite/loading.png",
        NULL);
    sfSprite *loading = sfSprite_create();

    sfSprite_setScale(loading, (sfVector2f){1.92, 1.08});
    sfSprite_setTexture(loading, loadingTexture, sfTrue);
    sfSprite_setOrigin(loading, (sfVector2f){0, 0});
    load_time(loading, window, player);
    sfSprite_destroy(loading);
    sfTexture_destroy(loadingTexture);
}
