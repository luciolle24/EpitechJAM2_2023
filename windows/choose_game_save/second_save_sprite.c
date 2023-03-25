/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** second_save_sprite
*/

#include "my_rpg.h"

static void init_second_back(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 666;
    pos.y = 45;
    size.x = 580;
    size.y = 760;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_second_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 775;
    pos.y = 350;
    size.x = 340;
    size.y = 100;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_second_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 790;
    pos.y = 370;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
}

void init_second_save(choose_save_t elem)
{
    init_second_back(elem.back_save_2.pict);
    init_second_button(elem.new_save_2.pict);
    init_second_button(elem.done_save_2.pict);
    init_second_text(elem.new_save_2.text, "NEW GAME");
    init_second_text(elem.done_save_2.text, "CONTINUE");
}
