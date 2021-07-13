# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:10:43 by ysonmez           #+#    #+#              #
#    Updated: 2021/07/13 19:19:37 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a

SRCS	=		ft_printf.c \
				utilities.c \
				print_type.c \


OBJS	=		$(SRCS:.c=.o)

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror

AR		=		ar rc

RAN		=		ranlib

RM		=		rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	*.c
			Make -C ./libft
			cp ./libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -c $(SRCs)
			$(AR) $(NAME) $(OBJS)

bonus:		all

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

all:		$(NAME)

re:			fclean all

.PHONY:		clean fclean all re bonus
