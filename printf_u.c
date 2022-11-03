#include "ft_printf.h"

int	u_int_len(unsigned int n)
{
	int	counter;
	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

void	ft_put_unbr_original(unsigned int nb,t_vars *vars)
{
	if (nb >= 10)
	{
		ft_put_unbr_original(nb / 10,vars);
		ft_put_unbr_original(nb % 10,vars);
	}
	else
		ft_putchar(nb + '0',vars);
}

void	ft_put_unsigned_nbr(unsigned int nb,t_vars *vars)
{
	int len_of_int;
	len_of_int = u_int_len(nb);
	if(nb==0 && vars->flags[precision] == 1)
		len_of_int--;
	handle_width(vars,u_int_len(nb));
	if(vars->state == 0)
	{
        ft_put_unbr_original(nb,vars);
		return;
	}
	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			if(vars->flag_counter[precision] < u_int_len(nb))
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
        		ft_put_unbr_original(nb,vars);
			
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
        	ft_put_unbr_original(nb,vars);
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
	        	ft_put_unbr_original(nb,vars);
			// if(n<0)
			// 	vars->flag_counter[minus]--;
			if(vars->flag_counter[precision] < u_int_len(nb))
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
	    ft_put_unbr_original(nb,vars);
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
	    ft_put_unbr_original(nb,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }
}