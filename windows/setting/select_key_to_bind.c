/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** select_key_to_bind
*/

#include "my_rpg.h"

int check_move_up_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 160 && mouse_pos.y <= 210) ? 1 : 0;
}

int check_move_down_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 260 && mouse_pos.y <= 310) ? 1 : 0;
}

int check_move_left_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 360 && mouse_pos.y <= 410) ? 1 : 0;
}

int change_the_key(sfText *text, sfRenderWindow *win)
{
    int tmp = 0;
    char *letter;

    tmp = get_key_binding(win) + 'a';
    letter = letter_to_string(tmp);
    sfText_setString(text, letter);
    free(letter);
    return tmp;
}

void check_if_a_key_is_selected(sfVector2i mouse_pos, game_setting_t *setting,
sfRenderWindow *win, settings_elem_t elem)
{
    if (check_move_up_selected(mouse_pos) == 1) {
        push_button(elem.key_move_up.pict, win);
        setting->move_up = change_the_key(elem.key_move_up.text, win);
        return;
    }
    if (check_move_down_selected(mouse_pos) == 1) {
        push_button(elem.key_move_down.pict, win);
        setting->move_down = change_the_key(elem.key_move_down.text, win);
        return;
    }
    if (check_move_left_selected(mouse_pos) == 1) {
        push_button(elem.key_move_left.pict, win);
        setting->move_left = change_the_key(elem.key_move_left.text, win);
        return;
    }
    check_if_a_key_is_selected_2(mouse_pos, setting, win, elem);
}
