#include "ft_printf_bonus.h"

int	ft_puthex_aux(unsigned int n, t_flag flag)
{
	int	ret;

	if (n < 16)
	{
		if (n >= 10)
			n = 'a' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n));
	}
	ret = ft_puthex_aux(n / 16, flag);
	return (ret + ft_puthex_aux(n % 16, flag));
}

int	ft_puthex(void *x, t_flag flag)
{
	int	n;
	int	ret;

	n = *((int *)x);
	ret = 0;
	if (flag.flag & 8 && n)
		ret = ft_putstr("0x", (t_flag)0);
	return (ft_puthex_aux(n));
}
