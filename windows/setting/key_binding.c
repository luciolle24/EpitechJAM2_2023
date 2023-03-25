/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** key_binding
*/

#include "my_rpg.h"

static int key_event(sfRenderWindow *win)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed)
            return event.text.unicode;
    }
    return -42;
}

int get_key_binding(sfRenderWindow *win)
{
    int key = -42;

    while (key == -42) {
        key = key_event(win);
    }
    return key;
}
