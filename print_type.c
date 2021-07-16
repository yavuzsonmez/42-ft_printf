/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yavuzsonmez <yavuzsonmez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:25:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 09:11:33 by yavuzsonmez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_puthexa_fd(unsigned int n, t_struct *data, int fd)
{
	char	*hxbase;

	if ((*data).type == UPHEXA)
		hxbase = ft_strdup("0123456789ABCDEF");
	else
		hxbase = ft_strdup("0123456789abcdef");
	if (n >= 16)
		ft_puthexa_fd(n / 16, data, fd);
	ft_putchar_fd(hxbase[n % 16], data, fd);
	free(hxbase);
}

void	ft_putunsint_fd(unsigned int n, t_struct *data, int fd)
{
	if (n >= 10)
		ft_putunsint_fd(n / 10, data, fd);
	ft_putchar_fd((n % 10) + 48, data, fd);
}

void	ft_putunslong_fd(unsigned long n, t_struct *data, int fd)
{
	char	*hxbase;

	hxbase = ft_strdup("0123456789abcdef");
	if (n >= 16)
		ft_putunslong_fd(n / 16, data, fd);
	ft_putchar_fd(hxbase[n % 16], data, fd);
	free(hxbase);
}
