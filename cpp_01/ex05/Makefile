NAME =	harl

SRCS =	main.cpp \
		Harl.cpp \

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS =	${SRCS:.cpp=.o}

RM = rm -rf

all:	${NAME}

.c.o:
	${CC} ${CPPFLAGS} -c $< -o

${NAME}:	${OBJS}
			${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
