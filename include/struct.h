/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT
    #define STRUCT
typedef enum {
    NONE,
    PRESSED,
    HOVER,
    CLICKED
} states_t;

typedef enum {
    SHOW,
    HIDE,
} show_t;

typedef struct canva_s {
    sfRectangleShape *rect;
    sfImage *image;
    sfTexture *texture;
} canva_t;

typedef struct button_s {
    char *name;
    sfRectangleShape *rect;
    sfColor init_color;
    sfColor hover;
    sfColor clicked;
    sfSprite *sprite;
    sfTexture *texture;
    states_t state;
    show_t s;
} button_t;

typedef struct rect_s {
    char *name;
    sfRectangleShape *rect;
    struct rect_s *next;
} rect_t;

typedef struct option_s {
    button_t *button;
    struct option_s *prev;
    struct option_s *next;
} option_t;

typedef struct window_s {
    sfRenderWindow *window;
    unsigned int x;
    unsigned int y;
    unsigned int frame;
    int speed;
    int change;
    sfVector2i button_positions;
    sfVector2i pos;
    sfVector2i pos2;
    char *login;
} window_t;

typedef struct pencil_s {
    sfRectangleShape *rect;
    int x0;
    int x1;
    int y0;
    int y1;
    int size;
    int r;
    int g;
    int b;
    sfText *n_r;
    sfText *n_g;
    sfText *n_b;
    states_t s;
    sfColor color;
} pencil_t;

typedef struct weapon_s {
    int dega;
    int speed;
    sfTexture *texture;
    sfSprite *sprite;
} weapon_t;

typedef struct stat_s {
    int life;
    int end;
    int weap_hnd;
    int nb_fiol;
    int mana;
    int niv;
    int lv_sword;
    int lv_shotgun;
    int lv_magie;
} stat_t;

typedef struct hero_s {
    sfClock *anim;
    sfClock *endspe;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texHP;
    sfSprite *spHP;
    sfTexture *texStam;
    sfSprite *spStam;
    sfTexture *texMan;
    sfSprite *spMan;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfIntRect recHP;
    sfIntRect recStam;
    sfIntRect recMan;
    sfView *run;
    stat_t *player;
    weapon_t *arme;
    float angle;
    int viewx;
    int viewy;
    int posx;
    int posy;
} hero_t;

#endif
