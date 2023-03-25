/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy_game_data
*/

#include "game.h"

void destroy_image_list(void *data)
{
    image_t *image = (image_t *)data;

    sfImage_destroy(image->image);
    sfTexture_destroy(image->texture);
    free(image->name);
    free(image);
}
