/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_monsters
*/

#include "game.h"

static void init_shape(character_t *monster, char **map);
static sfVector2f get_random_pos(char **map);
static list_t *init_textures(char *path);

const sfIntRect monster_tiles[] = {
    {0, 0, 12, 7},
    {13, 0, 14, 9},
    {28, 0, 16, 9},
    {45, 1, 11, 7},
    {0, 10, 12, 7},
    {13, 10, 14, 9},
    {28, 10, 16, 9},
    {45, 10, 11, 7},
    {0}
};

const char *monster_labels[] = {
    "right0",
    "right1",
    "right2",
    "right3",
    "left0",
    "left1",
    "left2",
    "left3"
};

void init_monsters(list_t **characters, char **map)
{
    character_t *monster = NULL;
    sfVector2f pos = {0};
    sfVector2f default_velocity = {0};
    char *path = "asset/characters/slime_animation.png";

    for (int i = 0; i < 300; i++) {
        monster = malloc(sizeof(*monster));
        init_shape(monster, map);
        monster->textures = init_textures(path);
        monster->current_anim_index = 0;
        monster->prev_anim_time = -1;
        monster->timer = 0;
        monster->velocity = default_velocity;
        monster->map = map;
        *characters = add_data_to_list_start(*characters, monster);
    }
}

static void init_shape(character_t *monster, char **map)
{
    sfVector2f size = {80, 70};
    sfVector2f pos = get_random_pos(map);

    monster->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(monster->shape, size);
    sfRectangleShape_setPosition(monster->shape, pos);
}

static sfVector2f get_random_pos(char **map)
{
    sfVector2f pos;

    do {
        pos.x = rand() % 100;
        pos.y = rand() % 100;
    } while (map[(int)pos.y][(int)pos.x] != ' ');
    pos.x *= 200;
    pos.y *= 200;
    return (pos);
}

static list_t *init_textures(char *path)
{
    list_t *textures = NULL;
    player_texture_t *texture = NULL;

    for (int i = 0; monster_tiles[i].width != 0; i++) {
        texture = malloc(sizeof(*texture));
        texture->texture = sfTexture_createFromFile(path, &monster_tiles[i]);
        texture->label = monster_labels[i];
        textures = add_data_to_list_start(textures, texture);
    }
    return (textures);
}
