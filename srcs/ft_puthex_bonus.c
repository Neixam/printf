/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:57:50 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 17:23:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthex_aux(unsigned int n)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (n < 16)
	{
		if (n >= 10)
			n = 'a' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n, null));
	}
	ret = ft_puthex_aux(n / 16);
	return (ret + ft_puthex_aux(n % 16));
}

int	ft_puthex(void *x, t_flag flag)
{
	int		n;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	n = *((int *)x);
	flag.size -= ft_len((unsigned int)n, 16);
	if (IS_HTAG(flag.flag) && n)
	{
		flag.size -= 2;
		if (!(IS_MINUS(flag.flag)))
			return (ft_putalign(flag) + ft_putstr("0x", null) + ft_puthex_aux(n));
		return (ft_putstr("0x", null) + ft_puthex_aux(n) + ft_putalign(flag));
	}
	if (!(IS_MINUS(flag.flag)))
		return (ft_putalign(flag) + ft_puthex_aux(n));
	return (ft_puthex_aux(n) + ft_putalign(flag));
}
