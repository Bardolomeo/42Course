# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 18:33:21 by gsapio            #+#    #+#              #
#    Updated: 2023/11/10 12:09:47 by gsapio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_charandstr.c ft_intanduns.c ft_printf.c ft_hexvalues.c
OBJS			=	${SRCS:.c=.o}
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(HEADER)
RM				=	rm -fr
NAME			=	libftprintf.a
HEADER			=	ft_printf.h

all:			${NAME}

$(NAME):		$(OBJS) $(HEADER)
				ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re
