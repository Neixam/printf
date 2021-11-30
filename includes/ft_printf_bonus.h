/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:10:43 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 16:11:44 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

typedef int	(*t_print)(void *, int);

int	ft_putchar(void *c, int flag);
int	ft_putstr(void *s, int flag);
int	ft_putnbr(void *n, int flag);
int	ft_puthex(void *x, int flag);
int	ft_putuns(void *u, int flag);
int	ft_putmajhex(void *x, int flag);
int	ft_putadd(void *p, int flag);
int	ft_printf(const char *fmt, ...);
int	ft_strichr(char *s, char c);

#endif
