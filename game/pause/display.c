/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** display
*/

#include "game.h"

void render_button(sfRenderWindow *window, button_t button)
{
    sfRenderWindow_drawRectangleShape(window, button.pict, NULL);
    sfRenderWindow_drawText(window, button.text, NULL);
}

void display_game_pause(sfRenderWindow *window, game_pause_t sprites)
{
    sfRenderWindow_drawRectangleShape(window, sprites.back_menu.pict, NULL);
    sfRenderWindow_drawRectangleShape(window, sprites.back_setting.pict, NULL);
    sfRenderWindow_drawRectangleShape(window, sprites.setting.pict, NULL);
    render_button(window, sprites.resume);
    render_button(window, sprites.quit);
}
