/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/15 17:01:35 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <printf.h>

void	ft_print_before(t_struct *data)
{
	int	k;
	int i;

	k = (*data).type;
	i = 0;
	if ((*data).width && (*data).argint == 0 && (*data).plen == 1 && (*data).prec == 0)
		ft_putchar_fd(' ', data, 1);
	if ((*data).width)
	{
		while (i < (*data).width - ((*data).alen) - ((*data).prec))
		{
			ft_putchar_fd(' ', data, 1);
			i++;
		}
		i = 0;
	}
	if ((*data).argint < 0 && (k == INTD || k == INTI))
		ft_putchar_fd('-', data, 1);
	if ((*data).hash && (*data).argunsint != 0 && k == LOWHEXA)
		ft_putstr_fd("0x", data, 1);
	else if ((*data).hash && (*data).argunsint != 0 && k == UPHEXA)
		ft_putstr_fd("0X", data, 1);
	if ((*data).plus && (k == INTI || k == INTD) && (*data).argint >= 0)
		ft_putchar_fd('+', data, 1);
	if ((*data).space && (*data).plus == 0 && (k == INTD || k == INTI))
		ft_putchar_fd(' ', data, 1);
	if ((*data).zero && (k == INTD || k == INTI || k == LOWHEXA|| k == UPHEXA || k == UNSINT))
	{
		while (i < (*data).zero - (*data).alen)
		{
			ft_putchar_fd('0', data, 1);
			i++;
		}
		i = 0;
	}
	if ((*data).prec && k != PTR && k != STR)
	{
		while (i < (*data).prec - (*data).alen)
		{
			ft_putchar_fd('0', data, 1);
			i++;
		}
	}
}

void	ft_print_after(t_struct *data)
{
	int i;
	int x;
	int k;

	i = 0;
	x = (*data).prec - (*data).alen;
	k = (*data).minus - x - (*data).alen;
	//printf("X : %d\nK : %d\n", x, k);
	//printf("ALEN : %d\nARGINT : %d\nPLEN : %d\nPREC : %d\nWIDTH : %d\nMINUS : %d\n",(*data).alen, (*data).argint, (*data).plen, (*data).prec, (*data).width, (*data).minus);
	//if ((*data).minus && (*data).plen == 1 && (*data).prec == 0)
	//	ft_putchar_fd(' ', data, 1);
	if ((*data).minus)
	{
		while (i < k)
		{
			ft_putchar_fd(' ', data, 1);
			i++;
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
