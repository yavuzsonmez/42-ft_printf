/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:14:34 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/15 12:04:43 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, t_struct *data, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		if ((*data).prec == 0 && (*data).plen == 1)
			return ;
		else if ((*data).prec > 0)
			while (s[i] && i < (*data).prec)
			{
				ft_putchar_fd(s[i], data, fd);
				i++;
			}
		else
			while (s[i])
			{
				ft_putchar_fd(s[i], data, fd);
				i++;
			}
	}
}
