/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

// Strings
void my_put_char(const char c);
int my_strlen(const char *str);
void my_putstr(const char *str);
int is_same_str(const char *str1, const char *str2);
int is_same_str_n(const char *str1, const char *str2, int n);
char *add_char_in_str(const char *str, const char c, int pos);
char *add_str_in_str(const char *str1, const char *str2, int pos);
char *my_strdup(char *str);

// Numbers
int get_first_digit(long nbr);
int get_number_len(long nbr);
long my_pow(long x, unsigned long y);
void my_put_nbr(long nbr);
int my_getnbr(char *str);

#endif /* !MY_H_ */
