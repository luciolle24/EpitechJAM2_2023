/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** time
*/

float *get_time_elapsed(void)
{
    static float time_elapsed = 0;

    return (&time_elapsed);
}

float *get_delta_time(void)
{
    static float delta_time = 0;

    return (&delta_time);
}
