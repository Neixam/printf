/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:36:21 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 15:11:16 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd_aux(unsigned long ad)
{
	int	ret;

	ret = 0;
	if (ad < 16)
	{
		if (ad >= 10)
			ad = 'a' + ad % 10;
		else
			ad += '0';
		return (ret + ft_putchar(&ad));
	}
	ret += ft_putadd_aux(ad / 16);
	return (ret + ft_putadd_aux(ad % 16));
}

int	ft_putadd(void *a)
{
	int				ret;
	unsigned long	ad;

	if (!a)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	ad = (unsigned long)a;
	ret += ft_putadd_aux(ad);
	return (ret);
}
