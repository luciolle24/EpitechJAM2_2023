/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** choose_save
*/

#include "my_rpg.h"
#include "get_saves.h"

static void display_sprites_2(choose_save_t sprites, sfRenderWindow *win,
int *save)
{
    if (save[2] == 0) {
        sfRenderWindow_drawRectangleShape(win, sprites.new_save_3.pict, NULL);
        sfRenderWindow_drawText(win, sprites.new_save_3.text, NULL);
    } else {
        sfRenderWindow_drawRectangleShape(win, sprites.done_save_3.pict, NULL);
        sfRenderWindow_drawText(win, sprites.done_save_3.text, NULL);
    }
    sfRenderWindow_drawRectangleShape(win, sprites.quit_button.pict, NULL);
    sfRenderWindow_drawText(win, sprites.quit_button.text, NULL);
}

static void display_sprites_1(choose_save_t sprites, sfRenderWindow *win,
int *save)
{
    sfRenderWindow_drawRectangleShape(win, sprites.simple_back.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.back_save_1.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.back_save_2.pict, NULL);
    sfRenderWindow_drawRectangleShape(win, sprites.back_save_3.pict, NULL);
    if (save[0] == 0) {
        sfRenderWindow_drawRectangleShape(win, sprites.new_save_1.pict, NULL);
        sfRenderWindow_drawText(win, sprites.new_save_1.text, NULL);
    } else {
        sfRenderWindow_drawRectangleShape(win, sprites.done_save_1.pict, NULL);
        sfRenderWindow_drawText(win, sprites.done_save_1.text, NULL);
    }
    if (save[1] == 0) {
        sfRenderWindow_drawRectangleShape(win, sprites.new_save_2.pict, NULL);
        sfRenderWindow_drawText(win, sprites.new_save_2.text, NULL);
    } else {
        sfRenderWindow_drawRectangleShape(win, sprites.done_save_2.pict, NULL);
        sfRenderWindow_drawText(win, sprites.done_save_2.text, NULL);
    }
    display_sprites_2(sprites, win, save);
}

void choose_file_to_play(sfRenderWindow *win, menu_t elem)
{
    choose_save_t sprites = def_all_sprite_in_choose_save();
    int *save = malloc(sizeof(int) * 3);

    save[0] = check_save(1);
    save[1] = check_save(2);
    save[2] = check_save(3);
    while (choose_file_event(win, elem, sprites) == 0) {
        display_sprites_1(sprites, win, save);
        sfRenderWindow_display(win);
    }
    free(save);
    destroy_choose_save(sprites);
}
