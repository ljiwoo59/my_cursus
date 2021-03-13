CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = ./srcs/
INCDIR = ./includes/

TARGET = BSQ
SOURCES = ft_print.c ft_solve.c main.c ft_atoi.c filetostr.c checking.c
SRCS = ${addprefix ${SRCDIR}, ${SOURCES}}
OBJS = ${SRCS:.c=.o}

all : ${TARGET}

${OBJS} : ${SRCS}
	${CC} ${CFLAGS} -I ${INCDIR} -c ${@:.o=.c} -o $@

${TARGET} : ${OBJS}
	${CC} -o ${TARGET} ${OBJS}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${TARGET}

re : fclean all

.PHONY : clean fclean re all
