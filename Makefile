# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:10:43 by ysonmez           #+#    #+#              #
#    Updated: 2021/07/19 11:18:59 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a

SRCS	=		ft_printf.c \
				format.c \
				set_len_type.c \
				print_type.c \
				printer.c \
				flags.c \

OBJS	=		$(SRCS:.c=.o)

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror

AR		=		ar rc

RAN		=		ranlib

RM		=		rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	
			make -C ./libft
			cp ./libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS)

bonus:		all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			cd ./libft && make fclean

all:		$(NAME)

re:			fclean all

.PHONY:		clean fclean all re bonus
