/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** split_map
*/

#include "my_rpg.h"

static void put_rec(char **map, sfVector2i pos, size_t height, char c);

void split_map(char **map, size_t width, size_t height)
{
    sfVector2i pos = {2, 2};

    put_rec(map, pos, height, '1');
    pos.x = width - 3;
    pos.y = height - 3;
    put_rec(map, pos, height, '2');
}

static void put_rec(char **map, sfVector2i pos, size_t height, char c)
{
    if (pos.x < 0 || pos.y < 0 || pos.y >= height || map[pos.y][pos.x] != ' ')
        return;
    map[pos.y][pos.x] = c;
    pos.x -= 1;
    put_rec(map, pos, height, c);
    pos.x += 2;
    put_rec(map, pos, height, c);
    pos.x -= 1;
    pos.y += 1;
    put_rec(map, pos, height, c);
    pos.y -= 2;
    put_rec(map, pos, height, c);
}
