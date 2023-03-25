/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** display
*/

#include "my_rpg.h"

static void display_sprites_3(settings_elem_t sprites, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, sprites.music_bar, NULL);
    sfRenderWindow_drawCircleShape(win, sprites.music_ball, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.sound_bar, NULL);
    sfRenderWindow_drawCircleShape(win, sprites.sound_ball, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.music.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.sound.pict, NULL);
    sfRenderWindow_drawText(win, sprites.music.text, NULL);
    sfRenderWindow_drawText(win, sprites.sound.text, NULL);
}

static void display_sprites_2(settings_elem_t sprites, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, sprites.quit_button.pict, NULL);
    sfRenderWindow_drawText(win, sprites.quit_button.text, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_attack.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_move_up.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_move_down.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_move_left.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_move_right.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.key_interact.pict, NULL);
    sfRenderWindow_drawText(win, sprites.key_move_up.text, NULL);
    sfRenderWindow_drawText(win, sprites.key_move_down.text, NULL);
    sfRenderWindow_drawText(win, sprites.key_move_left.text, NULL);
    sfRenderWindow_drawText(win, sprites.key_move_right.text, NULL);
    sfRenderWindow_drawText(win, sprites.key_attack.text, NULL);
    sfRenderWindow_drawText(win, sprites.key_interact.text, NULL);
    display_sprites_3(sprites, win);
}

void display_sprites_settings(settings_elem_t sprites, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, sprites.simple_back.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.back_settings.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.move_up.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.move_down.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.move_left.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.move_right.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.attack.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.interact.pict, NULL);
    sfRenderWindow_drawText(win, sprites.move_up.text, NULL);
    sfRenderWindow_drawText(win, sprites.move_down.text, NULL);
    sfRenderWindow_drawText(win, sprites.move_left.text, NULL);
    sfRenderWindow_drawText(win, sprites.move_right.text, NULL);
    sfRenderWindow_drawText(win, sprites.attack.text, NULL);
    sfRenderWindow_drawText(win, sprites.interact.text, NULL);
    display_sprites_2(sprites, win);
}
