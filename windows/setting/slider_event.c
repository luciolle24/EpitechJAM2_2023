/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** slider_event
*/

#include "my_rpg.h"

static void move_music_slider(sfRenderWindow *win, game_setting_t *setting,
settings_elem_t sprite, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfVector2i actual_mouse;
    sfVector2f vector;

    vector.y = 0;
    sfRenderWindow_pollEvent(win, &event);
    while (event.type == sfEvtMouseMoved || event.type == 9) {
        display_sprites_settings(sprite, win);
        sfRenderWindow_display(win);
        sfRenderWindow_pollEvent(win, &event);
        if (event.type == sfEvtMouseButtonReleased)
            return;
        actual_mouse = sfMouse_getPosition(NULL);
        if (actual_mouse.x > 1100 && actual_mouse.x < 1700) {
            vector.x = (float)(actual_mouse.x - mouse.x);
            sfCircleShape_move(sprite.music_ball, vector);
            setting->music_volume += (int)vector.x / 5;
        }
        mouse = actual_mouse;
    }
}

void check_if_click_on_music_slider(sfRenderWindow *win,
game_setting_t *setting, settings_elem_t sprite, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfVector2f b = sfCircleShape_getPosition(sprite.music_ball);
    float r = sfCircleShape_getRadius(sprite.music_ball);

    b.x += r + 5;
    b.y += r * 4 - 3;
    if (((float)mouse.x - b.x) * 2 + ((float)mouse.y - b.y) * 2 <= r)
        if (((float)mouse.x - b.x) * 2 + ((float)mouse.y - b.y) * 2 >= -r)
            move_music_slider(win, setting, sprite, event);
}

static void move_sound_slider(sfRenderWindow *win, game_setting_t *setting,
settings_elem_t sprite, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfVector2i actual_mouse;
    sfVector2f vector;

    vector.y = 0;
    sfRenderWindow_pollEvent(win, &event);
    while (event.type == sfEvtMouseMoved || event.type == 9) {
        display_sprites_settings(sprite, win);
        sfRenderWindow_display(win);
        sfRenderWindow_pollEvent(win, &event);
        if (event.type == sfEvtMouseButtonReleased)
            return;
        actual_mouse = sfMouse_getPosition(NULL);
        if (actual_mouse.x > 1100 && actual_mouse.x < 1700) {
            vector.x = (float)(actual_mouse.x - mouse.x);
            sfCircleShape_move(sprite.sound_ball, vector);
            setting->sound_volume += (int)vector.x / 5;
        }
        mouse = actual_mouse;
    }
}

void check_if_click_on_sound_slider(sfRenderWindow *win,
game_setting_t *setting, settings_elem_t sprite, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfVector2f b = sfCircleShape_getPosition(sprite.sound_ball);
    float r = sfCircleShape_getRadius(sprite.sound_ball);

    b.x += r + 5;
    b.y += r * 4 - 3;
    if (((float)mouse.x - b.x) * 2 + ((float)mouse.y - b.y) * 2 <= r)
        if (((float)mouse.x - b.x) * 2 + ((float)mouse.y - b.y) * 2 >= -r)
            move_sound_slider(win, setting, sprite, event);
}
