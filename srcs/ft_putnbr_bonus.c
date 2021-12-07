/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:59:38 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 13:43:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_aux(unsigned int n, int dot_size)
{
	int		ret;
	char	c;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	ret = 0;
	if (n < 10 && dot_size <= 1)
	{
		c = n + '0';
		return (ft_putchar(&c, null));
	}
	ret += ft_putnbr_aux(n / 10, dot_size - 1);
	return (ret + ft_putnbr_aux(n % 10, 0));
}

int	ft_putnbr_chk_flg(int n, t_flag flag, t_flag null)
{
	char	c;

	c = '-';
	if (n >= 0)
		c = '+';
	if (n < 0)
	{
		if (IS_ZERO(flag.flag) && !(IS_MINUS(flag.flag)))
			return (ft_putchar(&c, null) + ft_putalign(flag) + ft_putnbr_aux(-n, flag.dot_size));
		if (!(IS_MINUS(flag.flag)))
			return (ft_putalign(flag) + ft_putchar(&c, null) + ft_putnbr_aux(-n, flag.dot_size));
		return (ft_putchar(&c, null) + ft_putnbr_aux(-n, flag.dot_size) + ft_putalign(flag));
	}
	if (!(IS_SPACE(flag.flag)) && !(IS_PLUS(flag.flag)))
	{
		if (!(IS_MINUS(flag.flag)))
			return (ft_putalign(flag) + ft_putnbr_aux(n, flag.dot_size));
		return (ft_putnbr_aux(n, flag.dot_size) + ft_putalign(flag));
	}
	if (!(IS_PLUS(flag.flag)))
		c = ' ';
	if (!(IS_MINUS(flag.flag)))
		return (ft_putalign(flag) + ft_putchar(&c, null) + ft_putnbr_aux(n, flag.dot_size));
	return (ft_putchar(&c, null) + ft_putnbr_aux(n, flag.dot_size) + ft_putalign(flag));
}

int	ft_putnbr(void *n, t_flag flag)
{
	int		nb;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	nb = *((int *)n);
	if (nb < 0)
		flag.size -= (ft_len(-nb, 10) + 1);
	else
		flag.size -= ft_len(nb, 10);
	return (ft_putnbr_chk_flg(nb, flag, null));
}
