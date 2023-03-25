/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** anim_player
*/

#include "game.h"

static sfTexture *get_player_anim_texture(list_t *textures, const char *label);

void anim_player(character_t *player, float time_elapsed, char *label)
{
    int current_anim_time = (int)(time_elapsed * 10);
    sfTexture *texture = NULL;

    if (current_anim_time == player->prev_anim_time) {
        free(label);
        return;
    }
    player->prev_anim_time = current_anim_time;
    if (current_anim_time % 5 == 0) {
        label[my_strlen(label) - 1] = player->current_anim_index + '0';
        texture = get_player_anim_texture(player->textures, label);
        sfRectangleShape_setTexture(player->shape, texture, sfTrue);
        player->current_anim_index += 1;
        player->current_anim_index %= 4;
    }
    free(label);
}

static sfTexture *get_player_anim_texture(list_t *textures, const char *label)
{
    while (textures != NULL) {
        if (is_same_str(((player_texture_t *)textures->data)->label, label))
            return (((player_texture_t *)textures->data)->texture);
        textures = textures->next;
    }
    return (NULL);
}
