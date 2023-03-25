/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** get_texture
*/

#include "game.h"

static sfTexture *get_texture_from_str(list_t *images, char *str);
static char *get_texture_name(char **map, vector2ul_t pos, char *strat_name);

sfTexture *get_texture_from_char(char **map, list_t *images, size_t x, \
size_t y)
{
    char *name;
    vector2ul_t pos = {x, y};

    switch (map[y][x]) {
        case (' '): name = get_texture_name(map, pos, "grass");
            return (get_texture_from_str(images, name));
        case ('x'): name = get_texture_name(map, pos, "mountain");
            return (get_texture_from_str(images, name));
        case ('o'): name = get_texture_name(map, pos, "water");
            return (get_texture_from_str(images, name));
        case ('a'): name = get_texture_name(map, pos, "mountain");
            return (get_texture_from_str(images, name));
        case ('p'): name = get_texture_name(map, pos, "bridge");
            return (get_texture_from_str(images, name));
        default: return (NULL);
    }
}

static sfTexture *get_texture_from_str(list_t *images, char *str)
{
    while (images != NULL) {
        if (is_same_str(((image_t *)images->data)->name, str)) {
            free(str);
            return (((image_t *)images->data)->texture);
        }
        images = images->next;
    }
    free(str);
    return (NULL);
}

static char *get_texture_name(char **map, vector2ul_t pos, char *strat_name)
{
    int len = my_strlen(strat_name);
    char *name = malloc(sizeof(*name) * (len + 6));
    int nbr = 0;

    if (map[pos.y][pos.x] == 'p')
        nbr = get_texture_bridge_nbr(map, pos, map[pos.y][pos.x]);
    else
        nbr = get_texture_nbr(map, pos, map[pos.y][pos.x]);
    for (int i = 0; i < len; i++)
        name[i] = strat_name[i];
    name[len] = nbr + '0';
    name[len + 1] = '.';
    name[len + 2] = 'p';
    name[len + 3] = 'n';
    name[len + 4] = 'g';
    name[len + 5] = '\0';
    return (name);
}
