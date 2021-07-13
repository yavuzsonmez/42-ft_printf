/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:13:02 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/13 20:05:44 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define INT 0
# define CHAR 1
# define STR 2
# define PTR 3
# define LOWHEXA 4
# define UPHEXA 5
# define UNSINT 6
# define PRCT 7

typedef struct s_struct
{
	int				hash;
	int				space;
	int				plus;
	int				zero;
	int				minus;
	int				prec;
	int				width;
	int				flen;
	int				alen;
	int				print;
	int				type;
	int				argint;
	char			*argstr;
	unsigned long	argptr;
	unsigned int	argunsint;
}	t_struct;

t_struct	*new_struct(void);
int			ft_count_digit(int n);
int			ft_count_digit_long(unsigned long n);
int			ft_get_type(const char *str);
int			ft_set_format(t_struct *data, const char *str);
void		ft_print_type(t_struct *data);
void		ft_arg_len(va_list args, t_struct *data);
void		ft_printer(va_list args, t_struct *data);
int			ft_parse_format(va_list args, t_struct *data, const char *str);
void		ft_puthexa_fd(unsigned long n, t_struct *data, int fd);
void		ft_putunsint_fd(unsigned int n, t_struct *data, int fd);

int			ft_printf(const char *str, ...);

#endif
