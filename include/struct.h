/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT
    #define STRUCT
    #include <stdbool.h>

enum {
    SET,
    DRAW
};

enum {
    PLAYER,
    SHOOT
};

typedef enum {
    SWORD,
    GUN,
    SPELL
} weapon_status_t;

typedef enum {
    PLYR,
    SQUELETON,
    BOSS,
    PNJ
} hero_status_t;

typedef struct rect_s {
    char *name;
    sfRectangleShape *rect;
    struct rect_s *next;
} rect_t;

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

typedef struct weapon_s {
    sfRectangleShape *colision_w;
    sfTexture *weapon_texture;
    sfSprite *weapon;
    sfRectangleShape *colision_b;
    sfTexture *bullet_texture;
    sfSprite *bullet;
    int dega;
    int speed;
    int status;
    struct weapon_s *prev;
    struct weapon_s *next;
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
    sfRectangleShape *colision;
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
    weapon_t *weapon;
    float angle;
    int viewx;
    int viewy;
    int posx;
    int posy;
    bool vie;
    int status;
} hero_t;

typedef struct rectangle_s {
    sfRectangleShape *rec;
    int status;
    struct rectangle_s *next;
    struct rectangle_s *prev;
} rectangle_t;

typedef struct map_s {
    char *name;
    sfSprite *map;
    sfVector2f start_player;
    sfRectangleShape *exit_player;
    sfVector2f start_mob;
    int **txt_map;
    struct rectangle_s *rectangle;
    struct map_s *next;
    struct map_s *prev;
} map_t;

#endif
