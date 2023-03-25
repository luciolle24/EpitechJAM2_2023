/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-adam.balfet
** File description:
** menu
*/

#include "my_rpg.h"

sfRectangleShape *back_menu(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 0;
    pos.y = 0;
    size.x = 1920;
    size.y = 1000;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

static void display_menu(menu_t elem, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, elem.back_menu.pict, NULL);
    sfRenderWindow_drawRectangleShape(window, elem.info_button, NULL);
    sfRenderWindow_drawRectangleShape(window, elem.play_button, NULL);
    sfRenderWindow_drawRectangleShape(window, elem.quit_button, NULL);
    sfRenderWindow_drawRectangleShape(window, elem.back_setting.pict, NULL);
    sfRenderWindow_drawRectangleShape(window, elem.setting.pict, NULL);
    sfRenderWindow_drawText(window, elem.info_title, NULL);
    sfRenderWindow_drawText(window, elem.play_title, NULL);
    sfRenderWindow_drawText(window, elem.quit_title, NULL);
}

void menu(void)
{
    sfVideoMode mode = {1920, 1000, 30};
    sfRenderWindow *window;
    sfVector2f window_percentage;
    menu_t elem = def_elem();

    window = sfRenderWindow_create(mode, "MY_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    window_percentage = get_percentage(window);
    while (sfRenderWindow_isOpen(window)) {
        display_menu(elem, window);
        sfRenderWindow_display(window);
        window_percentage = check_event(window, elem, window_percentage);
    }
    sfRenderWindow_destroy(window);
}
