/*
** EPITECH PROJECT, 2022
** lib
** File description:
** add_str_in_str
*/

#include <stdlib.h>
#include "my.h"

static void add_seg(char *str, const char *seg);

char *add_str_in_str(const char *str1, const char *str2, int pos)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result = malloc(sizeof(char) * (len1 + len2 + 2));
    int offset = 0;
    int i = 0;

    for (i = 0; str1[i] != '\0'; i++) {
        if (i == pos) {
            add_seg(&result[i], str2);
            offset = len2;
        }
        result[i + offset] = str1[i];
    }
    if (i == pos) {
        add_seg(&result[i], str2);
        offset = len2;
    }
    result[i + offset] = '\0';
    return (result);
}

static void add_seg(char *str, const char *seg)
{
    for (int i = 0; seg[i] != '\0'; i++)
        str[i] = seg[i];
}
