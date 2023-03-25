/*
** EPITECH PROJECT, 2021
** menu_display_info
** File description:
** menu_display_info
*/

#include "my_rpg.h"

static int info_quit(sfRenderWindow *wind)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(wind, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wind);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
    }
    return 0;
}

sfRectangleShape *create_back_info(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 520;
    pos.y = 120;
    size.x = 860;
    size.y = 800;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

static sfText *create_info_title_text(sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = 650;
    pos.y = 130;
    sfText_setColor(text, sfBlack);
    sfText_setString(text, "GAME INFO");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, pos);
    return text;
}

static sfText *create_info_text(int i, sfFont *font)
{
    sfText *text = sfText_create();
    char *texte;
    sfVector2f pos;

    if (i == 1)
        texte = "C'EST UN TOWER DÉFENSE\nVOUS POUVEZ POSER DES CHATS(TOUR)";
    else
        texte = "QUI TUERONT LES TOURS(ENNEMI)\nCROIX DIRECTIONNELLE POUR CAM";
    pos.x = 570;
    pos.y = (i == 1) ? 400 : 500;
    sfText_setColor(text, sfBlack);
    sfText_setString(text, texte);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    return text;
}

void display_game_info(sfRenderWindow *window)
{
    picture_utility_t back = create_back();
    sfFont *font = sfFont_createFromFile("asset/utility/Avara.ttf");
    picture_utility_t back_info = create_back_for_the_pause_text();
    sfText *info_title = create_info_title_text(font);
    sfText *text = create_info_text(1, font);
    sfText *text2 = create_info_text(2, font);

    while (info_quit(window) == 0) {
        sfRenderWindow_drawRectangleShape(window, back.pict, NULL);
        sfRenderWindow_drawRectangleShape(window, back_info.pict, NULL);
        sfRenderWindow_drawText(window, info_title, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_drawText(window, text2, NULL);
        sfRenderWindow_display(window);
    }
    sfFont_destroy(font);
    sfText_destroy(info_title);
    sfText_destroy(text);
    sfText_destroy(text2);
    destroy_menu_display(back, back_info);
}
