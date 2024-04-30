/*
** EPITECH PROJECT, 2023
** play_game
** File description:
** play_game
*/

#include "my.h"

hero_t *skull_head(void)
{
    hero_t *cible = malloc(sizeof(hero_t));
    sfVector2f scale = {2, 2};
    sfVector2f pos = {- 300.0, (rand() % 800)};

    srand(time(NULL));
    cible->texture = sfTexture_createFromFile
        ("picture/enemie3.png", NULL);
    cible->sprite = sfSprite_create();
    cible->scale = scale;
    cible->pos = pos;
    cible->rect.top = 0;
    cible->rect.left = 0;
    cible->rect.width = 127;
    cible->rect.height = 93;
    sfSprite_setTexture(cible->sprite, cible->texture, sfTrue);
    sfSprite_setScale(cible->sprite, cible->scale);
    sfSprite_setPosition(cible->sprite, cible->pos);
    return cible;
}

static sfSprite *fond2(void)
{
    sfTexture *texture = sfTexture_createFromFile("picture/fond2.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

static void destr(sfEvent event, enm *cible)
{
    if (event.type == sfEvtMouseButtonPressed) {
        srand(time(NULL));
        cible->pos.y = rand() % 800;
        sfSprite_setPosition(cible->sprite, cible->pos);
    }
}

static void kill_enm(sfVector2f position, sfEvent event
    , sfRenderWindow *window, enm *cible)
{
    sfVector2f enm_pos = position;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= enm_pos.x && mouse_pos.x <= (enm_pos.x + 160)) {
        if (mouse_pos.y >= enm_pos.y && mouse_pos.y <= (enm_pos.y + 200)) {
            destr(event, cible);
        }
    }
}

void move_rect(sfIntRect *rect, int offset, int max)
{
        rect->left += offset;
        if (rect->left >= max)
            rect->left = 0;
}

static void move_anim(sfClock *clock, enm *cible)
{
    sfTime clock_espl;

    clock_espl = sfClock_getElapsedTime(clock);
    if (clock_espl.microseconds > 100000) {
        sfSprite_setTextureRect(cible->sprite, cible->rect);
        move_rect(&cible->rect, 127, 254);
        sfClock_restart(clock);
    }
}

static void move_enm(sfClock *clock02, enm *cible, sfRenderWindow *window)
{
    sfTime clock_espl02;
    sfVector2f vector = {0.5, 0};

    clock_espl02 = sfClock_getElapsedTime(clock02);
    if (clock_espl02.microseconds > 10) {
        sfSprite_move(cible->sprite, vector);
        sfRenderWindow_drawSprite(window, cible->sprite, NULL);
        sfClock_restart(clock02);
    }
}

int play_game(sfRenderWindow *window, sfEvent event)
{
    sfSprite *newback_ground = fond2();
    enm *cible = skull_head();
    sfClock *clock = sfClock_create();
    sfClock *clock02 = sfClock_create();
    int ga_ov = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, newback_ground, NULL);
        move_anim(clock, cible);
        move_enm(clock02, cible, window);
        kill_enm(sfSprite_getPosition(cible->sprite), event, window, cible);
        closer(&event, window);
        ga_ov = game_over(cible, clock, clock02, window);
        sfRenderWindow_display(window);
        if (ga_ov == -1)
            sfRenderWindow_close(window);
    }
    return 0;
}


sfRenderWindow_display(window->window);
        sfRenderWindow_pollEvent(window->window, &event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, back, NULL);
        sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
        move_anim(anim, plyr);
        sfRenderWindow_drawSprite(window->window, sword->sprite, NULL);