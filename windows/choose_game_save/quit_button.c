/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** quit_button
*/

#include "my_rpg.h"

static void init_quit_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 590;
    pos.y = 850;
    size.x = 740;
    size.y = 100;
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_quit_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 880;
    pos.y = 870;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
}

void init_quit(choose_save_t elem)
{
    init_quit_button(elem.quit_button.pict);
    init_quit_text(elem.quit_button.text, "BACK");
}
