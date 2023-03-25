/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** move_up
*/

#include "my_rpg.h"

static void init_key_move_up_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 592;
    pos.y = 105;
    size.x = 50;
    size.y = 50;
    sfRectangleShape_setOutlineThickness(sprite, 3);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_key_move_up_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 610;
    pos.y = 115;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

static void init_move_up_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 242;
    pos.y = 107;
    size.x = 200;
    size.y = 50;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_move_up_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 260;
    pos.y = 115;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

void init_move_up(settings_elem_t elem, game_setting_t *setting)
{
    char *letter = letter_to_string(setting->move_up);

    init_key_move_up_button(elem.key_move_up.pict);
    init_key_move_up_text(elem.key_move_up.text, letter);
    free(letter);
    init_move_up_button(elem.move_up.pict);
    init_move_up_text(elem.move_up.text, "MOVE UP");
}
