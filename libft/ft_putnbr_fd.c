/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:03:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 15:37:24 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, t_struct *data, int fd)
{
	unsigned int	number;
	char			c;

	c = 0;
	if (n < 0)
		number = n * (-1);
	else
		number = n;
	if (number >= 10)
		ft_putnbr_fd(number / 10, data, fd);
	c = (number % 10) + 48;
	ft_putchar_fd(c, data, fd);
}
