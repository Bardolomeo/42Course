# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:36:33 by gsapio            #+#    #+#              #
#    Updated: 2023/12/03 15:16:37 by gsapio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY	=	Mandatory/game_key_events.c \
					Mandatory/game_key_events_utils.c \
					Mandatory/invalid_map_manager_utils.c \
					Mandatory/invalid_map_manager.c \
					Mandatory/invalid_map_manager_utils_ii.c \
					Mandatory/populate_map.c \
					Mandatory/start_game.c \
					Mandatory/start_game_error_management.c

LFLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -no-pie

PATH_LIBS = -Llibft -Lmlx

LIBFT_PATH = libft

MLX_PATH = mlx

HEADER = /Mandatory

OBJS_MANDATORY	= $(SRCS_MANDATORY:.c=.o)

BONUS			=	Bonus/game_key_events_bonus.c \
					Bonus/game_key_events_utils_bonus.c \
					Bonus/inavlid_map_manager_utils_bonus.c \
					Bonus/invalid_map_manager_bonus.c \
					Bonus/invalid_map_manager_utils_ii_bonus.c \
					Bonus/loop_events_bonus.c \
					Bonus/loop_events_utils_bonus.c \
					Bonus/loop_events_utils_ii_bonus.c \
					Bonus/populate_map_bonus.c \
					Bonus/start_game_bonus.c \
					Bonus/start_game_error_management_bonus.c

OBJS_BONUS		= $(BONUS:.c=.o)

CC				= gcc -g

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long

BONUS_NAME		= so_long_bonus

all:			$(NAME)

call_mlx:
		echo "$(GREEN)Cloning 'mlx' via HTTP into './mlx'...$(DEF_COLOR)"; \
		git clone https://github.com/42Paris/minilibx-linux mlx;

Mandatory/%.o: Mandatory/%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME):		$(OBJS_MANDATORY)
				make -C $(LIBFT_PATH) --no-print-directory
				make -C $(MLX_PATH) --no-print-directory
				$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME) Mandatory/so_long.c $(PATH_LIBS) $(LFLAGS)

Bonus/%.o: Bonus/%.c
	$(CC) $(CFLAGS) -I /Bonus -c $< -o $@

$(BONUS_NAME):	$(OBJS_BONUS)
				make -C $(LIBFT_PATH) --no-print-directory
				make -C $(MLX_PATH) --no-print-directory
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) Bonus/so_long_bonus.c $(PATH_LIBS) $(LFLAGS)

bonus:			$(BONUS_NAME)

clean:
				$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) -r ./mlx
				$(RM) $(NAME)_bonus
				$(RM) $(LIBFT_PATH)/*.o
				$(RM) $(LIBFT_PATH)/*.a
				$(RM) $(MLX_PATH)/*.o
				$(RM) $(MLX_PATH)/*.a

re:				fclean call_mlx $(NAME)

.PHONY:			all clean fclean re bonus
