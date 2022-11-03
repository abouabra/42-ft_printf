#include "ft_printf.h"

void	adress_helper(unsigned long long nb,t_vars *vars)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		adress_helper(nb / 16, vars);
		adress_helper(nb % 16, vars);
	}
	else
		ft_putchar_original(base[nb % 16],vars);
}

void	ft_put_adress_original(void *ptr,t_vars *vars)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	ft_putstr("0x",vars);
	adress_helper(nb,vars);
}
void	ft_put_adress(void *ptr,t_vars *vars)
{
	(void) ptr;	
	(void) vars;	
}