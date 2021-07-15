/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:51:21 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/15 16:50:09 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h>

t_struct	*new_struct(void)
{
	t_struct	*p_data;

	p_data = (t_struct *)malloc(sizeof(t_struct));
	(*p_data).hash = 0;
	(*p_data).space = 0;
	(*p_data).plus = 0;
	(*p_data).zero = 0;
	(*p_data).minus = 0;
	(*p_data).prec = 0;
	(*p_data).width = 0;
	(*p_data).plen = 0;
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

int	ft_count_digit(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (10);
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

int	ft_count_digit_long(unsigned long n)
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

int	ft_set_format(t_struct *data, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (*data).chartype)
	{
		if (str[i] >= '1' && str[i] <= '9' && (*data).width == 0)
			(*data).width = ft_printf_atoi(str - 1);
		else if (str[i] == '.' && (*data).prec == 0)
		{
			(*data).prec = ft_printf_atoi(str + i);
			(*data).plen = 1;
		}
		else if (str[i] == '#' && (*data).hash == 0)
			(*data).hash = 1;
		else if (str[i] == '+')
			(*data).plus = 1;
		else if (str[i] == ' ' && (*data).plus == 0)
			(*data).space = 1;
		else if (str[i] == '-' && (*data).minus == 0)
			(*data).minus = ft_printf_atoi(str + i);
		else if (str[i] == '0' && (*data).zero == 0 && (*data).minus == 0)
			(*data).zero = ft_printf_atoi(str + i);
		else if (str[i] >= '0' && str[i] <= '9')
			i += 0;
		else
			return (-1);
		i++;
	}
	return (i);
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

void	ft_arg_len(va_list args, t_struct *data)
{
	int	k;

	k = (*data).type;
	if (k == INTD || k == INTI || k == CHAR)
		(*data).argint = va_arg(args, int);
	else if (k == STR)
		(*data).argstr = va_arg(args, char *);
	else if (k == PTR)
		(*data).argptr = va_arg(args, unsigned long);
	else if (k == LOWHEXA || k == UPHEXA || k == UNSINT)
		(*data).argunsint = va_arg(args, unsigned int);
	if (k == INTD || k == INTI)
		(*data).alen = ft_count_digit((*data).argint);
	else if (k == PRCT || k == CHAR)
		(*data).alen = 1;
	else if (k == STR && (*data).argstr)
		(*data).alen = ft_strlen((*data).argstr);
	else if (k == PTR)
		(*data).alen = ft_count_digit_long((*data).argptr);
	else if (k == LOWHEXA || k == UPHEXA || k == UNSINT)
		(*data).alen = ft_count_digit_long((*data).argunsint);
}

int	ft_printer(va_list args, t_struct *data)
{
	ft_arg_len(args, data);
	if ((*data).type == STR && !(*data).argstr)
		ft_putstr_fd("(null)", data, 1);
	if ((*data).type == PTR)
		ft_putstr_fd("0x", data, 1);
	ft_print_before(data);
	if (ft_print_type(data) == -1)
		return (-1);
	ft_print_after(data);
	return (0);
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
	//return ((*data.flen))
	return (2 + i);
}
