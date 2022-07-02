##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

SRC	=	$(wildcard sources/get_command/*.c)	\
		$(wildcard sources/main_function/*.c)	\
		$(wildcard sources/check_system_call/*.c)	\
		$(wildcard sources/execute_command/*.c)	\
		$(wildcard sources/create_env/*.c)	\
		$(wildcard sources/new_commands/*.c)	\
		$(wildcard sources/new_commands/setenv/*.c)	\

TESTS	=	$(wildcard tests/*.c)

MAIN	=	sources/main.c

OBJ	=	$(SRC:.c=.o)

LIBFLAGS	=	-L./lib -lmy

ERRORFLAGS	=	-Werror -Wall -pedantic

CRITERIONFLAGS	=	-lcriterion --coverage

NAME	=	mysh

CFLAGS	=	-g3

all:	$(NAME)


$(NAME):	$(OBJ)
	make -C lib/
	gcc -o  $(NAME) $(MAIN) $(OBJ) $(LIBFLAGS) $(ERRORFLAGS)

clean:
	rm -f $(OBJ)
	make clean -s -C lib

fclean:	clean
	rm -f $(NAME)
	rm -f unit*
	rm -f unit_tests
	make fclean -s -C lib

unit_tests: fclean
	make -C lib/
	gcc -o unit_tests $(SRC) $(TESTS) $(CRITERIONFLAGS)	\
	$(LIBFLAGS)

tests_run:	unit_tests
	./unit_tests

re:	fclean all

.PHONY: all clean fclean re unit_tests tests_run
