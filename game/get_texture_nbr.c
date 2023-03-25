/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** get_texture_nbr
*/

#include "game.h"

static int get_texture_nbr_2(char **m, vector2ul_t p, char c, int nbr);
static int get_texture_nbr_3(char **m, vector2ul_t p, char c, int nbr);
static int get_around_count(char **m, vector2ul_t p, char c);

int get_texture_nbr(char **m, vector2ul_t p, char c)
{
    int nbr = get_around_count(m, p, c);
    int cond;

    if (c == ' ')
        return (rand() % 4 + 1);
    if (nbr == 4 || nbr == 0 || nbr == 1)
        return (5);
    return (get_texture_nbr_2(m, p, c, nbr));
}

static int get_texture_nbr_2(char **m, vector2ul_t p, char c, int nbr)
{
    int cond = p.x > 0 && m[p.y][p.x - 1] == c;

    if (nbr == 2) {
        if (m[p.y][p.x + 1] == c && m[p.y + 1] != NULL && m[p.y + 1][p.x] == c)
            return (1);
        if (cond && m[p.y + 1] != NULL && m[p.y + 1][p.x] == c)
            return (3);
        if (m[p.y][p.x + 1] == c && p.y > 0 && m[p.y - 1][p.x] == c)
            return (7);
        if (p.x > 0 && m[p.y][p.x - 1] == c && p.y > 0 && m[p.y - 1][p.x] == c)
            return (9);
    }
    return (get_texture_nbr_3(m, p, c, nbr));
}

static int get_texture_nbr_3(char **m, vector2ul_t p, char c, int nbr)
{
    int cond = p.x > 0 && m[p.y][p.x - 1] == c && m[p.y][p.x + 1] == c;

    if (nbr == 3) {
        if (cond && m[p.y + 1] != NULL && m[p.y + 1][p.x] == c)
            return (2);
        cond = p.x > 0 && m[p.y][p.x - 1] == c && m[p.y][p.x + 1] == c;
        if (cond && p.y > 0 && m[p.y - 1][p.x] == c)
            return (8);
        cond = p.y > 0 && m[p.y - 1][p.x] == c && m[p.y + 1] != NULL;
        if (cond && m[p.y + 1][p.x] == c && m[p.y][p.x + 1] == c)
            return (4);
        cond = p.y > 0 && m[p.y - 1][p.x] == c && m[p.y + 1] != NULL;
        if (cond && m[p.y + 1][p.x] == c && p.x > 0 && m[p.y][p.x - 1] == c)
            return (6);
    }
    return (5);
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
