/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 18:12:37 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_before(t_struct *data)
{
	int	k;
	int	i;

	k = (*data).type;
	i = 0;
	//printf("WIDTH : %d\n", (*data).width);
	if ((*data).width && (*data).minus == 0 && (*data).zero == 0)
	{
		if ((*data).alen)
			while (i < (*data).width - (*data).alen)
			{
				ft_putchar_fd(' ', data, 1);
				i++;
			}
		else
			while (i < (*data).width)
			{
				ft_putchar_fd(' ', data, 1);
				i++;
			}
		i = 0;
	}
	if ((*data).argint < 0 && (k == INTD || k == INTI))
		ft_putchar_fd('-', data, 1);
	if ((*data).hash && (*data).argunsint != 0 && k == LOWHEXA)
	{
		ft_putstr_fd("0x", data, 1);
		(*data).alen += 2;
	}
	else if ((*data).hash && (*data).argunsint != 0 && k == UPHEXA)
	{
		ft_putstr_fd("0X", data, 1);
		(*data).alen += 2;
	}
	if ((*data).plus && (k == INTI || k == INTD) && (*data).argint >= 0)
		ft_putchar_fd('+', data, 1);
	if ((*data).space && (*data).argint >=0 && (*data).plus == 0 && (k == INTD || k == INTI))
		ft_putchar_fd(' ', data, 1);
	if ((*data).zero && (*data).minus == 0 && k != CHAR && k != STR && k != PTR && k != PRCT)
	{
		while (i < (*data).zero - (*data).alen)
		{
			ft_putchar_fd('0', data, 1);
			i++;
		}
		i = 0;
	}
	while ((*data).prec > (*data).alen && (k != STR))
	{
		ft_putchar_fd('0', data, 1);
		(*data).prec--;
	}
}

void	ft_print_after(t_struct *data)
{
	int	i;
	int len;

	i = 0;
	len = (*data).alen;
	while ((*data).minus > len)
	{
		ft_putchar_fd(' ', data, 1);
		(*data).minus--;
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
