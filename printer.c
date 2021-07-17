/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 16:54:33 by ysonmez          ###   ########.fr       */
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

int	ft_print_type(t_struct *data)
{
	int	k;

	k = (*data).type;
	if (k == INTD || k == INTI)
		ft_putnbr_fd((*data).argint, data, 1);
	else if (k == CHAR)
		ft_putchar_fd((*data).argint, data, 1);
	else if (k == STR && (*data).argstr)
		ft_putstr_fd((*data).argstr, data, 1);
	else if (k == STR && !(*data).argstr)
		return (0);
	else if (k == LOWHEXA || k == UPHEXA)
		ft_puthexa_fd((*data).argunsint, data, 1);
	else if (k == PTR)
		ft_putunslong_fd((*data).argptr, data, 1);
	else if (k == UNSINT)
		ft_putunsint_fd((*data).argunsint, data, 1);
	else if (k == PRCT)
		ft_putchar_fd('%', data, 1);
	else
		return (-1);
	return (0);
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
