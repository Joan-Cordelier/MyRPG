/*
** EPITECH PROJECT, 2024
** MYH
** File description:
** MYH
*/

#ifndef MYH
    #define MYH
    #include "lib.h"
    #include "struct.h"
/*
** personage
*/
    #define LIFE 100
    #define END 100
    #define MANA 100
    #define MANA_REG 10 /*taux en pourcentage de régénération*/
    #define LIFE_REG 20 /*taux en pourcentage de régénération*/
    #define DEGAT_MOB 5
    #define NB_FIOL 4
    #define SPEED_W 5
    #define LEVEL_UP 2 /*taux de level up par niveaux, exemple: degats x2*/
/*
** arme
*/
    #define EPEE_1 1
    #define EPEE_2 2
    #define EPEE_3 3
    #define EPEE_4 4
    #define SHOTGUN 5
    #define MAGIE 6

hero_t *hero(char *file, int x, int y);
void rotate_png(hero_t *plyr, window_t *window,
    sfVector2i button_positions, sfSprite *sword);
int set_move(sfEvent event, window_t *window, hero_t *plyr);
int move_player(int *x, int *y, int speed);
sfRenderWindow *create_window(unsigned int x, unsigned int y,
    unsigned int frame, char *title);
void menu_prcp(window_t *window, char *file, sfEvent event);
int my_putstr(char const *str);
window_t *init_window(unsigned int x, unsigned int y, int frame, char *title);
float sword_rotate(hero_t *plyr, window_t *window,
    sfVector2i button_positions);
sfSprite *poll_event(sfEvent event, window_t *window, hero_t *plyr,
    sfSprite *sword);

//csfml_utils.c
sfVector2i mouse(sfRenderWindow *window);
sfSprite *fond(char *file, float x, float y);
sfSprite *change_arms(sfSprite *sword, char **arms,
    int *change);

//csfml.c
void move_rect(sfIntRect *rect, int offset, int max);

//csfml2.c
void destroy_sprites(sfSprite *mob, sfSprite *shoot, sfSprite *back);
void moove_and_set(hero_t *plyr, sfEvent event, window_t *window);
void move_anim(hero_t *cible);

void init_player(hero_t *player);

#endif
