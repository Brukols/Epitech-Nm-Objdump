##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## nmobjdump
##

NAME_OBJDUMP	=	my_objdump

NAME_NM		=	my_nm

NAME_TESTS	=	unit_tests

SRCS_NM		=		nm/src/main.c	\

SRCS_OBJDUMP	=	objdump/src/main.c	\
					objdump/src/objdump.c	\
					objdump/src/display_information.c	\
					objdump/src/display_overall_header.c	\

SRCS_TESTS	=	\

OBJS_NM	=	$(SRCS_NM:.c=.o)

OBJS_OBJDUMP	=	$(SRCS_OBJDUMP:.c=.o)

OBJS_TESTS		=	$(SRCS_TESTS:.c=.o)

CFLAGS	=	-W -Wall -Wextra

LDFLAGS	=	\

CC	=	gcc

RM		=		rm -f

all: nm objdump

nm: $(NAME_NM)

objdump: $(NAME_OBJDUMP)

$(NAME_NM): $(OBJS_NM)
			$(CC) -o $(NAME_NM) $(OBJS_NM) $(LDFLAGS)

$(NAME_OBJDUMP): $(OBJS_OBJDUMP)
			$(CC) -o $(NAME_OBJDUMP) $(OBJS_OBJDUMP) $(LDFLAGS)

clean:
	$(RM) $(OBJS_NM)
	$(RM) $(OBJS_OBJDUMP)

fclean: clean
	$(RM) $(NAME_NM)
	$(RM) $(NAME_OBJDUMP)

re: fclean all

re_nm: fclean nm
re_objdump: fclean objdump

tests_run:	LDFLAGS += -lcriterion --coverage
tests_run: 	CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: fclean $(OBJS_TESTS)
			$(CC) -o $(NAME_TESTS) $(OBJS_TESTS) $(LDFLAGS)
			./$(NAME_TESTS)

debug: CFLAGS += -g
debug: re

.PHONY: all nm objdump clean fclean re debug tests_run re_nm re_objdump