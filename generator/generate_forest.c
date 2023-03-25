/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** generate_forest
*/

#include "my_rpg.h"

static void add_circle(char **map, vector2ul_t size, vector2ul_t pos, \
int radius);

void add_forest(char **map, size_t width, size_t height)
{
    int nbr = rand() % 30 + 15;
    vector2ul_t size = {width, height};
    vector2ul_t pos = {0};

    for (int i = 0; i < nbr; i++) {
        pos.x = rand() % width;
        pos.y = rand() % height;
        add_circle(map, size, pos, width / 20);
    }
}

static void add_circle(char **map, vector2ul_t size, vector2ul_t pos, \
int radius)
{
    int is_not_in_map = pos.x < 2 || pos.x > size.x - 2;
    char c = map[pos.y][pos.x];

    is_not_in_map = is_not_in_map || pos.y < 2 || pos.y > size.y - 2;
    if (radius < 1 || is_not_in_map || c == 'a' || c == 'o' || c == 'x')
        return;
    radius -= rand() % 3;
    map[pos.y][pos.x] = 'a';
    pos.x -= 1;
    add_circle(map, size, pos, radius);
    pos.x += 2;
    add_circle(map, size, pos, radius);
    pos.y += 1;
    pos.x -= 1;
    add_circle(map, size, pos, radius);
    pos.y -= 2;
    add_circle(map, size, pos, radius);
}
