/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-adam.balfet
** File description:
** menu_event
*/

#include "my_rpg.h"
#include "cutscene.h"

static void check_if_mouse_on(sfRenderWindow *win, menu_t elem,
sfVector2f perc, sfVector2i m_pos)
{
    sfRectangleShape_setOutlineColor(elem.quit_button, sfTransparent);
    if (check_press_quit(win, perc, m_pos) == 1)
        return sfRectangleShape_setOutlineColor(elem.quit_button, sfRed);
    sfRectangleShape_setOutlineColor(elem.info_button, sfTransparent);
    if (check_press_info(win, perc, m_pos) == 1)
        return sfRectangleShape_setOutlineColor(elem.info_button, sfRed);
    sfRectangleShape_setOutlineColor(elem.play_button, sfTransparent);
    if (check_press_play(win, perc, m_pos) == 1)
        return sfRectangleShape_setOutlineColor(elem.play_button, sfRed);
    sfRectangleShape_setOutlineColor(elem.setting.pict, sfTransparent);
    if (check_press_sett(win, perc, m_pos) == 1)
        sfRectangleShape_setOutlineColor(elem.setting.pict, sfRed);
}

static void check_button(sfRenderWindow *win, menu_t elem, sfVector2f perc,
sfVector2i m_pos)
{
    if (check_press_quit(win, perc, m_pos) == 1) {
        push_button(elem.quit_button, win);
        return menu_destroy(win, elem);
    }
    if (check_press_info(win, perc, m_pos) == 1) {
        push_button(elem.info_button, win);
        cutscene_gen_noplayer(elem.setting_value, "0", win, elem.text_font);
        return;
    }
    if (check_press_play(win, perc, m_pos) == 1) {
        push_button(elem.play_button, win);
        return choose_file_to_play(win, elem);
    }
    if (check_press_sett(win, perc, m_pos) == 1) {
        push_button(elem.back_setting.pict, win);
        return change_settings(win, elem.setting_value);
    }
}

sfVector2f check_event(sfRenderWindow *win, menu_t elem, sfVector2f perc)
{
    sfEvent event;
    sfVector2i m_pos = sfMouse_getPosition(NULL);

    if (sfRenderWindow_pollEvent(win, &event)) {

        check_if_mouse_on(win, elem, perc, m_pos);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            menu_destroy(win, elem);
        if (event.type == sfEvtClosed)
            menu_destroy(win, elem);
        if (event.type == sfEvtMouseButtonPressed)
            check_button(win, elem, perc, m_pos);
        return (event.type == sfEvtResized) ? get_percentage(win) : perc;
    }
    return perc;
}
