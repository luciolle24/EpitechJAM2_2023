/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_pow
*/

#include "my.h"
#include <stdio.h>

long my_pow(long x, unsigned long y)
{
    long result = x;

    if (y == 0)
        return (1);
    for (unsigned long i = 0; i < y - 1; i++)
        result *= x;
    return (result);
}
