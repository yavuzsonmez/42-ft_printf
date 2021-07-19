/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:51:21 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/19 10:05:58 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_count_digit_unsint(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_count_digit_hexa(unsigned long n, t_struct *data)
{
	if (n >= 16)
		ft_count_digit_hexa(n / 16, data);
	(*data).alen++;
}

int	ft_get_type(const char *str)
{
	while (*str)
	{
		if (*str == 'd')
			return (INTD);
		else if (*str == 'i')
			return (INTI);
		else if (*str == 'c')
			return (CHAR);
		else if (*str == 's')
			return (STR);
		else if (*str == 'p')
			return (PTR);
		else if (*str == 'x')
			return (LOWHEXA);
		else if (*str == 'X')
			return (UPHEXA);
		else if (*str == 'u')
			return (UNSINT);
		else if (*str == '%')
			return (PRCT);
		str++;
	}
	return (-1);
}

int	ft_get_chartype(t_struct *data)
{
	int	k;

	k = (*data).type;
	if (k == INTD)
		return ('d');
	else if (k == INTI)
		return ('i');
	else if (k == CHAR)
		return ('c');
	else if (k == STR)
		return ('s');
	else if (k == PTR)
		return ('p');
	else if (k == LOWHEXA)
		return ('x');
	else if (k == UPHEXA)
		return ('X');
	else if (k == UNSINT)
		return ('u');
	else if (k == PRCT)
		return ('%');
	return (-1);
}
