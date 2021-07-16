/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:34:59 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 16:56:54 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_format(t_struct *data, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (*data).chartype)
	{
		if (str[i] == '#' && (*data).hash == 0)
			(*data).hash = 1;
		else if (str[i] == '+')
			(*data).plus = 1;
		else if (str[i] == ' ' && (*data).plus == 0)
			(*data).space = 1;
		else if (str[i] == '-' && (*data).minus == 0)
			(*data).minus = ft_printf_atoi(str + i);
		else if (str[i] == '0' && (*data).zero == 0 && (*data).minus == 0)
			(*data).zero = ft_printf_atoi(str + i);
		else if (str[i] >= '1' && str[i] <= '9' && (*data).width == 0)
			(*data).width = ft_printf_atoi(str + i - 1);
		else if (str[i] == '.' && (*data).prec == 0)
			(*data).prec = ft_printf_atoi(str + i);
		else if (!(str[i] >= '0' && str[i] <= '9'))
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
		ft_count_digit_hexa((*data).argptr, data);
	else if (k == LOWHEXA || k == UPHEXA)
		ft_count_digit_hexa((*data).argunsint, data);
	else if (k == UNSINT)
		(*data).alen = ft_count_digit_unsint((*data).argunsint);
}

int	ft_printer(va_list args, t_struct *data)
{
	ft_arg_len(args, data);
	if ((*data).type == STR && !(*data).argstr)
		ft_putstr_fd("(null)", data, 1);
	if ((*data).type == PTR)
	{
		ft_putstr_fd("0x", data, 1);
		(*data).alen += 2;
	}
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
	return (2 + i);
}
