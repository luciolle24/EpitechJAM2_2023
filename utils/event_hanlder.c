/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** cutscene_event
*/

#include "my_rpg.h"

int check_if_keypressed_ct(sfRenderWindow *win)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            return (1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (2);
        if (event.type == sfEvtClosed)
            return (3);
    }
    return (0);
}
