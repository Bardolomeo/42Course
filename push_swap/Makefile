# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:01:07 by gsapio            #+#    #+#              #
#    Updated: 2024/01/20 14:50:07 by gsapio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY	=	utils.c utils_ii.c stack_alloc.c push_swap.c \
					operations.c operations_ii.c error_management.c push_swap_ii.c

LFLAGS = -lft

PATH_LIBS = -Llibft

LIBFT_PATH = libft

OBJS_MANDATORY	= $(SRCS_MANDATORY:.c=.o)

BONUS			=	checker.c error_management_bonus.c operations_bonus.c operations_ii_bonus.c \
					stack_alloc.c utils_ii.c utils.c

OBJS_BONUS		= $(BONUS:.c=.o)

HEADER			= ./

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap

BONUS_NAME		= checker

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME):		$(OBJS_MANDATORY)
				make -C $(LIBFT_PATH) --no-print-directory
				$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME) main.c $(PATH_LIBS) $(LFLAGS)

$(BONUS_NAME):	$(OBJS_BONUS)
				make -C $(LIBFT_PATH) --no-print-directory
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(PATH_LIBS) $(LFLAGS) -no-pie

bonus:			$(BONUS_NAME)

clean:
				$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)
				make clean -C $(LIBFT_PATH) --no-print-directory

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS_NAME)

re:				fclean all

.PHONY: re clean fclean all
