##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## MAKEFILE
##

SRC	=	$(wildcard src/*.c)		\
		$(wildcard src/map/*.c)	\

TESTSRC	=	$(wildcard src/put/*.c)			\
			$(wildcard tests/put/*.c)	\

OBJ := ${SRC:.c=.o}

NAME := my_rpg

HEADER	=	my.h

TEST	=	uni_tests

CFLAGS := -Wall -Wextra -I ./include/

CSFML := -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):	${OBJ}
	$(CC) -o $(NAME) ${OBJ} ${CSFML} -lm $(CFLAGS) -g3

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
