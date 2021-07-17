/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:34:59 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 16:52:18 by ysonmez          ###   ########.fr       */
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
		else if (str[i] >= '1' && str[i] <= '9' && (*data).width == 0
			&& (*data).prec == -1)
			(*data).width = ft_printf_atoi(str + i - 1);
		else if (str[i] == '.' && (*data).prec == -1)
			(*data).prec = ft_printf_atoi(str + i);
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (i);
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
