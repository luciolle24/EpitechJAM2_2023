/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_game_data
*/

#include "game.h"

char **init_game_data(size_t width, size_t height)
{
    char **map = generate_map(width, height);
    sfClock *clock = sfClock_create();
    int seed = sfClock_getElapsedTime(clock).microseconds % 100;

    sfClock_destroy(clock);
    srand(seed);
    apply_map(map, width, height);
    return (map);
}
