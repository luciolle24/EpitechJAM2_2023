/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** fill_utility
*/

#include "get_saves.h"

static int return_nb(char *buff, int *i)
{
    int nb = 0;
    int j = *i;

    for (; buff[j] != ';' && buff[j] != '\n' && buff[j] != ']'; j++) {
        nb = nb * 10 + buff[j] - 48;
    }
    *i = j + 1;
    return nb;
}

void fill_data_with_buff(char *buff, save_datas_t *datas, int i)
{
    datas->health = return_nb(buff, &i);
    datas->player_model = return_nb(buff, &i);
    datas->stamina = return_nb(buff, &i);
    datas->posx = return_nb(buff, &i);
    datas->posy = return_nb(buff, &i);
    datas->city = return_nb(buff, &i);
}
