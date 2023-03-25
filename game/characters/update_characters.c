/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** update_characters
*/

#include "game.h"

void update_characters(list_t *characters, sfRenderWindow *window, \
sfClock *clock, sfView *view)
{
    update_player((character_t *)characters->data, window, clock, view);
    update_monsters(characters->next, window);
}
