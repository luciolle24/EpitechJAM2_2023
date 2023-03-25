/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** cutscene_show
*/

#include "cutscene.h"
#include "clock.h"
#include "utility.h"

static void show_bg(char *file, sfRenderWindow *win);
static void close_window(sfRenderWindow *win, int code);

void cutsc_print(cutscene_t *cut, sfRenderWindow *win, sfRectangleShape **spr,
sfFont *font)
{
    sfRectangleShape *text_box = create_txt_box();
    int code;

    show_bg(cut->background, win);
    sfRenderWindow_drawRectangleShape(win, text_box, NULL);
    print_character(cut->id, win, spr);
    print_character_name(cut->id, win, font);
    sfRenderWindow_display(win);
    print_text_nice(cut->dialogues, win, font);

    while ((code = check_if_keypressed_ct(win)) != 1) {
        sfRenderWindow_display(win);
        if (code > 1 && code < 4) {
            close_window(win, code);
            return;
        }
    }
    sfRectangleShape_destroy(text_box);
    if (cut->next->next != NULL)
        cutsc_print(cut->next, win, spr, font);
}

static void show_bg(char *file, sfRenderWindow *win)
{
    sfRectangleShape *sprite = back_menu(sfTexture_createFromFile(file, NULL));

    sfRenderWindow_drawRectangleShape(win, sprite, NULL);
}

sfText *create_text_cutsn(char *str, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = 130;
    pos.y = 880;
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 25);
    sfText_setPosition(text, pos);
    return (text);
}

sfRectangleShape *create_txt_box(void)
{
    char *tmp = "asset/utility/TextBox.png";
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(tmp, NULL);

    pos.x = 40;
    pos.y = 800;
    size.x = 1840;
    size.y = 200;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return (sprite);
}

static void close_window(sfRenderWindow *win, int code)
{
    if (code == 3)
        sfRenderWindow_destroy(win);
    return;
}
