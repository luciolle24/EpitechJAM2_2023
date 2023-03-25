/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** move_down
*/

#include "my_rpg.h"

static void init_key_move_down_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 592;
    pos.y = 205;
    size.x = 50;
    size.y = 50;
    sfRectangleShape_setOutlineThickness(sprite, 3);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_key_move_down_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 610;
    pos.y = 215;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

static void init_move_down_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 242;
    pos.y = 207;
    size.x = 200;
    size.y = 50;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_move_down_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 235;
    pos.y = 215;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

void init_move_down(settings_elem_t elem, game_setting_t *setting)
{
    char *letter = letter_to_string(setting->move_down);

    init_key_move_down_button(elem.key_move_down.pict);
    init_key_move_down_text(elem.key_move_down.text, letter);
    free(letter);
    init_move_down_button(elem.move_down.pict);
    init_move_down_text(elem.move_down.text, "MOVE DOWN");
}
