/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** clock_utility
*/


#include "clock.h"

int check_elapsed_time(clocks_t clocks)
{
    clocks.time = sfClock_getElapsedTime(clocks.clock).microseconds;
    if (clocks.time > clocks.interval) {
        sfClock_restart(clocks.clock);
        return (1);
    }
    return (0);
}

clocks_t initialize_clock(int interval)
{
    clocks_t clocks;
    clocks.clock = sfClock_create();
    clocks.interval = interval;
    return (clocks);
}
