# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:10:43 by ysonmez           #+#    #+#              #
#    Updated: 2021/07/17 14:12:30 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a

SRCS	=		ft_printf.c \
				setup.c \
				format.c \
				flags.c \
				print_type.c \
				ft_width.c \
				ft_hash.c \
				ft_zero.c \

OBJS	=		$(SRCS:.c=.o)

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror

AR		=		ar rc

RAN		=		ranlib

RM		=		rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	*.c
			make -C ./libft
			cp ./libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS)

bonus:		all

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

all:		$(NAME)

re:			fclean all

.PHONY:		clean fclean all re bonus
