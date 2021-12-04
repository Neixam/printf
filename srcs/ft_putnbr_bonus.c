/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:59:38 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 18:50:46 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_aux(unsigned int n)
{
	int		ret;
	char	c;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	ret = 0;
	if (n < 10)
	{
		c = n + '0';
		return (ft_putchar(&c, null));
	}
	ret += ft_putnbr_aux(n / 10);
	return (ret + ft_putnbr_aux(n % 10));
}

int	ft_putnbr(void *n, t_flag flag)
{
	int		nb;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	nb = *((int *)n);
	if (nb < 0)
	{
		flag.size -= (ft_len(-nb, 10) + 1);
		if (IS_ZERO(flag.flag) && !(IS_MINUS(flag.flag)))
			return (ft_putchar("-", null) + ft_putalign(flag) + ft_putnbr_aux(-nb));
		if (!(IS_MINUS(flag.flag)))
			return (ft_putalign(flag) + ft_putchar("-", null) + ft_putnbr_aux(-nb));
		return (ft_putchar("-", null) + ft_putnbr_aux(-nb) + ft_putalign(flag));
	}
	else
		flag.size -= ft_len(nb, 10);
	if (!(IS_MINUS(flag.flag)))
		return (ft_putalign(flag) + ft_putnbr_aux(nb));
	return (ft_putnbr_aux(nb) + ft_putalign(flag));
}
