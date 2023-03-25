/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** inventory
*/

#include "inventory.h"
#include "utility.h"
#include <stdio.h>

static char check_if_keypressed(sfRenderWindow *win);
static void display_items(sfRectangleShape **sprite, sfRenderWindow *win);
static void display_quantity(sfText **quantities, sfRenderWindow *win);

int display_inventory(sfRenderWindow *win, sfView *view, int *quantity)
{
    sfVector2f center = sfView_getCenter(view);
    sfRectangleShape *inventory_box = create_inventory(center);
    sfRectangleShape **sprites = init_items(center);
    sfText **quantities = init_quantities(center, quantity);
    int status = 1;

    sfRenderWindow_drawRectangleShape(win, inventory_box, NULL);
    display_items(sprites, win);
    display_quantity(quantities, win);
    sfRenderWindow_display(win);
    while (status == 1) {
        if (check_if_keypressed(win) == 1)
            status = 0;
    }
    sfRectangleShape_destroy(inventory_box);
    return (0);
}

static char check_if_keypressed(sfRenderWindow *win)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
            return (1);
    }
}

static void display_items(sfRectangleShape **sprite, sfRenderWindow *win)
{
    int counter = 0;

    while (counter < 4) {
        sfRenderWindow_drawRectangleShape(win, sprite[counter], NULL);
        counter++;
    }
}

static void display_quantity(sfText **quantities, sfRenderWindow *win)
{
    int counter = 0;

    while (counter < 4) {
        sfRenderWindow_drawText(win, quantities[counter], NULL);
        counter++;
    }
}
