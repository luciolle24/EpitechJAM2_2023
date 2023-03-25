/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_inventory
*/

#include "inventory.h"

sfRectangleShape *create_inventory(sfVector2f center)
{
    sfRectangleShape *sprite = sfRectangleShape_create();
    sfTexture *text = sfTexture_createFromFile("asset/utility/inventory.png",
    NULL);
    sfVector2f pos;
    sfVector2f size;

    pos.x = center.x - 400;
    pos.y = center.y - 300;
    size.x = 800;
    size.y = 400;
    sfRectangleShape_setTexture(sprite, text, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return (sprite);
}
