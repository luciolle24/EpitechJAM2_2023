/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** clock
*/

#ifndef CLOCK_H_
    #define CLOCK_H_
    #include <SFML/System.h>
typedef struct clocks {
    sfClock *clock;
    sfUint32 time;
    sfUint32 interval;
} clocks_t;

int check_elapsed_time(clocks_t clocks);
clocks_t initialize_clock(int interval);
#endif /* !CLOCK_H_ */