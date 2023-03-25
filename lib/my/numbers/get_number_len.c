/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_number_len
*/

#include "my.h"

int get_number_len(long nbr)
{
    int len = 0;

    while (nbr != 0) {
        nbr /= 10;
        len++;
    }
    return (len);
}
