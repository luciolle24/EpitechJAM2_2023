/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** display
*/

#include "game.h"

static void put_map(sfRectangleShape ***map_tiles, sfRenderWindow *window)
{
    for (size_t y = 0; map_tiles[y] != NULL; y++)
        for (size_t x = 0; map_tiles[y][x] != NULL; x++)
            sfRenderWindow_drawRectangleShape(window, map_tiles[y][x], NULL);
}

void display_game(sfRenderWindow *window, core_game_t game)
{
    sfClock *clock = game.clock;

    sfRenderWindow_setView(window, game.view);
    sfRenderWindow_clear(window, sfBlack);
    put_map(game.map_tiles, window);
    update_characters(game.characters, window, game.clock, game.view);
    display_npc(game.pnj, window);
    sfRenderWindow_display(window);
    *get_time_elapsed() += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfClock_restart(clock);
}
