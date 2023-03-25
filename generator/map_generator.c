/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** map_generator
*/

#include "my_rpg.h"

static void clear_map(char **map, size_t width, size_t height);

char **generate_map(size_t width, size_t height)
{
    char **map = malloc(sizeof(char *) * (height + 1));

    for (size_t i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 1));
        for (size_t j = 0; j < width; j++)
            map[i][j] = '*';
        map[i][width] = '\0';
    }
    map[height] = NULL;
    return (map);
}

void put_map_char(char **map)
{
    for (size_t y = 0; map[y] != NULL; y++) {
        for (size_t x = 0; map[y][x] != '\0'; x++)
            my_put_char(map[y][x]);
        my_put_char('\n');
    }
}

void destroy_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++)
        free(map[y]);
    free(map);
}

char **apply_map(char **map, size_t width, size_t height)
{
    clear_map(map, width, height);
    add_river(map, width, height);
    split_map(map, width, height);
    add_forest(map, width, height);
    add_cities(map, width, height);
    add_bridge(map, width, height);
    restore_map(map, width, height);
    return (map);
}

static void clear_map(char **map, size_t width, size_t height)
{
    int is_border = 0;

    for (size_t y = 0; map[y] != NULL; y++) {
        for (size_t x = 0; map[y][x] != '\0'; x++) {
            is_border = x == 0 || x == width - 1 || y == 0 || y == height - 1;
            is_border = is_border || x == 1 || x == width - 2;
            is_border = is_border || y == 1 || y == height - 2;
            map[y][x] = (is_border) ? 'x' : ' ';
        }
    }
}
