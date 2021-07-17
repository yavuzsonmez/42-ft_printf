/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:56:03 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 16:42:07 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_struct *data, int k)
{
	int	i;

	i = 0;
	if ((*data).width == (*data).prec)
		(*data).width = 0;
	if ((k == INTD || k == INTI) && (*data).argint == 0 && (*data).prec == 0)
	{
		while (i++ <= (*data).width - (*data).alen)
			ft_putchar_fd(' ', data, 1);
	}
	else if (k == STR && (*data).prec == 0)
	{
		while (i++ < (*data).width)
			ft_putchar_fd(' ', data, 1);
	}
	else if ((*data).alen)
	{
		while (i++ < (*data).width - (*data).alen)
			ft_putchar_fd(' ', data, 1);
	}
	else
	{
		while (i++ < (*data).width)
			ft_putchar_fd(' ', data, 1);
	}
}

void	ft_zero(t_struct *data)
{
	int	i;

	i = 0;
	while (i++ < (*data).zero - (*data).alen)
		ft_putchar_fd('0', data, 1);
}

void	ft_prec(t_struct *data)
{
	if ((*data).argint < 0)
	{
		while ((*data).prec > (*data).alen - 1 && (*data).type != STR)
		{
			ft_putchar_fd('0', data, 1);
			(*data).prec--;
		}
	}
	else
	{
		while ((*data).prec > (*data).alen && (*data).type != STR)
		{
			ft_putchar_fd('0', data, 1);
			(*data).prec--;
		}
	}
}

void	ft_hash(t_struct *data)
{
	if ((*data).hash && (*data).argunsint != 0 && (*data).type == LOWHEXA)
	{
		ft_putstr_fd("0x", data, 1);
		(*data).alen += 2;
	}
	else if ((*data).hash && (*data).argunsint != 0 && (*data).type == UPHEXA)
	{
		ft_putstr_fd("0X", data, 1);
		(*data).alen += 2;
	}
}
