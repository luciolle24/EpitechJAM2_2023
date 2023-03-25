##
## EPITECH PROJECT, 2021
## task02
## File description:
## Makefile
##

SRC = strings/my_put_char.c\
	  strings/my_putstr.c\
	  strings/my_strlen.c\
	  strings/is_same_str.c\
	  strings/add_char_in_str.c\
	  strings/add_str_in_str.c\
	  strings/my_strdup.c\
	  numbers/get_first_digit.c\
	  numbers/get_number_len.c\
	  numbers/my_pow.c\
	  numbers/my_put_nbr.c\
	  numbers/my_getnbr.c

OBJ = ${SRC:.c=.o}
MYLIB = libmy.a
INCLUDE_CMD = -I../../include/
NAME = libmy.a

all:
	@echo -e "\e[95mCompilings lib"
	@make ${NAME} -s

${NAME}: ${OBJ}
	@ar rc ${MYLIB} ${OBJ}

%.o: %.c
	@echo -e -n "\e[96m  - $<\n"
	@gcc -c ${INCLUDE_CMD} $< -o $@ -g3

clean:
	@echo -e "\e[95mOn lib"
	@rm -f ${OBJ}
	@rm -f lib/libmy.a
	@rm -f lib/my/libmy.a
	@echo -e "\e[96m  - deleting *.o\e[0m"

fclean: clean
	@rm -f ${NAME}
	@echo -e "\e[96m  - deleting ${NAME}\e[0m"

re: fclean all
