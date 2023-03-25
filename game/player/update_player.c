/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** update_player
*/

#include "game.h"

static void put_player(character_t *player, sfRenderWindow *window);

void update_player(character_t *player, sfRenderWindow *window, sfClock *clock,
sfView *view)
{
    float delta_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    sfClock_restart(clock);
    *get_time_elapsed() += delta_time;
    put_player(player, window);
}

void move_player(character_t *player, float offset_x, float offset_y)
{
    sfVector2f offset = {offset_x, offset_y};

    if (offset.x < 0)
        anim_player(player, *get_time_elapsed(), my_strdup("left0"));
    if (offset.x > 0)
        anim_player(player, *get_time_elapsed(), my_strdup("right0"));
    if (offset.y < 0)
        anim_player(player, *get_time_elapsed(), my_strdup("top0"));
    if (offset.y > 0)
        anim_player(player, *get_time_elapsed(), my_strdup("down0"));
    sfRectangleShape_move(player->shape, offset);
}

static void put_player(character_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, player->shape, NULL);
}
