/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *buffer = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        buffer[i] = str[i];
    buffer[len] = '\0';
    return (buffer);
}
