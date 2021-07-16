/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:14:34 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/16 18:06:46 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, t_struct *data, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		if ((*data).prec == 0)
			return ;
		if ((*data).prec)
			while (s[i] && (*data).prec)
			{
				ft_putchar_fd(s[i], data, fd);
				i++;
				(*data).prec--;
			}
		else
			while (s[i])
			{
				ft_putchar_fd(s[i], data, fd);
				i++;
			}
	}
}
