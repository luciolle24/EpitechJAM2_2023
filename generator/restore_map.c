/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** restore_map
*/

#include "my_rpg.h"

void restore_map(char **map, size_t width, size_t height)
{
    char c;

    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            c = map[y][x];
            map[y][x] = (c == '1' || c == '2') ? ' ' : c;
        }
    }
}
