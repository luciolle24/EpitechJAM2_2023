/*
** EPITECH PROJECT, 2022
** test_saves
** File description:
** main
*/

#include "get_saves.h"

char *get_save_path(int save_nb)
{
    if (save_nb == 1) {
        return "saves/save1.txt";
    }
    if (save_nb == 2) {
        return "saves/save2.txt";
    }
    if (save_nb == 3) {
        return "saves/save3.txt";
    }
    write(2, "ERROR: invalid save was given\n", 31);
    return NULL;
}

void my_memset(char *buff, char c, int size)
{
    for (int i = 0; i < size; i++)
        buff[i] = c;
    buff[size - 1] = '\0';
}

void read_file(char *buff, int fd)
{
    int result = 1;
    int j = 0;

    while (result != -1 && result != 0) {
        result = read(fd, buff, 1);
        j += 1;
        buff += 1;
    }
    while (j > 0) {
        buff -= 1;
        j -= 1;
    }
}

int get_save(save_datas_t *datas, int save_nb)
{
    int fd = open(get_save_path(save_nb), O_RDONLY);
    char *buff = malloc(sizeof(char) * 11000);

    my_memset(buff, '\0', 11000);
    if (fd == -1) {
        write(2, "ERROR: issue with the open function\n", 37);
        return -1;
    }
    read_file(buff, fd);
    close(fd);
    fill_datas(datas, buff);
    free(buff);
    return 0;
}
