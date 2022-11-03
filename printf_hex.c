#include "ft_printf.h"
#include <stdio.h>

int	hex_len(unsigned int n)
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

void	put_hex_original(unsigned int nb, char x,t_vars *vars)
{
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		put_hex_original(nb / 16, x,vars);
		put_hex_original(nb % 16, x,vars);
	}
	else
		ft_putchar(base[nb % 16],vars);
}

void	ft_put_hex_nbr(unsigned int nb, char x,t_vars *vars)
{
	handle_width(vars,hex_len(nb));

	if(vars->flags[zero] == 1)
    {
        handle_padding(vars,vars->flag_counter[zero],hex_len(nb),'0');
        put_hex_original(nb,x,vars);
        vars->flags[zero] = 0;
    }
	else if(vars->flags[minus] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			handle_padding(vars,vars->flag_counter[precision],hex_len(nb),'0');
			put_hex_original(nb,x,vars);
			handle_padding(vars,vars->flag_counter[minus],vars->flag_counter[precision],' ');
			return;
		}
        put_hex_original(nb,x,vars);
        handle_padding(vars,vars->flag_counter[minus],hex_len(nb),' ');
        vars->flags[minus] = 0;
    }
	else if(vars->flags[precision] == 1)
    {
        handle_padding(vars,vars->flag_counter[precision],hex_len(nb),'0');
		put_hex_original(nb,x,vars);
        vars->flags[precision] = 0;
    }
	else if(vars->state == 0)
		put_hex_original(nb,x,vars);
}