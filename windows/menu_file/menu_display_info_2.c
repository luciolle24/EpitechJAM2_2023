/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** menu_display_info_2
*/

#include "my_rpg.h"

picture_utility_t create_back(void)
{
    char *tmp_name = "asset/utility/MainMenu.png";
    picture_utility_t back;

    back.texture = sfTexture_createFromFile(tmp_name, NULL);
    back.pict = back_menu(back.texture);
    return back;
}

picture_utility_t create_back_for_the_pause_text(void)
{
    char *tmp_name = "asset/utility/back_pause.png";
    picture_utility_t back;

    back.texture = sfTexture_createFromFile(tmp_name, NULL);
    back.pict = create_back_info(back.texture);
    return back;
}

void destroy_menu_display(picture_utility_t back_i, picture_utility_t back)
{
    sfTexture_destroy(back.texture);
    sfRectangleShape_destroy(back.pict);
    sfTexture_destroy(back_i.texture);
    sfRectangleShape_destroy(back_i.pict);
}
