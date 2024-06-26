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

int my_putstr(char const *str);

//colision.c
void colision(hero_t *mob, hero_t *plyr, map_t *map);
int is_touching(int x, int y, int **txt_map);
int is_touching_border(int x, int y);
map_t *map_colision(window_t *window, hero_t *plyr, map_t *map, hero_t *mob);

//colision_box.c
int colisioin_box_mob(sfRectangleShape *box, hero_t *mob);

//csfml_utils.c
sfVector2i mouse(sfRenderWindow *window);
sfSprite *fond(char *file, float x, float y);

//csfml.c
void menu_prcp(window_t *window);
void move_rect(sfIntRect *rect, int offset, int max, int i);
void set_mob_back_shoot(hero_t *mob, hero_t *plyr, map_t *map);

//csfml2.c
void destroy_sprites(sfSprite *mob, sfSprite *back);
void moove_and_set(hero_t *plyr, map_t *map);
void move_anim(hero_t *cible, int n);

//death.c
void dead_hero(hero_t *hero, map_t *map);
void dead_mob(hero_t *hero, map_t *map);

//event.c
void poll_event(map_t *map, window_t *window, hero_t *plyr, hero_t *mob);

//init_pnj.c
void init_pnj_null(map_t *map);
void check_status(pnj_t *pnj, hero_t *hero);
void init_pnj_cave(map_t *map);

//loading.c
void my_loading(sfRenderWindow *window, hero_t *plyr);

//map_utils.c
void init_map(map_t *map);
char **my_str_to_word_array(char *str, char *end);
char *open_read(const char *path);
void set_rect(sfRectangleShape *rect, int x, int y);

//mooves_mobs.c
void moove_squeleton(hero_t *plyr, hero_t *mob, map_t *map);

//player.c
void init_player(hero_t *player);
int set_move(hero_t *plyr, map_t *map);

//pnj.c
hero_t *init_hero(char *file, int x, int y, int status);

//print_inventaire.c
void set_inventaire(hero_t *plyr);
void print_inventaire(window_t *window, hero_t *plyr);
void set_rect_inv(sfRectangleShape *rect, int x, int y);

//sword_hit.c
void sword_hit(hero_t *plyr, hero_t *mob, map_t *map, int change);
void sword_hit_mob(hero_t *plyr, hero_t *mob, map_t *map, int change);
void hero_xp(hero_t *hero);
void level_up(hero_t *plyr);

//sword_rotate.c
void rotate_png(hero_t *plyr, sfVector2i button_positions);
void rotate_mob(hero_t *plyr, hero_t *mob);
float sword_rotate(hero_t *plyr, sfVector2i button_positions);

//weapon.c
void init_weapon(hero_t *hero);

//window.c
sfRenderWindow *create_window(unsigned int x, unsigned int y,
    unsigned int frame, char *title);
window_t *init_window(unsigned int x, unsigned int y, int frame, char *title);
void aply_change_hit(hero_t *plyr, hero_t *mob, map_t *map, weapon_t *weapon);
void handle_exit_button_click(button_t *button, window_t *window);
void render_buttons(window_t *window,
    button_t **buttons, size_t button_count);
button_t *create_button(const char *name, sfVector2f position, sfFont *font);
void handle_events(window_t *window, button_t **buttons, size_t button_count);
void cleanup(button_t **buttons, size_t button_count);
button_t **create_menu_buttons(sfFont *font);
void display_main_menu(window_t *window);



#endif
