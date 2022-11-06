#include "ft_printf.h"
#include <stdio.h>

int	ptr_len(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}
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
	adress_helper(nb,vars);
}
void	ft_put_adress(void *ptr,t_vars *vars)
{
	int len_of_int;
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	len_of_int = ptr_len(nb) + 2;
	handle_width(vars,len_of_int);
	if(vars->flags[zero] != 1)
	{
		ft_putstr_original("0x",vars);
	}
	if(vars->state == 0)
	{
        ft_put_adress_original(ptr,vars);
		return;
	}
	if(vars->flags[zero] == 1)
    {
		handle_padding(vars,vars->flag_counter[zero],len_of_int,'0');
		ft_putstr_original("0x",vars);
		ft_put_adress_original(ptr,vars);
        vars->flags[zero] = 0;
		vars->int_len[zero] = 0;
		vars->flag_counter[zero] = 0;
		vars->state=0;
    }
	if(vars->flags[minus] == 1)
    {
		ft_put_adress_original(ptr,vars);
        handle_padding(vars,vars->flag_counter[minus],len_of_int,' ');
        vars->flags[minus] =0;
		vars->int_len[minus] = 0;
		vars->flag_counter[minus] = 0;
		vars->state=0;
    }
}