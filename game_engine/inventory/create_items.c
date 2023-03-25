/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_items
*/

#include "inventory.h"

static sfRectangleShape *create_items(const char *filepath, int pos_x,
int pos_y);
static sfText *create_quantities(int quantity, int pos_x,
int pos_y, sfFont *font);

const char *item_texture_array[5] = {
    "asset/items/food.png",
    "asset/items/paperbomb.png",
    "asset/items/tracts.png",
    "asset/items/sword.png",
    NULL
};
const char *item_name_array[5] = {
    "Food",
    "Paper Bombs",
    "Tracts",
    "Sword",
    NULL
};

sfRectangleShape **init_items(sfVector2f center)
{
    int counter = 0;
    sfRectangleShape **sprite = malloc(sizeof(*sprite) * 5);

    while (item_texture_array[counter] != NULL) {
        sprite[counter] = create_items(item_texture_array[counter],
        (center.x - 400) + counter * 100, (center.y - 300));
        counter++;
    }
    return (sprite);
}

static sfRectangleShape *create_items(const char *filepath, int pos_x,
int pos_y)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    pos.x = pos_x + 15;
    pos.y = pos_y + 15;
    size.x = 70;
    size.y = 70;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return (sprite);
}

sfText **init_quantities(sfVector2f center, int *quantity)
{
    int counter = 0;
    sfText **sprite = malloc(sizeof(*sprite) * 5);
    sfFont *font = sfFont_createFromFile("asset/utility/Avara.ttf");

    while (item_texture_array[counter] != NULL) {
        sprite[counter] = create_quantities(quantity[counter],
        (center.x - 400) + counter * 100, (center.y - 300), font);
        counter++;
    }
    return (sprite);
}

static sfText *create_quantities(int quantity, int pos_x,
int pos_y, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = pos_x + 80;
    pos.y = pos_y + 70;
    sfText_setString(text, nb_to_str(quantity));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
    return (text);
}
