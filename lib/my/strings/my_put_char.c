/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_put_char
*/

#include <unistd.h>
#include "my.h"

void my_put_char(const char c)
{
    write(1, &c, 1);
}
