/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** run_game
*/

#include "game.h"
#include "inventory.h"
#include "cutscene.h"

static void put_map(sfRectangleShape ***map_tiles, sfRenderWindow *window);
static void destroy_datas(list_t *images, sfRectangleShape ***map_tiles, \
sfView *view, list_t *characters);
static void run_beginig_ct(game_setting_t *game, sfRenderWindow *win,
sfFont *font);

core_game_t init_all_game(sfRenderWindow *window, game_setting_t *settings)
{
    core_game_t game;
    char **map = NULL;

    game.images = init_images();
    game.view = sfView_create();
    game.map_tiles = get_map_tiles(game.images, &map);
    game.characters = init_characters(game.view, map);
    game.clock = sfClock_create();
    game.font = sfFont_createFromFile("asset/utility/Avara.ttf");
    game.pnj = def_all_npc(game.view);
    ((character_t *)game.characters->data)->map = map;
    return game;
}

void run_game(sfRenderWindow *window, game_setting_t *settings, int id)
{
    core_game_t game = init_all_game(window, settings);
    int if_quit = 0;

    run_beginig_ct(settings, window, game.font);
    // sfView_setSize(game.view, (sfVector2f){1920, 1000});
    // while (sfRenderWindow_isOpen(window) && if_quit == 0) {
    //     if_quit = check_game_events(window, settings, game);
    //     display_game(window, game);
    // }
    // destroy_datas(game.images, game.map_tiles, game.view, game.characters);
    // sfClock_destroy(game.clock);
}

static void destroy_datas(list_t *images, sfRectangleShape ***map_tiles, \
sfView *view, list_t *characters)
{
    destroy_list(images, &destroy_image_list);
    destroy_map_tiles(map_tiles);
    sfView_destroy(view);
    destroy_player((character_t *)characters->data);
}

static void run_beginig_ct(game_setting_t *game, sfRenderWindow *win,
sfFont *font)
{
    cutscene_gen_noplayer(game, "1", win, font);
    cutscene_gen(game, "2", win, font);
    cutscene_gen(game, "3", win, font);
    cutscene_gen_noplayer(game, "4", win, font);
    cutscene_gen(game, "5", win, font);
}
