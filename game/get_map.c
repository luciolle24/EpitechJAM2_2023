/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** get_map
*/

#include "game.h"

static sfRectangleShape *get_tile(char **map, list_t *images, size_t x, \
size_t y);

sfRectangleShape ***get_map_tiles(list_t *images, char ***map)
{
    size_t width = 100;
    size_t height = 100;
    sfRectangleShape ***map_tiles = malloc(sizeof(*map_tiles) * (height + 1));

    *map = init_game_data(width, height);
    for (size_t y = 0; y < height; y++) {
        map_tiles[y] = malloc(sizeof(*map_tiles[y]) * (width + 1));
        for (size_t x = 0; x < width; x++)
            map_tiles[y][x] = get_tile(*map, images, x, y);
        map_tiles[y][width] = NULL;
    }
    map_tiles[height] = NULL;
    return (map_tiles);
}

static sfRectangleShape *get_tile(char **map, list_t *images, size_t x, \
size_t y)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f scale = {1, 1};
    sfVector2f size = {200, 200};
    sfVector2f pos = {x * size.x, y * size.y};
    sfTexture *texture = get_texture_from_char(map, images, x, y);

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setTexture(shape, texture, sfFalse);
    sfRectangleShape_setScale(shape, scale);
    sfRectangleShape_setSize(shape, size);
    return (shape);
}
