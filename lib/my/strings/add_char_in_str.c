/*
** EPITECH PROJECT, 2022
** lib
** File description:
** add_char_in_str
*/

#include <stdlib.h>
#include "my.h"

char *add_char_in_str(const char *str, const char c, int pos)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 2));
    int offset = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (i == pos) {
            result[i] = c;
            offset++;
        }
        result[i + offset] = str[i];
    }
    if (i == pos) {
        result[i] = c;
        offset++;
    }
    result[i + offset] = '\0';
    return (result);
}
