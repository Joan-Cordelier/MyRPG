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
    #include <string.h>
int move_player(int *x, int *y, int speed);
sfRenderWindow *create_window(unsigned int x, unsigned int y,
    unsigned int frame, char *title);
int my_strncmp(char const *s1, char const *s2, int n);
void menu_prcp(window_t *window, char *file, sfEvent event);
void event_close(window_t *window, sfEvent event);
void my_putstr(char *str);
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
    show s);
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
option_t *add_button(char *image, sfVector2f pos, char *name, show s);
#endif
