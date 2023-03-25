/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** list
*/

#include "my_rpg.h"

list_t *add_data_to_list_start(list_t *list, void *data)
{
    list_t *tmp = list;

    if (list == NULL) {
        list = malloc(sizeof(list_t));
        list->next = NULL;
        list->old = NULL;
        list->data = data;
        return (list);
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = malloc(sizeof(list_t));
    tmp->next->next = NULL;
    tmp->next->old = tmp;
    tmp->next->data = data;
    return (list);
}

list_t *add_data_to_list_end(list_t *list, void *data)
{
    list_t *tmp;

    if (list == NULL) {
        list = malloc(sizeof(list_t));
        list->next = NULL;
        list->old = NULL;
        list->data = data;
        return (list);
    }
    tmp = malloc(sizeof(list_t));
    tmp->next = list;
    list->old = tmp;
    tmp->old = NULL;
    tmp->data = data;
    return (tmp);
}

void destroy_list(list_t *list, void (*func_to_destroy)(void *data))
{
    list_t *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        if (func_to_destroy)
            func_to_destroy(tmp->data);
        free(tmp);
    }
}
