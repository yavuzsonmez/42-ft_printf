/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:51:21 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/13 19:13:20 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_struct	*new_struct(void)
{
	t_struct	*data;

	(*data).hash = 0;
	(*data).space = 0;
	(*data).plus = 0;
	(*data).zero = 0;
	(*data).minus = 0;
	(*data).prec = 0;
	(*data).width = 0;
	(*data).flen = 0;
	(*data).alen = 0;
	(*data).print = 0;
	(*data).type = 0;
	(*data).type = 0;
	(*data).argint = 0;
	(*data).argstr = 0;
	(*data).argptr = 0;
	(*data).argunsint = 0;
	return (data);
}

int	ft_count_digit(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * (-1);
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
	size_t	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == 'd' || str[i] == 'i')
			return (INT);
		else if (str[i] == 'c')
			return (CHAR);
		else if (str[i] == 's')
			return (STR);
		else if (str[i] == 'p')
			return (PTR);
		else if (str[i] == 'x')
			return (LOWHEXA);
		else if (str[i] == 'X')
			return (UPHEXA);
		else if (str[i] == 'u')
			return (UNSINT);
		else if (str[i] == '%')
			return (PRCT);
		i++;
	}
	return (-1);
}

int	ft_set_format(va_list args, t_struct *data, const char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != (*data).type)
	{
		if (str[i] == '#' && (*data).hash == 0)
			(*data).hash = 1;
		else if (str[i] == '+' && (*data).plus == 0)
			(*data).plus = 1;
		else if (str[i] == ' ' && (*data).space == 0 && (*data).plus == 0)
			(*data).space = 1;
		else if (str[i] == '-' && (*data).minus == 0)
			(*data).minus = 1;
		else if(str[i] == '0' && (*data).zero == 0 && (*data).minus == 0)
			(*data).zero = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}


void	ft_print_type(va_list args, t_struct *data)
{
	if ((*data).type == INT)
		ft_putchar_fd((*data).argint, 1);
	else if ((*data).type == CHAR)
		ft_putchar_fd((*data).argint, 1);
	else if ((*data).type == STR)
	{
		if ((*data).argstr == NULL)
			ft_putstr_fd("(null)", 1);
		else
			ft_putstr_fd((*data).argstr, 1);
	}
	else if ((*data).type == LOWHEXA || (*data).type == UPHEXA || (*data).type == PTR)
	{
		if ((*data).type == PTR)
		{
			ft_putstr_fd("0x", 1);
			ft_puthexa_fd((*data).argptr, 1);
		}
		else
			ft_puthexa_fd((*data).argunsint, 1);
	}
	else if ((*data).type == UNSINT)
		ft_putunsint_fd((*data).argunsint, 1);
	else if ((*data).type == PRCT)
		ft_putchar_fd((*data).argint, 1);
	else
		return ;
}

void	ft_arg_len(args, data);
{
	if ((*data).type == INT)
		(*data).argint = va_arg(args, int);
	else if ((*data).type == CHAR)
		(*data).argint = va_arg(args, int);
	else if ((*data).type == STR)
		(*data).argstr = va_arg(args, char *);
	else if ((*data).type == PTR)
		(*data).argptr = va_arg(args, unsigned long);
	else if ((*data).type == LOWHEXA || (*data).type == UPHEXA || (*data).type == UNSINT)
		(*data).argunsint = va_arg(args, unsigned int);
	else if ((*data).type == PRCT)
		(*data).argint = va_arg(args, int);
	if ((*data).type == INT || (*data).type == CHAR || (*data).type == PRCT)
		(*data).alen = ft_count_digit((*data).argint);
	else if ((*data).type == STR)
		(*data).alen = ft_strlen((*data).argstr);
	else if ((*data).type == PTR)
		(*data).alen = ft_count_digit_long((*data).argptr);
	else if ((*data).type == LOWHEXA || (*data).type == UPHEXA || (*data).type == UNSINT)
		(*data).alen = ft_count_digit_long((*data).argunsint);
}

void	ft_printer(va_list args, t_struct *data)
{
	ft_arg_len(args, data);
	ft_print_type(args, data);
}

int		ft_parse_format(va_list args, t_struct *data, const char *str)
{
	int state;

	state = 0;
	(*data).type = ft_get_type(str);
	if ((*data).type == -1)
		return(-1);
	state = ft_set_format(args, data, str);
	if (state == -1)
		return (-1);
	ft_printer(args, data);
	//return ((*data.flen))
	return (1);
}
