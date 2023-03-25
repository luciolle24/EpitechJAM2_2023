/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy_player
*/

#include "game.h"

static void player_destroy_texture_element(void *data);

void destroy_player(character_t *player)
{
    sfRectangleShape_destroy(player->shape);
    destroy_list(player->textures, &player_destroy_texture_element);
    free(player);
}

static void player_destroy_texture_element(void *data)
{
    player_texture_t *texture =  (player_texture_t *)data;

    sfTexture_destroy(texture->texture);
    free(texture);
}
