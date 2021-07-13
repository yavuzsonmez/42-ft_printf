/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/13 19:00:24 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	*data;
	size_t		i;
	int			parser;

	va_start(args, str);
	data = new_struct();
	i = 0;
	parser = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			parser = ft_parse_format(args, data, str + i + 1);
			if (parser == -1)
				return (-1);
			else
				i += parser;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return ((*data).print);
}
