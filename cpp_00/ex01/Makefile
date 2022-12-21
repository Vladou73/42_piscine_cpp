# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 14:31:42 by vnafissi          #+#    #+#              #
#    Updated: 2022/12/21 14:10:30 by vnafissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	phonebook

SRCS = Phonebook.cpp Contact.cpp main.cpp

CC = c++

CPPFLAGS = -Wall -Wextra -Werror #-std=c++98

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
