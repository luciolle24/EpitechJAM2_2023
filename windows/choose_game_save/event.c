/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** event
*/

#include "my_rpg.h"
#include "game.h"

static void check_if_mouse_on(sfRenderWindow *win, menu_t elem,
sfVector2i mouse_pos, choose_save_t s)
{
    sfRectangleShape_setOutlineColor(s.quit_button.pict, sfTransparent);
    if (check_if_selected_esc_save(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.quit_button.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.new_save_1.pict, sfTransparent);
    if (check_if_selected_save_1(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.new_save_1.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.new_save_2.pict, sfTransparent);
    if (check_if_selected_save_2(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.new_save_2.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.new_save_3.pict, sfTransparent);
    if (check_if_selected_save_3(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.new_save_3.pict, sfRed);
}

static int check_game_button_2(sfRenderWindow *win, menu_t elem,
sfVector2i mouse_pos, choose_save_t sprites)
{
    if (check_if_selected_save_3(mouse_pos) == 1) {
        push_button(sprites.new_save_3.pict, win);
        push_button(sprites.done_save_3.pict, win);
        run_game(win, elem.setting_value, 3);
        return 1;
    }
    return 0;
}

static int check_game_button(sfRenderWindow *win, menu_t elem,
sfVector2i mouse_pos, choose_save_t sprites)
{
    if (check_if_selected_esc_save(mouse_pos) == 1) {
        push_button(sprites.quit_button.pict, win);
        return 1;
    }
    if (check_if_selected_save_1(mouse_pos) == 1) {
        push_button(sprites.new_save_1.pict, win);
        push_button(sprites.done_save_1.pict, win);
        run_game(win, elem.setting_value, 1);
        return 1;
    }
    if (check_if_selected_save_2(mouse_pos) == 1) {
        push_button(sprites.new_save_2.pict, win);
        push_button(sprites.done_save_2.pict, win);
        run_game(win, elem.setting_value, 2);
        return 1;
    }
    return check_game_button_2(win, elem, mouse_pos, sprites);
}

int choose_file_event(sfRenderWindow *win, menu_t elem, choose_save_t sprites)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);

    if (sfRenderWindow_pollEvent(win, &event)) {
        check_if_mouse_on(win, elem, mouse_pos, sprites);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
        if (event.type == sfEvtMouseButtonPressed)
            return check_game_button(win, elem, mouse_pos, sprites);
    }
    return 0;
}
