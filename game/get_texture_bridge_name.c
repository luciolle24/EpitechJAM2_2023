/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** get_texture_bridge_name
*/

#include "game.h"

static int get_direction(char **m, vector2ul_t p, char c);
static int get_border(char **m, vector2ul_t p, char c);
static int get_around_count(char **m, vector2ul_t p, char c);

int get_texture_bridge_nbr(char **m, vector2ul_t p, char c)
{
    int count = get_around_count(m, p, c);

    if (count == 2)
        return (get_direction(m, p, c));
    return (get_border(m, p, c));
}

static int get_direction(char **m, vector2ul_t p, char c)
{
    if (m[p.y][p.x + 1] == c)
        return (6);
    return (5);
}

static int get_border(char **m, vector2ul_t p, char c)
{
    if (m[p.y][p.x + 1] == c)
        return (4);
    if (p.y > 0 && m[p.y - 1][p.x] == c)
        return (3);
    if (m[p.y + 1] != NULL && m[p.y + 1][p.x] == c)
        return (1);
    if (p.x > 0 && m[p.y][p.x - 1] == c)
        return (2);
    return (0);
}

static int get_around_count(char **m, vector2ul_t p, char c)
{
    int result = 0;

    result += (p.y > 0) && (m[p.y - 1][p.x] == c);
    result += (p.x > 0) && (m[p.y][p.x - 1] == c);
    result += (m[p.y][p.x + 1] == c);
    result += (m[p.y + 1] != NULL) && (m[p.y + 1][p.x] == c);
    return (result);
}
