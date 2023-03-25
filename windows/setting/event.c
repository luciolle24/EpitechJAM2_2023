/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** event
*/

#include "my_rpg.h"

static int check_if_selected_esc(sfVector2i mouse_pos)
{
    if (mouse_pos.x >= 625 && mouse_pos.x <= 1310)
        return (mouse_pos.y >= 800 && mouse_pos.y <= 910) ? 1 : 0;
}

static int check_game_button(sfRenderWindow *win, game_setting_t *setting,
settings_elem_t sprite, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);

    check_if_click_on_music_slider(win, setting, sprite, event);
    check_if_click_on_sound_slider(win, setting, sprite, event);
    if (check_if_selected_esc(mouse_pos) == 1) {
        push_button(sprite.quit_button.pict, win);
        return 1;
    }
    check_if_a_key_is_selected(mouse_pos, setting, win, sprite);
    return 0;
}

static void check_if_mouse_is_on_2(sfRenderWindow *win, settings_elem_t s,
sfVector2i mouse_pos)
{
    sfRectangleShape_setOutlineColor(s.key_move_left.pict, sfTransparent);
    if (check_move_left_selected(mouse_pos) == 1)
        return sfRectangleShape_setOutlineColor(s.key_move_left.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.key_move_right.pict, sfTransparent);
    if (check_move_right_selected(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.key_move_right.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.quit_button.pict, sfTransparent);
    if (check_if_selected_esc(mouse_pos) == 1)
        sfRectangleShape_setOutlineColor(s.quit_button.pict, sfRed);
}

static void check_if_mouse_is_on(sfRenderWindow *win, settings_elem_t s)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);

    sfRectangleShape_setOutlineColor(s.key_interact.pict, sfTransparent);
    if (check_interract_selected(mouse_pos) == 1)
        return sfRectangleShape_setOutlineColor(s.key_interact.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.key_attack.pict, sfTransparent);
    if (check_attack_selected(mouse_pos) == 1)
        return sfRectangleShape_setOutlineColor(s.key_attack.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.key_move_down.pict, sfTransparent);
    if (check_move_down_selected(mouse_pos) == 1)
        return sfRectangleShape_setOutlineColor(s.key_move_down.pict, sfRed);
    sfRectangleShape_setOutlineColor(s.key_move_up.pict, sfTransparent);
    if (check_move_up_selected(mouse_pos) == 1)
        return sfRectangleShape_setOutlineColor(s.key_move_up.pict, sfRed);
    check_if_mouse_is_on_2(win, s, mouse_pos);
}

int settings_event(sfRenderWindow *win, game_setting_t *setting,
settings_elem_t sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        check_if_mouse_is_on(win, sprite);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
        if (event.type == sfEvtMouseButtonPressed)
            return check_game_button(win, setting, sprite, event);
    }
    return 0;
}
