/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** event_select_save
*/

#include "my_rpg.h"

int check_if_selected_esc_save(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 625 && mouse_pos.x <= 1310)
        return (mouse_pos.y >= 900 && mouse_pos.y <= 1010) ? 1 : 0;
}

int check_if_selected_save_1(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 130 && mouse_pos.x <= 505)
        return (mouse_pos.y >= 400 && mouse_pos.y <= 510) ? 1 : 0;
}

int check_if_selected_save_2(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 760 && mouse_pos.x <= 1140)
        return (mouse_pos.y >= 400 && mouse_pos.y <= 510) ? 1 : 0;
}

int check_if_selected_save_3(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 1390 && mouse_pos.x <= 1775)
        return (mouse_pos.y >= 400 && mouse_pos.y <= 510) ? 1 : 0;
}
