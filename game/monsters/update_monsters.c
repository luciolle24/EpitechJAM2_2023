/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** update_monsters
*/

#include "game.h"

static void update(character_t *character, sfRenderWindow *window);
static void update_velocity(character_t *character);

void update_monsters(list_t *characters, sfRenderWindow *window)
{
    while (characters != NULL) {
        update((character_t *)characters->data, window);
        characters = characters->next;
    }
}

static void update(character_t *character, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, character->shape, NULL);
    character->timer -= *get_delta_time();
    if (character->timer <= 0)
        update_velocity(character);
    if (character->velocity.x > 0)
        anim_player(character, *get_time_elapsed(), my_strdup("right0"));
    else
        anim_player(character, *get_time_elapsed(), my_strdup("left0"));
    if (check_collider(character, character->velocity))
        sfRectangleShape_move(character->shape, character->velocity);
}

static void update_velocity(character_t *character)
{
    sfVector2f velocity = {rand() % 3, rand() % 2};

    character->timer = (float)(rand() % 100) / (float)10;
    character->velocity = velocity;
}
