/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** my_getnbr
*/

#include "my.h"

static int get_is_neg(char *str, int *i);

int my_getnbr(char *str)
{
    int nbr = 0;
    int i = 0;
    int is_neg = get_is_neg(str, &i);

    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (nbr * is_neg);
        nbr *= 10;
        nbr += str[i] - '0';
    }
    return (nbr * is_neg);
}

static int get_is_neg(char *str, int *i)
{
    int is_neg = 1;

    for (; str[*i] != '\0'; *i += 1) {
        if (str[*i] == '-')
            is_neg *= -1;
        if (str[*i] >= '0' && str[*i] <= '9')
            return (is_neg);
    }
    return (is_neg);
}
