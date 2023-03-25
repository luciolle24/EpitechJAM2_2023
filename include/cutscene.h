/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** cutscene
*/

#ifndef CUTSCENE_H_
    #define CUTSCENE_H_
    #include "my_rpg.h"

// *****************************************
// *        CUTSCENES STRUCTURES           *
// *****************************************
typedef struct cutscene {
    char *background;
    char *dialogues;
    int id;
    struct cutscene *next;
    int exit;
} cutscene_t;

typedef struct ret_values {
    int talking;
    int counter;
} ret_values_t;
// *****************************************
// *        CUTSCENES FUNCTIONS            *
// *****************************************
// \brief open file and sets it as a linked_list
cutscene_t *open_file(char *filename);
// \brief prints the cutscene
void cutsc_print(cutscene_t *cut, sfRenderWindow *win, sfRectangleShape **spr,
sfFont *font);
// \brief creates all the character models
sfRectangleShape **init_character(void);
// \brief prints the character
void print_character(int id, sfRenderWindow *win, sfRectangleShape **sprite);
// \brief prints the character name
void print_character_name(int id, sfRenderWindow *win,  sfFont *font);
// \brief Generates cutscenes based on a text file (no player needed)
void cutscene_gen_noplayer(game_setting_t *game,  char *id, sfRenderWindow *win,
sfFont *font);
// \brief Generates cutscenes based on a text file
void cutscene_gen(game_setting_t *game, char *id, sfRenderWindow *win,
sfFont *font);
// \brief generates cutscene values
ret_values_t *init_cutcene_values(void);
// \brief Fress all the cutscene
void free_cutscene(cutscene_t *cutscene);
// \brief Prints the text into a nice rpg style
void print_text_nice(char *str, sfRenderWindow *win, sfFont *font);
// \brief Creates a text object for the cutscene
sfText *create_text_cutsn(char *str, sfFont *font);
// \brief creates the text box
sfRectangleShape *create_txt_box(void);
#endif /* !CUTSCENE_H_ */
