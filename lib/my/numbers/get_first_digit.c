/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_first_digit
*/

#include "my.h"

int get_first_digit(long nbr)
{
    while (nbr / 10 != 0)
        nbr /= 10;
    return ((int)nbr);
}
