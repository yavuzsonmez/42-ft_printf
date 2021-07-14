/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:13:02 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/14 14:06:01 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define INTd 0
# define INTi 1
# define CHAR 2
# define STR 3
# define PTR 4
# define LOWHEXA 5
# define UPHEXA 6
# define UNSINT 7
# define PRCT 8

t_struct	*new_struct(void);
int			ft_count_digit(int n);
int			ft_count_digit_long(unsigned long n);
int			ft_get_type(const char *str);
int			ft_get_chartype(t_struct *data);
int			ft_set_format(t_struct *data, const char *str);
int			ft_print_type(t_struct *data);
void		ft_arg_len(va_list args, t_struct *data);
int			ft_printer(va_list args, t_struct *data);
int			ft_parse_format(va_list args, t_struct *data, const char *str);
void		ft_puthexa_fd(unsigned long n, t_struct *data, int fd);
void		ft_putunsint_fd(unsigned int n, t_struct *data, int fd);
void		ft_putcharr_fd(char c, int fd);

int			ft_printf(const char *str, ...);

#endif
