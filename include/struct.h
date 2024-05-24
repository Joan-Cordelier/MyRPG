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
    NONE,
    HOVER,
    CLICKED
} button_state_t;

typedef struct {
    char *name;
    sfText *text;
    button_state_t state;
} button_t;

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
    sfSound *sounG;
    sfSoundBuffer *sounG2;
    int damage;
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

typedef struct inventaire_s {
    sfTexture *texIn;
    sfSprite *spIn;
    sfIntRect recIn;
    sfRectangleShape *epee;
    sfRectangleShape *gun;
    sfRectangleShape *fioleVie;
    sfRectangleShape *fioleMana;
} inventaire_t;

typedef struct hero_s {
    sfRectangleShape *colision;
    sfSound *songG;
    sfSoundBuffer *songG2;
    sfSound *songS;
    sfSoundBuffer *songS2;
    sfClock *anim;
    sfClock *endspe;
    sfClock *spatt;
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
    inventaire_t *inv;
    stat_t *player;
    weapon_t *weapon;
    sfTexture *texXP;
    sfSprite *spXP;
    sfIntRect recXP;
    sfSound *songXP;
    sfSoundBuffer *songXP2;
    sfClock *clockXP;
    int XP;
    float angle;
    int viewx;
    int viewy;
    int posx;
    int posy;
    bool Inv;
    bool moove;
    int status;
} hero_t;

typedef struct pnj_s {
    sfSprite *pnj;
    sfTexture *pnj_texture;
    sfFont* font;
    sfText* text;
    char **dialogue;
    int posx;
    int posy;
    int line;
    int status;
    bool talk;
} pnj_t;

typedef struct map_s {
    char *name;
    sfSprite *map;
    sfVector2f start_player;
    sfRectangleShape *exit_player_next;
    int is_next;
    sfRectangleShape *exit_player_prev;
    int is_prev;
    sfVector2f start_mob;
    sfSound *song;
    sfSoundBuffer *song2;
    sfClock *timeS;
    int rep;
    int **txt_map;
    struct pnj_s *pnj;
    struct map_s *next;
    struct map_s *prev;
} map_t;

#endif
