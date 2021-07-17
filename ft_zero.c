/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:12:01 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 14:16:56 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(t_struct *data)
{
	int i;

	i = 0;
	while (i < (*data).zero - (*data).alen)
	{
		ft_putchar_fd('0', data, 1);
		i++;
	}
	i = 0;
}

void	ft_prec(t_struct *data)
{
	if ((*data).argint < 0)
		while ((*data).prec > (*data).alen - 1 && (*data).type != STR)
		{
			ft_putchar_fd('0', data, 1);
			(*data).prec--;
		}
	else
		while ((*data).prec > (*data).alen && (*data).type != STR)
		{
			ft_putchar_fd('0', data, 1);
			(*data).prec--;
		}
}
