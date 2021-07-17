/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 15:45:01 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*new_struct(void)
{
	t_struct	*p_data;

	p_data = (t_struct *)malloc(sizeof(t_struct));
	(*p_data).hash = 0;
	(*p_data).space = 0;
	(*p_data).plus = 0;
	(*p_data).zero = 0;
	(*p_data).minus = 0;
	(*p_data).prec = -1;
	(*p_data).width = 0;
	(*p_data).alen = 0;
	(*p_data).print = 0;
	(*p_data).type = 0;
	(*p_data).chartype = 0;
	(*p_data).argint = 0;
	(*p_data).argstr = 0;
	(*p_data).argptr = 0;
	(*p_data).argunsint = 0;
	return (p_data);
}

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
