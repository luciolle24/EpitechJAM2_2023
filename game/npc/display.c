/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** display
*/

#include "game.h"

void display_npc(npc_t *all_pnj, sfRenderWindow *window)
{
    if (all_pnj->next != NULL)
        display_npc(all_pnj->next, window);
    sfRenderWindow_drawRectangleShape(window, all_pnj->npc.pict, NULL);
}
