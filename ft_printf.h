/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:13:02 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 17:41:40 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define INTD 0
# define INTI 1
# define CHAR 2
# define STR 3
# define PTR 4
# define LOWHEXA 5
# define UPHEXA 6
# define UNSINT 7
# define PRCT 8

int			ft_count_digit(int n);
void		ft_count_digit_hexa(unsigned long n, t_struct *data);
int			ft_count_digit_unsint(unsigned int n);
int			ft_get_type(const char *str);
int			ft_get_chartype(t_struct *data);
int			ft_set_format(t_struct *data, const char *str);
int			ft_print_type(t_struct *data);
void		ft_arg_len(va_list args, t_struct *data);
int			ft_printer(va_list args, t_struct *data);
void		ft_puthexa_fd(unsigned int n, t_struct *data, int fd);
void		ft_putunslong_fd(unsigned long n, t_struct *data, int fd);
void		ft_putunsint_fd(unsigned int n, t_struct *data, int fd);
void		ft_putcharr_fd(char c, int fd);
void		ft_print_before(t_struct *data);
void		ft_print_after(t_struct *data);
void		ft_width(t_struct *data, int k);
void		ft_hash(t_struct *data);
void		ft_zero(t_struct *data);
void		ft_prec(t_struct *data);
int			ft_printf_atoi(const char *str);

int			ft_parse_format(va_list args, t_struct *data, const char *str);
int			ft_printf(const char *str, ...);

#endif
