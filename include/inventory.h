/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>

// \brief creates the inventory sprite
sfRectangleShape *create_inventory(sfVector2f center);
// \brief displays the inventory
int display_inventory(sfRenderWindow *win, sfView *view, int *quantity);
// \brief initializes items for the inventory
sfRectangleShape **init_items(sfVector2f center);
// \brief initializes quantities for the inventory
sfText **init_quantities(sfVector2f center, int *quantity);
// \brief transforms a psoitive int into a str
char *nb_to_str(int nb);
#endif /* !INVENTORY_H_ */
