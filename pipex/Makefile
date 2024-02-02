# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:01:07 by gsapio            #+#    #+#              #
#    Updated: 2024/01/23 22:28:08 by gsapio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY	= main.c error_management.c pipex.c utils.c

LFLAGS = -lft

PATH_LIBS = -Llibft

LIBFT_PATH = libft

OBJS_MANDATORY	= $(SRCS_MANDATORY:.c=.o)

BONUS			= main_bonus.c error_management_bonus.c pipex.c utils.c pipex_bonus.c

OBJS_BONUS		= $(BONUS:.c=.o)

HEADER			= ./

CC				= cc -g

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= pipex

BONUS_NAME		= pipex_bonus

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME):		$(OBJS_MANDATORY)
				rm -f pipex
				make -C $(LIBFT_PATH) --no-print-directory
				make bonus -C $(LIBFT_PATH) --no-print-directory
				$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME) $(PATH_LIBS) $(LFLAGS)

bonus:			${BONUS_NAME}

${BONUS_NAME}:	$(OBJS_BONUS)
				make -C ./libft
				$(CC) $(CFLAGS) ${OBJS_BONUS} -Llibft -lft -o pipex -no-pie

clean:
				$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
				make clean -C $(LIBFT_PATH) --no-print-directory

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS_NAME)

re:				fclean all

.PHONY: re clean fclean all
