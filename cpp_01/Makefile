# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 14:31:42 by vnafissi          #+#    #+#              #
#    Updated: 2022/12/21 17:21:50 by vnafissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	zombie

SRCS = Zombie.cpp main.cpp

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
