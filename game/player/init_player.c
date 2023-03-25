/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_player
*/

#include "game.h"

static sfRectangleShape *init_player_shape(sfVector2f pos, sfVector2f size);
static list_t *init_player_textures(char *image_path);

const sfIntRect player_tiles[] = {
    {1, 1, 13, 17},
    {15, 0, 14, 18},
    {30, 1, 13, 17},
    {44, 0, 14, 18},
    {2, 19, 11, 18},
    {15, 19, 11, 18},
    {30, 19, 11, 17},
    {44, 19, 11, 18},
    {2, 38, 11, 18},
    {15, 38, 11, 18},
    {30, 38, 11, 18},
    {44, 38, 11, 18},
    {1, 57, 13, 16},
    {15, 57, 14, 17},
    {30, 57, 13, 16},
    {44, 57, 14, 17},
    {0}
};

const char *player_labels[] = {
    "down0",
    "down1",
    "down2",
    "down3",
    "right0",
    "right1",
    "right2",
    "right3",
    "left0",
    "left1",
    "left2",
    "left3",
    "top0",
    "top1",
    "top2",
    "top3"
};

character_t *init_player(sfView *view)
{
    character_t *player = malloc(sizeof(*player));
    sfVector2f position = sfView_getCenter(view);
    sfVector2f size = {70, 100};
    sfVector2f default_velocity = {0};
    char *image_path = "asset/characters/player_animation.png";

    player->shape = init_player_shape(position, size);
    player->textures = init_player_textures(image_path);
    player->prev_anim_time = -1;
    player->current_anim_index = 0;
    player->timer = 0;
    player->velocity = default_velocity;
    sfRectangleShape_setPosition(player->shape, position);
    return (player);
}

static sfRectangleShape *init_player_shape(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setTexture(shape, NULL, sfTrue);
    return (shape);
}

static list_t *init_player_textures(char *image_path)
{
    list_t *textures = NULL;
    sfTexture *texture = NULL;
    player_texture_t *player_texture = NULL;

    for (int i = 0; player_tiles[i].width != 0; i++) {
        player_texture = malloc(sizeof(*player_texture));
        texture = sfTexture_createFromFile(image_path, &player_tiles[i]);
        player_texture->texture = texture;
        player_texture->label = player_labels[i];
        textures = add_data_to_list_start(textures, player_texture);
    }
    return (textures);
}
