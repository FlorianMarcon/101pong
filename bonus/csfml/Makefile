##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=       src/pong.c \
                src/analyseEvt.c  \
		src/delete_pix.c  \
		src/putball.c  \
		src/putplayspace.c  \
		src/put_racket.c  \


OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS	=	-W -Wall -Wextra -Werror -I./include

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re:	fclean all
