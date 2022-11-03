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
	int len_of_int;
	len_of_int = hex_len(nb);
	if(nb==0 && vars->flags[precision] == 1)
		len_of_int--;
	handle_width(vars,hex_len(nb));
	if(vars->state == 0)
	{
        put_hex_original(nb,x,vars);
		return;
	}
	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			if(vars->flag_counter[precision] < hex_len(nb))
				vars->flag_counter[precision] = len_of_int;
			
			//printf("len_of_int %d %d\n",vars->flag_counter[zero],vars->flag_counter[precision]-1);
			handle_padding(vars,vars->flag_counter[zero],vars->flag_counter[precision],' ');
			// if(n < 0)
			// {
			// 	ft_putchar('-', vars);
			// 	vars->flag_counter[precision]--;
			// 	len_of_int--;
			// }
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(nb != 0)
        		put_hex_original(nb,x,vars);
			
			//printf("======");
			vars->flags[zero] =0;
			vars->int_len[zero] = 0;
			vars->flag_counter[zero] = 0;
			
			vars->flags[precision] =0;
			vars->int_len[precision] = 0;
			vars->flag_counter[precision] = 0;
			vars->state=0;
			return;
		}
		else
		{
        	handle_padding(vars,vars->flag_counter[zero],len_of_int,'0');
        	put_hex_original(nb,x,vars);
		}
        vars->flags[zero] = 0;
		vars->int_len[zero] = 0;
		vars->flag_counter[zero] = 0;
		vars->state=0;
    }
	if(vars->flags[minus] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			//printf("len_of_int %d %d\n",vars->flag_counter[precision],vars->flag_counter[minus]);
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(nb != 0)
	        	put_hex_original(nb,x,vars);
			// if(n<0)
			// 	vars->flag_counter[minus]--;
			if(vars->flag_counter[precision] < hex_len(nb))
				vars->flag_counter[precision] = len_of_int;
			handle_padding(vars,vars->flag_counter[minus],vars->flag_counter[precision],' ');
			//printf("len_of_int %d %d\n",vars->flag_counter[precision],vars->flag_counter[minus]);
			vars->flags[minus] =0;
			vars->int_len[minus] = 0;
			vars->flag_counter[minus] = 0;
			
			vars->flags[precision] =0;
			vars->int_len[precision] = 0;
			vars->flag_counter[precision] = 0;
			vars->state=0;
			return;
		}
	    put_hex_original(nb,x,vars);
        handle_padding(vars,vars->flag_counter[minus],len_of_int,' ');
        vars->flags[minus] =0;
		vars->int_len[minus] = 0;
		vars->flag_counter[minus] = 0;
		vars->state=0;
    }
	if(vars->flags[precision] == 1)
    {
		//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);
        handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
		//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);
		if(nb != 0)
	    put_hex_original(nb,x,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }
}