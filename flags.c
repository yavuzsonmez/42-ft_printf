/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 15:09:36 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_before(t_struct *data)
{
	if ((*data).width && (*data).minus == 0 && (*data).zero == 0)
		ft_width(data, (*data).type);
	if ((*data).argint < 0 && ((*data).type == INTD || (*data).type == INTI))
		ft_putchar_fd('-', data, 1);
	ft_hash(data);
	if ((*data).plus && ((*data).type == INTI || (*data).type == INTD)
		&& (*data).argint >= 0)
		ft_putchar_fd('+', data, 1);
	if ((*data).space && (*data).argint >= 0 && (*data).plus == 0
		&& ((*data).type == INTD || (*data).type == INTI))
		ft_putchar_fd(' ', data, 1);
	if ((*data).zero && (*data).minus == 0 && (*data).type != CHAR
		&& (*data).type != STR && (*data).type != PTR && (*data).type != PRCT)
		ft_zero(data);
	ft_prec(data);
}

void	ft_print_after(t_struct *data)
{
	while ((*data).minus > (*data).alen)
	{
		ft_putchar_fd(' ', data, 1);
		(*data).minus--;
	}
	if (((*data).type == INTD || (*data).type == INTI)
		&& (*data).argint == 0 && (*data).prec == 0)
	{
		while (0 <= (*data).minus - (*data).alen)
		{
			ft_putchar_fd(' ', data, 1);
			(*data).minus--;
		}
	}
}

int	ft_printf_atoi(const char *str)
{
	size_t	i;
	int		result;

	i = 1;
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + ((str[i] - 48) % 10);
		i++;
	}
	return (result);
}
