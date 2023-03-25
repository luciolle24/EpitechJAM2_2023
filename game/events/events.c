/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** events
*/

#include "my_rpg.h"
#include "game.h"

static void check_move_player(sfEvent event, game_setting_t *settings, \
core_game_t game, sfRenderWindow *window);

// static int check_key_pressed(sfEvent event, game_setting_t *settings,
// sfView *view, sfRenderWindow *window);

int check_game_events(sfRenderWindow *win, game_setting_t *settings,
core_game_t game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        switch (event.type) {
            case (sfEvtClosed):
                sfRenderWindow_close(win);
                return 1;
            case (sfEvtKeyPressed):
                check_move_player(event, settings, game, win);
                return check_if_esc_is_press(event, settings, game.view, win);
        }
    }
}

static void check_move_player(sfEvent event, game_setting_t *set,
core_game_t game, sfRenderWindow *window)
{
    sfVector2f vect = {0};
    float speed = 10;

    vect.y = (event.text.unicode == set->move_down - 'a') ? speed : vect.y;
    vect.y = (event.text.unicode == set->move_up - 'a') ? -speed : vect.y;
    vect.x = (event.text.unicode == set->move_right - 'a') ? speed : vect.x;
    vect.x = (event.text.unicode == set->move_left - 'a') ? -speed : vect.x;
    if (check_collider((character_t *)game.characters->data, vect)) {
        move_player((character_t *)game.characters->data, vect.x, vect.y);
        sfView_move(game.view, vect);
    }
}
