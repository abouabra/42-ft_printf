/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 09:19:38 by abouabra         ###   ########.fr       */
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
}
void handle_padding(t_vars *vars,int flag_counter,int int_len,char c)
{
	//printf("\nflag: width count:  %d\nflag: . count: %d\n\n",vars->flag_counter[width],vars->flag_counter[width]);
	if(vars->flags[minus] != 1 && vars->flags[width] == 1)
	{
		handle_width(vars,flag_counter);
	}
    while(int_len < flag_counter)
    {
        ft_putchar(c, vars);
        int_len++;
    }
}
void	ft_putnbr(int n,t_vars *vars)
{
	if(n<0)
		ft_putchar('-', vars);
	handle_width(vars, int_len(n));

	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			vars->flags[width] = 1;
			vars->flag_counter[width] = vars->flag_counter[zero];	
		}
		else
		{
        	handle_padding(vars,vars->flag_counter[zero],int_len(n),'0');
        	ft_putnbr_original(n,vars);
		}
        vars->flags[zero] = 0;
    }
	if(vars->flags[minus] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			handle_padding(vars,vars->flag_counter[precision],int_len(n),'0');
			ft_putnbr_original(n,vars);
			handle_padding(vars,vars->flag_counter[minus],vars->flag_counter[precision],' ');
			return;
		}
        ft_putnbr_original(n,vars);
        handle_padding(vars,vars->flag_counter[minus],int_len(n),' ');
        vars->flags[minus] = 0;
    }
	if(vars->flags[precision] == 1)
    {
		//printf("\nflag: width count:  %d\nflag: . count: %d\n\n",vars->flag_counter[width],vars->flag_counter[width]);
        handle_padding(vars,vars->flag_counter[precision],int_len(n),'0');
        ft_putnbr_original(n,vars);
        vars->flags[precision] = 0;
    }
	if(vars->state == 0)
        ft_putnbr_original(n,vars);
}