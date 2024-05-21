##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## MAKEFILE
##

SRC	=	$(wildcard src/*.c)		\

TESTSRC	=	$(wildcard src/put/*.c)			\
			$(wildcard tests/put/*.c)	\

OBJ := ${SRC:.c=.o}

NAME := my_rpg

HEADER	=	my.h

TEST	=	uni_tests

CFLAGS := -g3 -Wall -Wextra -I ./include

CSFML := -lcsfml-graphics -lcsfml-audio

CSFML2 := -lcsfml-window -lcsfml-system -lcsfml-network

all: $(NAME)

$(NAME):	${OBJ}
	$(CC) -o $(NAME) ${OBJ} ${CSFML} ${CSFML2} -O2 -lm $(CFLAGS)

clean:
	rm -f $(NAME)
	rm -f *~
	rm -f vgcore*
	rm -f coding-style-reports.log*
	rm -f *.gcda
	rm -f *.gcno
	rm -f ${OBJ}
	rm -f ${TEST}

fclean: clean
	rm -f $(NAME)

re: fclean clean all

$(TEST):	fclean
	$(CC) -o $(TEST) $(TESTSRC) --coverage -lcriterion $(CFLAGS)

tests_run:	$(TEST)
	./$(TEST)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	all clean fclean re $(TEST) tests_run
