/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** csfml
*/

#include "my.h"

/* void closer(sfEvent *event, window_t **window, pencil_t **pencil)
{
    while (sfRenderWindow_pollEvent((*window)->window, event)) {
        if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close((*window)->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        if ((*pencil)->size != 100)
            (*pencil)->size++;
    if (sfKeyboard_isKeyPressed(sfKeyDown)){
        if ((*pencil)->size != 1)
            (*pencil)->size--;
    }
}

static void display_board(window_t *window, canva_t *board,
    sfRectangleShape *tools_bar, sfText *t)
{
    sfTexture_updateFromImage(board->texture, board->image, 0, 0);
    sfRectangleShape_setTexture(board->rect, board->texture, sfTrue);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawRectangleShape(window->window, tools_bar, NULL);
    sfRenderWindow_drawRectangleShape(window->window, board->rect, NULL);
    sfRenderWindow_drawText(window->window, t, NULL);
}

static void hover_func(option_t *t, window_t *window)
{
    folder_hover(t, window);
    edition_hover(t, window);
    help_hover(t, window);
}

static void off_func(option_t *t)
{
    folder_off(t);
    edition_off(t);
    help_off(t);
}

static void clicked_func(window_t *window, pencil_t *pencil, option_t *t,
    canva_t *board)
{
    folder_op(t, board, window);
    size_op(t, pencil);
    help_op(t, window);
    color_op(t, pencil);
}

static void display_buttons(window_t *window, pencil_t *pencil, option_t **op,
    canva_t *board)
{
    option_t *t = *op;

    while (t != NULL) {
        if (is_button_hover(t->button, pencil))
            hover_func(t, window);
        else
            off_func(t);
        if (is_button_clicked(t->button, pencil))
            clicked_func(window, pencil, t, board);
        if (t->button->s == SHOW) {
            sfRenderWindow_drawRectangleShape(window->window,
                t->button->rect, NULL);
            sfRenderWindow_drawSprite(window->window, t->button->sprite, NULL);
        }
        t = t->next;
    }
    sfRenderWindow_drawRectangleShape(window->window, pencil->rect, NULL);
    sfRenderWindow_display(window->window);
}

static sfRectangleShape *init_tool_bar(window_t *window)
{
    sfRectangleShape *tools_bar = sfRectangleShape_create();

    sfRectangleShape_setFillColor(tools_bar, sfColor_fromRGB(138, 138, 138));
    sfRectangleShape_setOutlineColor(tools_bar, sfBlack);
    sfRectangleShape_setOutlineThickness(tools_bar, 2);
    sfRectangleShape_setPosition(tools_bar, (sfVector2f){1, 0});
    sfRectangleShape_setSize(tools_bar, (sfVector2f)
    {sfRenderWindow_getSize(window->window).x,
        sfRenderWindow_getSize(window->window).y});
    return tools_bar;
} */

static sfSprite *fond(char *file)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {3, 3};
 
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void move_rect(sfIntRect *rect, int offset, int max)
{
    for (int n = 0; n <= 2; n++) {
       rect->left += offset;
        if (rect->left >= max)
           rect->left = 0;
    }
}

static void move_anim(sfClock *clock, hero_t *cible)
{
   sfTime clock_espl;
   clock_espl = sfClock_getElapsedTime(clock);
   if (clock_espl.microseconds > 100000) {
       sfSprite_setTextureRect(cible->sprite, cible->rect);
       move_rect(&cible->rect, 127, 254);
       sfClock_restart(clock);
   }
}

hero_t *hero(char *file, int x, int y)
{
   hero_t *cible = malloc(sizeof(hero_t));
   sfVector2f scale = {2, 2};
   sfVector2f pos = {960, 540};
   srand(time(NULL));
   cible->texture = sfTexture_createFromFile
       (file, NULL);
   cible->sprite = sfSprite_create();
   cible->scale = scale;
   cible->pos = pos;
   cible->rect.top = 0;
   cible->rect.left = 0;
   cible->rect.width = x;
   cible->rect.height = y;
   sfSprite_setTexture(cible->sprite, cible->texture, sfTrue);
   sfSprite_setScale(cible->sprite, cible->scale);
   sfSprite_setPosition(cible->sprite, cible->pos);
   return cible;
}

void menu_prcp(window_t *window, char *file, sfEvent event)
{
    /* canva_t *board = init_canva(window->window, file);
    pencil_t *pencil = init_pencil();
    sfRectangleShape *tools_bar = init_tool_bar(window);
    option_t *op = all_button();
    sfClock *clock = sfClock_create();
    sfText *text_size = init_text_size(); */
    sfSprite *back = fond("sprite/map.jpg");
    //hero_t *plyr = hero("sprite/hero_rpg/hero_rpg.png", 127, 93);
    hero_t *plyr = hero("sprite/hero_rpg/hero_rpg.png", 50, 50);
    hero_t *sword = hero("sprite/arme/epee-4.png", 200, 200);
    sfClock *anim = sfClock_create();
    sfSprite_setOrigin(plyr->sprite, (sfVector2f){75, 50});

    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_pollEvent(window->window, &event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, back, NULL);
        sfRenderWindow_drawSprite(window->window, plyr->sprite, NULL);
        sfRenderWindow_drawSprite(window->window, sword->sprite, NULL);
        //move_anim(anim, plyr);
        sfRenderWindow_display(window->window);
        /* if (sfClock_getElapsedTime(clock).microseconds * 240 / 1000000 > 1) {
            closer(&event, &window, &pencil);
            //pencil = get_pos(pencil, window->window);
            //draw_on_board(pencil, board, window, text_size);
            display_board(window, board, tools_bar, text_size);
            display_rgb_text(window, pencil);
            display_buttons(window, pencil, &op, board);
            sfClock_restart(clock);
        } */
    }
    // destroy_func(op, board, tools_bar, clock);
    // destroy_func2(pencil, text_size);
}
