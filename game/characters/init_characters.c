/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_characters
*/

#include "game.h"

list_t *init_characters(sfView *view, char **map)
{
    list_t *characters = NULL;

    characters = add_data_to_list_start(characters, init_player(view));
    init_monsters(&characters, map);
    return (characters);
}
