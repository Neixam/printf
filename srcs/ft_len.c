/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:39:50 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 18:57:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_putalign_s(t_flag flag)
{
	char	c;
	int		ret;

	c = ' ';
	if (IS_ZERO(flag.flag) && !(IS_MINUS(flag.flag)))
		c = '0';
	ret = 0;
	while (flag.size-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int	ft_len(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}
