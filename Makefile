# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 16:08:48 by ftataje-          #+#    #+#              #
#    Updated: 2022/09/27 12:04:07 by ftataje-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
PROG_B  = pipex_bonus

SRCS 	= pipex.c utils.c ft_strjoin.c ft_strnstr.c ft_split.c ft_strlen.c ft_strncmp.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= pipex.c

SRCS_B	= pipex_bonus.c utils.c utils_bonus.c ft_strjoin.c ft_strnstr.c ft_split.c ft_strlen.c ft_strncmp.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= pipex_bonus.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "\033[33m----Compiling----"
					@$(CC) ${OBJS} -o ${NAME}

bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
					@echo "\033[33m----Compiling Bonus----"
					@$(CC) ${OBJS_B} -o ${PROG_B}

clean:
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@rm -f $(NAME)
					@rm -f ${PROG_B}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus