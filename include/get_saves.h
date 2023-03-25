/*
** EPITECH PROJECT, 2022
** test_saves
** File description:
** get_saves
*/

#ifndef GET_SAVES_H_
    #define GET_SAVES_H_

    #include "stdlib.h"
    #include "unistd.h"
    #include "fcntl.h"
    #include "stdio.h"

typedef struct save_datas {
    char **map;
    int health;
    int player_model;
    int stamina;
    int posx;
    int posy;
    int city;
    int *inventory;
    int *inv_pos;
    int time;
    int language;
} save_datas_t;

void fill_datas(save_datas_t *datas, char *buff);
void reset_save(int save_nb);
void fill_save(save_datas_t *datas, int save_nb);
char *get_save_path(int save_nb);
void free_datas(save_datas_t *datas);
int my_strlen(const char *str);
int check_save(int save_nb);
void fill_data_with_buff(char *buff, save_datas_t *datas, int i);

#endif /* !GET_SAVES_H_ */
