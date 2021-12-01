#include "ft_printf_bonus.h"

int	ft_putmajhex_aux(unsigned int n, t_flag flag)
{
	int	ret;

	if (n < 16)
	{
		if (n >= 10)
			n = 'A' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n));
	}
	ret = ft_putmajhex_aux(n / 16, flag);
	return (ret + ft_putmajhex_aux(n % 16, flag));
}

int	ft_putmajhex(void *X, t_flag flag)
{
	int	n;
	int	ret;

	n = *((int *)X);
	ret = 0;
	if (flag.flag & 8 && n)
		ret = ft_putstr("0X", (t_flag)0);
	return (ret + ft_putmajhex_aux(n));
}
