/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** interact
*/

#include "my_rpg.h"

static void init_key_move_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 592;
    pos.y = 505;
    size.x = 50;
    size.y = 50;
    sfRectangleShape_setOutlineThickness(sprite, 3);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_key_move_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 610;
    pos.y = 515;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}


static void init_interract_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 242;
    pos.y = 507;
    size.x = 200;
    size.y = 50;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_interract_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 245;
    pos.y = 515;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

void init_interract(settings_elem_t elem, game_setting_t *setting)
{
    char *letter = letter_to_string(setting->player_id);

    init_key_move_button(elem.key_interact.pict);
    init_key_move_text(elem.key_interact.text, letter);
    free(letter);
    init_interract_button(elem.interact.pict);
    init_interract_text(elem.interact.text, "Choose Player");
}
