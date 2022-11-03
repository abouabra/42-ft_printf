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
		ft_putchar(base[nb % 16],vars);
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
	int len_of_int;
	unsigned long long	nb;
	nb = (unsigned long long)ptr;

	len_of_int = hex_len(nb);
	if(nb==0 && vars->flags[precision] == 1)
		len_of_int--;
	handle_width(vars,hex_len(nb));
	if(vars->state == 0)
	{
        ft_put_adress_original(ptr,vars);
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
        		ft_put_adress_original(ptr,vars);
        		
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
        	ft_put_adress_original(ptr,vars);
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
        		ft_put_adress_original(ptr,vars);
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
        ft_put_adress_original(ptr,vars);
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
        	ft_put_adress_original(ptr,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }
	
}