/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/06 16:06:56 by abouabra         ###   ########.fr       */
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
		ft_putchar_original(nb + '0',vars);
}

void handle_width(t_vars *vars, int int_len)
{
	vars->flags[width] = 0;
	while(int_len < vars->flag_counter[width])
	{
		ft_putchar_original(' ', vars);
		int_len++;
	}
	vars->int_len[width] = 0;
	vars->flag_counter[width] = 0;
}
void handle_padding(t_vars *vars,int flag_counter,int int_len,char c)
{
	if(vars->flags[minus] != 1 && vars->flags[width] == 1)
	{
		handle_width(vars,flag_counter);
	}
    while(int_len < flag_counter)
    {
        ft_putchar_original(c, vars);
        int_len++;
    }
}
void	ft_putnbr(int n,t_vars *vars)
{
	int	len_of_int;

	len_of_int = int_len(vars, n);
	if (n == 0 && vars->flags[precision] == 1)
		len_of_int--;
	if (vars->flags[plus] != 1 && vars->flags[space] != 1)
		handle_width(vars, int_len(vars, n));
	if (n < 0 && vars->flags[plus] != 1 && vars->flags[space] != 1
		&& (vars->flags[precision] != 1 || vars->flags[zero] != 1))
	{
		ft_putchar_original('-', vars);
	}
	if (vars->state == 0)
	{
		ft_putnbr_original(n, vars);
		return ;
	}
	if (vars->flags[plus] == 1)
	{
		vars->flags[plus] = 0;
		if (n >= 0)
			len_of_int++;
		handle_width(vars, len_of_int);
		if (n < 0)
			ft_putchar_original('-', vars);
		if (n >= 0)
			ft_putchar_original('+', vars);
		ft_putnbr_original(n, vars);
		vars->state = 0;
	}
	if (vars->flags[space] == 1)
	{
		vars->flags[space] = 0;
		len_of_int++;
		handle_width(vars, len_of_int);
		if (n >= 0)
			ft_putchar_original(' ', vars);
		if (n < 0)
			ft_putchar_original('-', vars);
		ft_putnbr_original(n, vars);
		vars->state = 0;
	}
	if(vars->flags[zero] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			if(vars->flag_counter[precision] < int_len(vars, n))
				vars->flag_counter[precision] = len_of_int;
			
			if(n<0)
				vars->flag_counter[zero]--;
			handle_padding(vars,vars->flag_counter[zero],vars->flag_counter[precision],' ');
			if(n < 0)
			{
				ft_putchar_original('-', vars);
				vars->flag_counter[precision]--;
				len_of_int--;
			}
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(n != 0)
				ft_putnbr_original(n,vars);
			
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
			handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
			if(n != 0)
				ft_putnbr_original(n,vars);
			if(n<0)
				vars->flag_counter[minus]--;
			if(vars->flag_counter[precision] < int_len(vars, n))
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
        ft_putnbr_original(n,vars);
        handle_padding(vars,vars->flag_counter[minus],len_of_int,' ');
        vars->flags[minus] =0;
		vars->int_len[minus] = 0;
		vars->flag_counter[minus] = 0;
		vars->state=0;
    }

	if(vars->flags[precision] == 1)
    {
        handle_padding(vars,vars->flag_counter[precision],len_of_int,'0');
		if(n != 0)
			ft_putnbr_original(n,vars);
        vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }

}