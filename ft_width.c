/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:56:03 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 14:45:39 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_struct *data)
{
	int	k;
	int	i;

	k = (*data).type;
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
