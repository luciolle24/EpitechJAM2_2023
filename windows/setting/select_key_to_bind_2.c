/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** select_key_to_bind_2
*/

#include "my_rpg.h"

int check_move_right_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 460 && mouse_pos.y <= 510) ? 1 : 0;
}

int check_interract_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 560 && mouse_pos.y <= 610) ? 1 : 0;
}

int check_attack_selected(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 600 && mouse_pos.x <= 650)
        return (mouse_pos.y >= 660 && mouse_pos.y <= 710) ? 1 : 0;
}

void check_if_a_key_is_selected_2(sfVector2i mouse_pos,
game_setting_t *setting, sfRenderWindow *win, settings_elem_t elem)
{
    if (check_move_right_selected(mouse_pos) == 1) {
        push_button(elem.key_move_right.pict, win);
        setting->move_right = change_the_key(elem.key_move_right.text, win);
        return;
    }
    if (check_interract_selected(mouse_pos) == 1) {
        push_button(elem.key_interact.pict, win);
        setting->interact = change_the_key(elem.key_interact.text, win);
        return;
    }
    if (check_attack_selected(mouse_pos) == 1) {
        push_button(elem.key_attack.pict, win);
        setting->attack = change_the_key(elem.key_attack.text, win);
        return;
    }
}
