/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:03:20 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 17:24:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putuns_aux(unsigned int n)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (n < 10)
	{
		n += '0';
		return (ft_putchar(&n, null));
	}
	ret = ft_putuns_aux(n / 10);
	return (ret + ft_putuns_aux(n % 10));
}

int	ft_putuns(void *u, t_flag flag)
{
	unsigned int	n;

	n = *((unsigned int *)u);
	flag.size -= ft_len(n, 10);
	if (!(IS_MINUS(flag.flag)))
		return (ft_putalign(flag) + ft_putuns_aux(n));
	return (ft_putuns_aux(n) + ft_putalign(flag));
}
