/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** event
*/

#include "game.h"
#include "inventory.h"

int check_if_esc_is_press(sfEvent event, game_setting_t *settings,
sfView *view, sfRenderWindow *window)
{
    int quantity[5];
    quantity[0] = 1;
    quantity[1] = 2;
    quantity[2] = 2;
    quantity[3] = 1;

    if (event.key.code == sfKeyEscape)
        return game_pause(window, settings, view);
    if (event.key.code == sfKeyE)
        return display_inventory(window, view, quantity);
    return 0;
}

static int check_if_button_select2(sfRenderWindow *window,
game_setting_t *settings, sfView *view, game_pause_t sprites)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f tmp;

    if (check_if_select(mouse_pos, sprites.quit.pict, center) == 1) {
        push_button(sprites.quit.pict, window);
        sfView_setCenter(view, (sfVector2f){960, 500});
        sfRenderWindow_setView(window, view);
        sfRenderWindow_display(window);
        return 2;
    }
    if (check_if_select(mouse_pos, sprites.resume.pict, center) == 1) {
        push_button(sprites.resume.pict, window);
        return 1;
    }
    return 0;
}

static int check_if_button_select(sfRenderWindow *window,
game_setting_t *settings, sfView *view, game_pause_t sprites)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f tmp;

    if (check_if_select(mouse_pos, sprites.back_setting.pict, center) == 1) {
        push_button(sprites.back_setting.pict, window);
        tmp = sfView_getCenter(view);
        sfView_setCenter(view, (sfVector2f){960, 500});
        sfRenderWindow_setView(window, view);
        sfRenderWindow_display(window);
        change_settings(window, settings);
        sfView_setCenter(view, tmp);
        return 1;
    }
    return check_if_button_select2(window, settings, view, sprites);
}

static void overlay(sfRenderWindow *window,
game_setting_t *settings, sfView *view, game_pause_t sprites)
{
    sfVector2f center = sfView_getCenter(view);
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);

    sfRectangleShape_setOutlineColor(sprites.back_setting.pict, sfYellow);
    if (check_if_select(mouse_pos, sprites.back_setting.pict, center) == 1) {
        sfRectangleShape_setOutlineColor(sprites.back_setting.pict, sfRed);
        return;
    }
    sfRectangleShape_setOutlineColor(sprites.quit.pict, sfTransparent);
    if (check_if_select(mouse_pos, sprites.quit.pict, center) == 1) {
        sfRectangleShape_setOutlineColor(sprites.quit.pict, sfRed);
        return;
    }
    sfRectangleShape_setOutlineColor(sprites.resume.pict, sfTransparent);
    if (check_if_select(mouse_pos, sprites.resume.pict, center) == 1) {
        sfRectangleShape_setOutlineColor(sprites.resume.pict, sfRed);
        return;
    }
}

int game_pause_event(sfRenderWindow *window, game_setting_t *settings,
sfView *view, game_pause_t sprites)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        overlay(window, settings, view, sprites);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
        if (event.type == sfEvtMouseButtonPressed)
            return check_if_button_select(window, settings, view, sprites);
    }
    return 0;
}
