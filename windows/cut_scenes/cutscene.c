/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** cutscene_1
*/

#include "cutscene.h"
#include "structs.h"

void cutscene_gen_noplayer(game_setting_t *game, char *id, sfRenderWindow *win,
sfFont *font)
{
    cutscene_t *cutscene;
    sfRectangleShape **char_textures = init_character();
    char *actualfp = my_strdup("asset/dialogues/");

    actualfp = add_str_in_str(actualfp, game->language, my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, "/ct", my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, id, my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, ".txt", my_strlen(actualfp));
    cutscene = open_file(actualfp);
    if (cutscene->exit == -1) {
        write(2, "Bad dialogue file\n", 18);
        return;
    }
    while (sfRenderWindow_isOpen(win)) {
        cutsc_print(cutscene, win, char_textures, font);
        break;
    }
    free_cutscene(cutscene);
}

void cutscene_gen(game_setting_t *game, char *id, sfRenderWindow *win,
sfFont *font)
{
    cutscene_t *cutscene;
    sfRectangleShape **char_textures = init_character();
    char *actualfp = my_strdup("asset/dialogues/");

    actualfp = add_str_in_str(actualfp, game->language, my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, "/ct", my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, id, my_strlen(actualfp));
    actualfp = add_char_in_str(actualfp, '_', my_strlen(actualfp));
    actualfp = add_char_in_str(actualfp, game->player_id, my_strlen(actualfp));
    actualfp = add_str_in_str(actualfp, ".txt", my_strlen(actualfp));
    cutscene = open_file(actualfp);
    if (cutscene->exit == -1) {
        write(2, "Bad dialogue file\n", 18);
        return;
    }
    while (sfRenderWindow_isOpen(win)) {
        cutsc_print(cutscene, win, char_textures, font);
        break;
    }
    free_cutscene(cutscene);
}
