##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib's Makefile
##

SRC	=	$(wildcard my_printf/*.c)	\
		$(wildcard my/*.c)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
