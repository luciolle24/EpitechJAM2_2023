/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fill_datas
*/

#include "get_saves.h"

void free_datas(save_datas_t *datas)
{
    for (int i = 0; datas->map[i]; i++)
        free(datas->map[i]);
    free(datas->map);
    free(datas->inventory);
    free(datas->inv_pos);
}

static void get_inv_obj(char *buff, int *i, save_datas_t *datas)
{
    int nb = 0;
    int ctr = *i + 12;

    datas->inventory = malloc(sizeof(int) * 7);
    for (int j = 0; j < 7; j++) {
        for (; buff[ctr] != '.' && buff[ctr] != ']'; ctr++);
        ctr++;
        for (nb = 0; buff[ctr] != ';' && buff[ctr] != ']'; ctr++) {
            nb = nb * 10 + (buff[ctr] - 48);
        }
        datas->inventory[j] = nb;
    }
    *i = ctr;
}

static void get_inv_order(char *buff, int *i, save_datas_t *datas)
{
    int nb = 0;
    int ctr = *i + 2;

    datas->inv_pos = malloc(sizeof(int) * 12);
    for (int j = 0; j < 12; j++)
        datas->inv_pos[j] = -1;
    for (int j = 0; j < 12; ctr++, j++) {
        for (nb = 0; buff[ctr] != ';' && buff[ctr] != ']'; ctr++) {
            nb = nb * 10 + (buff[ctr] - 48);
        }
        datas->inv_pos[j] = nb;
    }
}

void fill_datas(save_datas_t *datas, char *buff)
{
    int i = 6;
    int j = 0;
    int k = 0;

    datas->map = malloc(sizeof(char *) * 101);
    for (j = 0; i > 10107 || buff[i] != ']'; j++, i++) {
        datas->map[j] = malloc(sizeof(char) * 101);
        for (k = 0; buff[i] != '\n'; i++, k++)
            datas->map[j][k] = buff[i];
        datas->map[j][k] = '\0';
    }
    datas->map[j] = NULL;
    i += 10;
    fill_data_with_buff(buff, datas, i);
    get_inv_obj(buff, &i, datas);
    get_inv_order(buff, &i, datas);
}
