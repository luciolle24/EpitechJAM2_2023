/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_images
*/

#include "game.h"

const char *tiles_name[26] = {
    "asset/tiles/bridge1.png",
    "asset/tiles/bridge2.png",
    "asset/tiles/bridge3.png",
    "asset/tiles/grass1.png",
    "asset/tiles/grass2.png",
    "asset/tiles/grass3.png",
    "asset/tiles/grass4.png",
    "asset/tiles/mountain1.png",
    "asset/tiles/mountain2.png",
    "asset/tiles/mountain3.png",
    "asset/tiles/mountain4.png",
    "asset/tiles/mountain5.png",
    "asset/tiles/mountain6.png",
    "asset/tiles/mountain7.png",
    "asset/tiles/mountain8.png",
    "asset/tiles/mountain9.png",
    "asset/tiles/water1.png",
    "asset/tiles/water2.png",
    "asset/tiles/water3.png",
    "asset/tiles/water4.png",
    "asset/tiles/water5.png",
    "asset/tiles/water6.png",
    "asset/tiles/water7.png",
    "asset/tiles/water8.png",
    "asset/tiles/water9.png",
    NULL
};

static image_t *create_image(const char *name);
static char *get_image_name(const char *str);

list_t *init_images(void)
{
    list_t *images = NULL;
    sfImage *image;

    for (int i = 0; tiles_name[i] != NULL; i++)
        images = add_data_to_list_start(images, create_image(tiles_name[i]));
    return (images);
}

static image_t *create_image(const char *name)
{
    image_t *image = malloc(sizeof(*image));
    sfIntRect area = {0, 0, 248, 248};
    sfTexture *texture = sfTexture_createFromFile(name, &area);

    image->image = sfImage_createFromFile(name);
    image->name = get_image_name(name);
    image->texture = texture;
    return (image);
}

static char *get_image_name(const char *str)
{
    int len = my_strlen(str);
    int size = 0;
    int offset = 0;
    char *name = NULL;

    for (size = len - 1; size >= 0 && str[size] != '/'; size--);
    size = len - size;
    name = malloc(sizeof(*name) * (size + 1));
    offset = len - size;
    for (int i = 0; i < size; i++)
        name[i] = str[offset + 1 + i];
    name[size] = '\0';
    return (name);
}
