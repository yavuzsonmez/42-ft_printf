/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:06:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/17 14:08:46 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash(t_struct *data)
{
	if ((*data).hash && (*data).argunsint != 0 && (*data).type == LOWHEXA)
	{
		ft_putstr_fd("0x", data, 1);
		(*data).alen += 2;
	}
	else if ((*data).hash && (*data).argunsint != 0 && (*data).type == UPHEXA)
	{
		ft_putstr_fd("0X", data, 1);
		(*data).alen += 2;
	}
}
