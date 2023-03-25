/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fill_save
*/

#include "get_saves.h"

int check_save(int save_nb)
{
    int fd = open(get_save_path(save_nb), O_RDONLY);
    char buff[8];

    read(fd, buff, 8);
    close(fd);
    if (buff[7] == ' ')
        return 0;
    return 1;
}

void reset_save(int save_nb)
{
    int fd = open(get_save_path(save_nb), O_RDWR | O_TRUNC);
    int fd2 = open("saves/save_template.txt", O_RDONLY);
    char *buff = malloc(sizeof(char) * 10209);

    read(fd2, buff, 10209);
    write(fd, buff, 10209);
    free(buff);
    close(fd);
    close(fd2);
}

char *nb_to_str(int nb)
{
    char *str = malloc(sizeof(char));
    int keep = 0;
    int i = 0;

    for (i = 1; (nb / i) > 1; i *= 10, keep++) {
        free(str);
        str = malloc(sizeof(char) * keep);
    }
    if (nb < 10) {
        str[0] = nb + 48;
        str[1] = '\0';
        return str;
    }
    for (int j = 0; nb > 0; j++) {
        str[j] = (nb / i) + 48;
        nb = nb % (i);
        i /= 10;
    }
    return str;
}

static void end_the_fill_save(int fd, char *temp, char *off_heap)
{
    write(fd, temp, my_strlen(temp));
    write(fd, "]", 1);
    write(fd, "\ninventory:[\0", 13);
    close(fd);
    free(off_heap);
}

void fill_save(save_datas_t *datas, int save_nb)
{
    int fd = open(get_save_path(save_nb), O_RDWR);
    char *off_heap = malloc(sizeof(char) * 100);
    char *temp;
    int nbs[6] = {datas->health, datas->player_model,
    datas->stamina, datas->posx, datas->posy, datas->city};

    read(fd, off_heap, 6);
    for (int i = 0; i < 100; i++) {
        write(fd, datas->map[i], 100);
        write(fd, "\n", 1);
    }
    read(fd, off_heap, 10);
    for (int i = 0; i < 5; i++) {
        temp = nb_to_str(nbs[i]);
        write(fd, temp, my_strlen(temp));
        write(fd, ";", 1);
        free(temp);
    }
    temp = nb_to_str(nbs[5]);
    end_the_fill_save(fd, temp, off_heap);
}
