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
		ft_putchar_original(base[nb % 16],vars);
}

void	ft_put_hex_nbr(unsigned int nb, char x,t_vars *vars)
{
	int	len_of_int;

	len_of_int = hex_len(nb);
	if (nb == 0 && vars->flags[precision] == 1)
		len_of_int--;
	if (vars->flags[hashtag] != 1)
		handle_width(vars, hex_len(nb));
	if (vars->state == 0)
	{
		put_hex_original(nb, x, vars);
		return ;
	}
	if (vars->flags[hashtag] == 1)
	{
		vars->flags[hashtag] = 0;
		if (nb != 0)
			len_of_int += 2;
		handle_width(vars, len_of_int);
		if (x == 'x' && nb != 0)
			ft_putstr_original("0x", vars);
		else if (x == 'X' && nb != 0)
			ft_putstr_original("0X", vars);
		put_hex_original(nb, x, vars);
		vars->state = 0;
	}
	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			if(vars->flag_counter[precision] < hex_len(nb))
				vars->flag_counter[precision] = len_of_int;
			
			handle_padding(vars,vars->flag_counter[zero],vars->flag_counter[precision],' ');
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(nb != 0)
        		put_hex_original(nb,x,vars);
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
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(nb != 0)
	        	put_hex_original(nb,x,vars);
			if(vars->flag_counter[precision] < hex_len(nb))
				vars->flag_counter[precision] = len_of_int;
			handle_padding(vars,vars->flag_counter[minus],vars->flag_counter[precision],' ');
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
        handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
		if(nb != 0)
	    	put_hex_original(nb,x,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }
}