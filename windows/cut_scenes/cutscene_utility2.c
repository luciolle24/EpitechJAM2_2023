
/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cut_scene_loop
*/

#include "cutscene.h"
#include "clock.h"

ret_values_t *init_cutcene_values(void)
{
    ret_values_t  *ret_values = malloc(sizeof(*ret_values));

    ret_values->counter = 1;
    ret_values->talking = 0;
    return (ret_values);
}

void print_text_nice(char *str, sfRenderWindow *win, sfFont *font)
{
    int size = my_strlen(str);
    char *new_str = my_strdup(" ");
    int counter = 0;
    sfText *text = create_text_cutsn(new_str, font);
    clocks_t clock = initialize_clock(3000);

    sfRenderWindow_display(win);
    while (counter < size) {
        new_str = add_char_in_str(new_str, str[counter], counter);
        text = create_text_cutsn(new_str, font);
        while (check_elapsed_time(clock) != 1) {
            sfRenderWindow_drawText(win, text, NULL);
            sfRenderWindow_display(win);
        }
        counter++;
    }
    sfText_destroy(text);
}

