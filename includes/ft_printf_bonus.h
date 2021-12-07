/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:10:43 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 13:04:48 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define IS_ZERO(x) (x) & 1
# define IS_MINUS(x) (x) & 2
# define IS_DOT(x) (x) & 4
# define IS_HTAG(x) (x) & 8
# define IS_SPACE(x) (x) & 16
# define IS_PLUS(x) (x) & 32

typedef struct	s_flag
{
	int flag;
	int size;
	int	dot_size;
}		t_flag;

typedef int	(*t_print)(void *, t_flag);

int		ft_putchar(void *c, t_flag flag);
int		ft_putstr(void *s, t_flag flag);
int		ft_putnbr(void *n, t_flag flag);
int		ft_puthex(void *x, t_flag flag);
int		ft_putuns(void *u, t_flag flag);
int		ft_putmajhex(void *x, t_flag flag);
int		ft_putadd(void *p, t_flag flag);
int		ft_printf(const char *fmt, ...);
int		ft_strichr(char *s, char c);
int		ft_len(unsigned long n, int base);
int		ft_putalign(t_flag flag);
t_flag	ft_flag(const char *fmt, int *i);
int		ft_particular_atoi(const char *s, int *i);

#endif
