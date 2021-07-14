/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:51:21 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/14 14:29:34 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	(*p_data).flen = 0;
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
	while (str[i])
	{
		if (str[i] == 'd')
			return (INTd);
		else if (str[i] == 'i')
			return (INTi);
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

int	ft_get_chartype(t_struct *data)
{
	int	k;

	k = (*data).type;
	if (k == INTd)
		return ('d');
	else if (k == INTi)
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
		if (str[i] == '#' && (*data).hash == 0)
			(*data).hash = 1;
		else if (str[i] == '+' && (*data).plus == 0)
			(*data).plus = 1;
		else if (str[i] == ' ' && (*data).space == 0 && (*data).plus == 0)
			(*data).space = 1;
		else if (str[i] == '-' && (*data).minus == 0)
			(*data).minus = 1;
		else if (str[i] == '0' && (*data).zero == 0 && (*data).minus == 0)
			(*data).zero = 1;
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
	if (k == INTd || k == INTi)
		ft_putnbr_fd((*data).argint, data, 1);
	else if (k == CHAR)
		ft_putchar_fd((*data).argint, data, 1);
	else if (k == STR && (*data).argstr)
		ft_putstr_fd((*data).argstr, data, 1);
	else if (k == STR && !(*data).argstr)
		return (0);
	else if (k == LOWHEXA || k == UPHEXA || k == PTR)
	{
		if (k == PTR)
			ft_puthexa_fd((*data).argptr, data, 1);
		else
			ft_puthexa_fd((*data).argunsint, data, 1);
	}
	else if (k == UNSINT)
		ft_putunsint_fd((*data).argunsint, data, 1);
	else if (k == PRCT && (*data).argint == 1)
		ft_putchar_fd('%', data, 1);
	else
		return (-1);
	return (0);
}

void	ft_arg_len(va_list args, t_struct *data)
{
	int	k;

	k = (*data).type;
	if (k == INTd || k == INTi || k == CHAR)
		(*data).argint = va_arg(args, int);
	else if (k == PRCT)
	{
		(*data).argint = 1;
		(*data).alen = 1;
	}
	else if (k == STR)
		(*data).argstr = va_arg(args, char *);
	else if (k == PTR)
		(*data).argptr = va_arg(args, unsigned long);
	else if (k == LOWHEXA || k == UPHEXA || k == UNSINT)
		(*data).argunsint = va_arg(args, unsigned int);
	if (k == INTd || k == INTi || k == CHAR)
		(*data).alen = ft_count_digit((*data).argint);
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

int		ft_parse_format(va_list args, t_struct *data, const char *str)
{
	int	state;

	state = 0;
	(*data).type = ft_get_type(str);
	(*data).chartype = ft_get_chartype(data);
	if ((*data).type == -1 || (*data).chartype == -1)
		return (-1);
	state = ft_set_format(data, str);
	if (state == -1)
		return (-1);
	state = ft_printer(args, data);
	if (state == -1)
		return (-1);
	//return ((*data.flen))
	return (2);
}
