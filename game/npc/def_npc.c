/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_npc
*/

#include "game.h"

npc_t *def_npc(sprite_info_t info, char *name, sfVector2f center)
{
    npc_t *new_pnj = malloc(sizeof(*new_pnj));

    new_pnj->info = info;
    new_pnj->next = NULL;
    new_pnj->npc = def_simple_elem(name);
    init_sprite(new_pnj->npc.pict, center, info);
    return new_pnj;
}

void add_npc(sprite_info_t info, char *name, sfVector2f center, npc_t *pnj)
{
    if (pnj->next != NULL)
        return add_npc(info, name, center, pnj->next);
    pnj->next = def_npc(info, name, center);
}

npc_t *def_all_npc(sfView *view)
{
    sfVector2f center = sfView_getCenter(view);
    sprite_info_t info;
    npc_t *all_npc;

    info = init_info((sfVector2f){1000, 1000}, (sfVector2f){75, 75}, info);
    all_npc = def_npc(info, "asset/characters/NPC_A.png", center);
    info = init_info((sfVector2f){1150, 1000}, (sfVector2f){75, 75}, info);
    add_npc(info, "asset/characters/NPC_C.png", center, all_npc);
    return all_npc;
}
