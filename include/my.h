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
int my_strncmp(char const *s1, char const *s2, int n);
void menu_prcp(window_t *window, char *file, sfEvent event);
void event_close(window_t *window, sfEvent event);
int my_putstr(char const *str);
sfText *init_text_size(void);
char *my_itoa(int value);
void update_text_size(sfText *text, pencil_t *pencil);
void login_window(char *login);
void folder_op(option_t *t, canva_t *board,
    window_t *window);
void display_rgb_text(window_t *window, pencil_t *pencil);
void destroy_func(option_t *t, canva_t *board, sfRectangleShape *rect,
    sfClock *clock);
void destroy_func2(pencil_t *pencil, sfText *t);
button_t *init_folder_button(char *image, sfVector2f pos, char *name,
    show_t s);
void help_hover(option_t *t, window_t *window);
void size_op(option_t *t, pencil_t *);
void color_op(option_t *t, pencil_t *);
void help_window(void);
void help_op(option_t *t, window_t *);
void help_off(option_t *t);
void folder_off(option_t *t);
void folder_hover(option_t *t, window_t *window);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);;
window_t *init_window(unsigned int x, unsigned int y, int frame, char *title);
canva_t *init_canva(sfRenderWindow *window, char *file);
sfVector2i get_mouse_pos(sfRenderWindow *window);
sfImage *init_image(sfRenderWindow *window);
sfImage *init_image_file(sfRenderWindow *window, char *file);
void draw_on_board(pencil_t *pencil, canva_t *board, window_t
    *window, sfText *);
pencil_t *init_pencil(void);
int is_button_clicked(button_t *button, pencil_t *pencil);
sfBool is_button_hover(button_t *button, pencil_t *pencil);
pencil_t *get_pos(pencil_t *mouse_pos, sfRenderWindow *window);
option_t *all_button(void);
void update_last_pos(pencil_t **pencil, window_t *window);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
void edition_hover(option_t *t, window_t *window);
void edition_off(option_t *t);
void set_color(pencil_t *pencil);
option_t *add_button(char *image, sfVector2f pos, char *name, show_t s);
float sword_rotate(hero_t *plyr, window_t *window,
    sfVector2i button_positions);
sfSprite *poll_event(sfEvent event, window_t *window, hero_t *plyr,
    sfSprite *sword);

//csfml_utils.c
sfVector2i mouse(sfRenderWindow *window);
sfSprite *fond(char *file, float x, float y);
sfSprite *change_arms(sfSprite *sword, char **arms,
    int *change);

//csfml2.c
void destroy_sprites(sfSprite *mob, sfSprite *shoot, sfSprite *back);
void moove_and_set(hero_t *plyr, sfEvent event, window_t *window);
void move_anim(hero_t *cible);

void init_player(hero_t *player);

#endif
