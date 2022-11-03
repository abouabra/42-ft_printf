/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 18:20:01 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_original(int n,t_vars *vars)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_original(nb / 10,vars);
		ft_putnbr_original(nb % 10,vars);
	}
	else
		ft_putchar(nb + '0',vars);
}

void handle_width(t_vars *vars, int int_len)
{
	while(int_len < vars->flag_counter[width])
	{
		ft_putchar(' ', vars);
		int_len++;
	}
	vars->flags[width] = 0;
	vars->int_len[width] = 0;
	vars->flag_counter[width] = 0;
}
void handle_padding(t_vars *vars,int flag_counter,int int_len,char c)
{
	if(vars->flags[minus] != 1 && vars->flags[width] == 1)
	{
		handle_width(vars,flag_counter);
	}
	//printf("////flag . counter: %d len:%d\n",int_len,flag_counter);
    while(int_len < flag_counter)
    {
        ft_putchar(c, vars);
        int_len++;
    }
}
void	ft_putnbr(int n,t_vars *vars)
{
	//int i;
	//printf("====");
	//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);

	int len_of_int;
	len_of_int = int_len(vars,n);
	if(n==0 && vars->flags[precision] == 1)
		len_of_int--;
	handle_width(vars, int_len(vars,n));
	if(n < 0 && (vars->flags[precision] != 1 ||  vars->flags[zero] != 1))
	{
		ft_putchar('-', vars);	
	}
	if(vars->state == 0)
	{
        ft_putnbr_original(n,vars);
		return;
	}
	//printf("\nflag precision counter: %d len:%d\n",n,len_of_int);
	
	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			if(vars->flag_counter[precision] < int_len(vars, n))
				vars->flag_counter[precision] = len_of_int;
			handle_padding(vars,vars->flag_counter[zero],vars->flag_counter[precision],' ');
			if(n<0)
				vars->flag_counter[zero]--;
			//if(n==0 && vars->flags[precision] == 1)
			//	len_of_int--;
			//printf("len_of_int %d %d\n",vars->flag_counter[zero],vars->flag_counter[precision]);
			if(n < 0)
			{
				ft_putchar('-', vars);	
			}
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(n != 0)
				ft_putnbr_original(n,vars);
			
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
        	ft_putnbr_original(n,vars);
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
			if(n != 0)
				ft_putnbr_original(n,vars);
			if(n<0)
				vars->flag_counter[minus]--;
			if(vars->flag_counter[precision] < int_len(vars, n))
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
        ft_putnbr_original(n,vars);
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
		if(n != 0)
			ft_putnbr_original(n,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }

}