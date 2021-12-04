/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmajhex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:58:30 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 17:23:16 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putmajhex_aux(unsigned int n)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (n < 16)
	{
		if (n >= 10)
			n = 'A' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n, null));
	}
	ret = ft_putmajhex_aux(n / 16);
	return (ret + ft_putmajhex_aux(n % 16));
}

int	ft_putmajhex(void *X, t_flag flag)
{
	int		n;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	n = *((int *)X);
	flag.size -= ft_len((unsigned int)n, 16);
	if (IS_HTAG(flag.flag) && n)
	{
		flag.size -= 2;
		if (!(IS_MINUS(flag.flag)))
			return (ft_putalign(flag) + ft_putstr("0X", null) + ft_putmajhex_aux(n));
		return (ft_putstr("0X", null) + ft_putmajhex_aux(n) + ft_putalign(flag));
	}
	if (!(IS_MINUS(flag.flag)))
		return (ft_putalign(flag) + ft_putmajhex_aux(n));
	return (ft_putmajhex_aux(n) + ft_putalign(flag));
}
