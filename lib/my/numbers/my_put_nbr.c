/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_put_nbr
*/

#include "my.h"
#include <stdio.h>

void my_put_nbr(long nbr)
{
    int digit = 0;
    int len = get_number_len(nbr);
    int len_tmp;

    for (int i = 0; i < len; i++) {
        digit = get_first_digit(nbr);
        my_put_char(digit + '0');
        len_tmp = get_number_len(nbr);
        len_tmp = my_pow(10, (len_tmp == 0) ? 0 : len_tmp - 1);
        nbr -= digit * len_tmp;
    }
}
