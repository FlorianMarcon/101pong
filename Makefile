##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS	=	-W -Wall -Wextra -Werror 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(NAME)

re:	fclean all
