/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cut_scene_loop
*/

#include "cutscene.h"

static cutscene_t *init_cutscene(void);
static void add_data(cutscene_t *cutsn, char *dialogue, int id, char *bc);
void handling_cutsc(ret_values_t *value, cutscene_t *cut, char *tmp, char *bc);

cutscene_t *open_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    char *tmp = NULL;
    ssize_t line_size = 0;
    ret_values_t *values = init_cutcene_values();
    cutscene_t *cutscene = init_cutscene();
    char *bc;

    if (!fp) {
        cutscene->exit = -1;
        return (cutscene);
    }
    line_size = getline(&tmp, &line_size, fp);
    bc = my_strdup(tmp);
    bc[line_size - 1] = '\0';
    while (line_size >= 0) {
        line_size = getline(&tmp, &line_size, fp);
        handling_cutsc(values, cutscene, my_strdup(tmp), bc);
    }
    fclose(fp);
    return (cutscene);
}

static cutscene_t *init_cutscene(void)
{
    cutscene_t *cutscene = malloc(sizeof(*cutscene));

    cutscene->id = 0;
    cutscene->dialogues = NULL;
    cutscene->next = NULL;
    cutscene->exit = 0;
    return (cutscene);
}

static void add_data(cutscene_t *cutsn, char *dialogue, int id, char *bc)
{
    if (cutsn->next != NULL)
        return (add_data(cutsn->next, dialogue, id, bc));
    cutsn->next = init_cutscene();
    cutsn->dialogues = dialogue;
    cutsn->id = id;
    cutsn->background = my_strdup(bc);
}

void free_cutscene(cutscene_t *cutscene)
{
    if (cutscene->next != NULL)
        free_cutscene(cutscene->next);
    free(cutscene);
}

void handling_cutsc(ret_values_t *value, cutscene_t *cut, char *tmp, char *bc)
{
    if (value->counter == 1) {
        value->talking = my_getnbr(tmp);
        value->counter = 0;
    } else {
        add_data(cut, my_strdup(tmp), value->talking, bc);
        value->counter = 1;
    }
}
