##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=

OBJ	=	$(SRC:.c=.o)

NAME	=

CFLAGS	=

all:	clean

clean:
		rm -f $(OBJ)
		rm -f *~
		rm -f *#

fclean:		clean
		rm -f $(NAME)

re:	fclean all
