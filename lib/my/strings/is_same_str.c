/*
** EPITECH PROJECT, 2022
** lib
** File description:
** is_same_str
*/

#include "my.h"

int is_same_str(const char *str1, const char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (0);
    return (my_strlen(str1) == my_strlen(str2));
}

int is_same_str_n(const char *str1, const char *str2, int n)
{
    int len = my_strlen(str1);

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0' && i < n; i++)
        if (str1[i] != str2[i])
            return (0);
    return ((len == my_strlen(str2)) ? 1 : len == n);
}
