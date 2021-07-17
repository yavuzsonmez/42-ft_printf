/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 17:41:49 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*new_struct(void)
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

static void	ft_setvarzero(int *count, int *i)
{
	*count = 0;
	*i = 0;
}

static void	ft_put_normal(char format, int *count, int *i)
{
	ft_putcharr_fd(format, 1);
	(*count)++;
	(*i)++;
}

int	ft_parse_format(va_list args, t_struct *data, const char *str)
{
	int	state;
	int	i;

	state = 0;
	i = 0;
	(*data).type = ft_get_type(str);
	(*data).chartype = ft_get_chartype(data);
	if ((*data).type == -1 || (*data).chartype == -1)
		return (-1);
	i = ft_set_format(data, str);
	if (i == -1)
		return (-1);
	state = ft_printer(args, data);
	if (state == -1)
		return (-1);
	return (2 + i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	*data;
	int			i;
	int			count;
	int			parser;

	va_start(args, format);
	ft_setvarzero(&count, &i);
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
			ft_put_normal(format[i], &count, &i);
	}
	va_end(args);
	return (count);
}
