SRCS            =	${wildcard srcs/*.c}

OBJS		=	${SRCS:.c=.o}

NAME		= push_swap

RM		= rm -f

CC		= cc

CFLAGS		= -Wall -Wextra -Werror -Iincludes

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re
