##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## MAKEFILE
##

SRC :=	src/main.c	\
		src/window.c \
		src/csfml.c \
		src/player.c \
		src/pnj.c \

OBJ := ${SRC:.c=.o}

NAME := my_rpg

CFLAGS := -g3 -Wall -Wextra -Iinclude

CSFML := -lcsfml-graphics -lcsfml-audio

CSFML2 := -lcsfml-window -lcsfml-system -lcsfml-network

all: $(NAME)

$(NAME):	${OBJ}
	$(CC) -o $(NAME) ${OBJ} ${CSFML} ${CSFML2} -O2

clean:
	rm -f $(NAME)
	rm -f *~
	rm -f vgcore*
	rm -f coding-style-reports.log*
	rm -f *.gcda
	rm -f *.gcno
	rm -f ${OBJ}
	rm -f ${TESTNAME}
	rm -f ${TESTOBJ}


fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re
