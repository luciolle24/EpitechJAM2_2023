/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_slider
*/

#include "my_rpg.h"

sfRectangleShape *def_slider_bar(void)
{
    sfRectangleShape *slider_bar;

    slider_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(slider_bar, (sfVector2f){600, 10});
    sfRectangleShape_setFillColor(slider_bar, sfBlack);
    return slider_bar;
}

sfCircleShape *def_slider_ball(void)
{
    sfCircleShape *slider_ball = sfCircleShape_create();

    sfCircleShape_setRadius(slider_ball, 20);
    sfCircleShape_setFillColor(slider_ball, sfRed);
    return slider_ball;
}

void init_music_and_sound(button_t sprit, sfVector2f pos, char *name)
{
    sfVector2f size;

    size.x = 200;
    size.y = 50;
    sfRectangleShape_setPosition(sprit.pict, pos);
    sfRectangleShape_setSize(sprit.pict, size);
    pos.x += 40;
    pos.y += 10;
    sfText_setString(sprit.text, name);
    sfText_setColor(sprit.text, sfBlack);
    sfText_setCharacterSize(sprit.text, 30);
    sfText_setPosition(sprit.text, pos);
}

void init_music_slider(sfRectangleShape *bar, sfCircleShape *ball,
int percentage)
{
    sfVector2f ball_pos;

    ball_pos.y = 205;
    ball_pos.x = 1100 + (600 * percentage) / 100;
    sfCircleShape_setPosition(ball, ball_pos);
    ball_pos.x = 1100;
    ball_pos.y = 220;
    sfRectangleShape_setPosition(bar, ball_pos);
}

void init_sound_slider(sfRectangleShape *bar, sfCircleShape *ball,
int percentage)
{
    sfVector2f ball_pos;

    ball_pos.y = 405;
    ball_pos.x = 1100 + (600 * percentage) / 100;
    sfCircleShape_setPosition(ball, ball_pos);
    ball_pos.x = 1100;
    ball_pos.y = 420;
    sfRectangleShape_setPosition(bar, ball_pos);
}
