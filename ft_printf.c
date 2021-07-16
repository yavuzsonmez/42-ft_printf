/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yavuzsonmez <yavuzsonmez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 09:11:25 by yavuzsonmez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	*data;
	int			i;
	int			count;
	int			parser;

	va_start(args, format);
	i = 0;
	count = 0;
	parser = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			data = new_struct();
			parser = ft_parse_format(args, data, format + i + 1);
			if (parser == -1)
				return (-1);
			i += parser;
			count += (*data).print;
			free(data);
		}
		else
		{
			ft_putcharr_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
