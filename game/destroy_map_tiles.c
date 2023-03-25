/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy_map_tiles
*/

#include "game.h"

void destroy_map_tiles(sfRectangleShape ***map_tiles)
{
    for (size_t y = 0; map_tiles[y] != NULL; y++) {
        for (size_t x = 0; map_tiles[y][x] != NULL; x++)
            sfRectangleShape_destroy(map_tiles[y][x]);
        free(map_tiles[y]);
    }
    free(map_tiles);
}
