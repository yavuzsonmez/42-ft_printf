/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/14 15:35:56 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_before(t_struct *data)
{
	int	k;

	k = (*data).type;
	if ((*data).hash && (*data).argunsint != 0 && k == LOWHEXA)
		ft_putstr_fd("0x", data, 1);
	else if ((*data).hash && (*data).argunsint != 0 && k == UPHEXA)
		ft_putstr_fd("0X", data, 1);
}

void	ft_print_after(t_struct *data)
{
	int	k;

	k = (*data).type;
}
