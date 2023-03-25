/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** quit
*/

#include "my_rpg.h"

static void init_quit_button(sfRectangleShape *sprite)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 610;
    pos.y = 750;
    size.x = 700;
    size.y = 100;
    sfRectangleShape_setOutlineThickness(sprite, 3);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
}

static void init_quit_text(sfText *text, char *sentence)
{
    sfVector2f pos;

    pos.x = 880;
    pos.y = 770;
    sfText_setString(text, sentence);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
}

void init_quit_settings(settings_elem_t elem)
{
    init_quit_button(elem.quit_button.pict);
    init_quit_text(elem.quit_button.text, "BACK");
}
