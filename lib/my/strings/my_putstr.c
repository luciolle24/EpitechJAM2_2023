/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_putstr
*/

#include "my.h"
#include <unistd.h>

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
