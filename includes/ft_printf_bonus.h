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

typedef int	(*t_print)(void *, t_flag);

typedef struct	s_flag
{
	int flag;
	int size;
}		t_flag;

int	ft_putchar(void *c, t_flag flag);
int	ft_putstr(void *s, t_flag flag);
int	ft_putnbr(void *n, t_flag flag);
int	ft_puthex(void *x, t_flag flag);
int	ft_putuns(void *u, t_flag flag);
int	ft_putmajhex(void *x, t_flag flag);
int	ft_putadd(void *p, t_flag flag);
int	ft_printf(const char *fmt, ...);
int	ft_strichr(char *s, char c);

#endif
