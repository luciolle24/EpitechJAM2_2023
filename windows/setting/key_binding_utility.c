/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** key_binding_utility
*/

#include "my_rpg.h"

char *letter_to_string(char letter)
{
    char *string = malloc(sizeof(char) * 2);

    string[0] = letter;
    string[1] = '\0';
    return string;
}
