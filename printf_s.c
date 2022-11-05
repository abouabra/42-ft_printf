/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/05 18:36:27 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putstr_original(char *s,t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_original(s[i],vars);
		i++;
	}
}

void handle_string_precision(t_vars *vars,int flag_counter,char *str)
{
	int i;
	
	i=0;
	vars->flags[width] = 0;
	while(*str && i < flag_counter)
	{
		ft_putchar_original(*str, vars);
		i++;
		str++;
	}
	vars->int_len[width] = 0;
	vars->flag_counter[width] = 0;
}

void	ft_putstr(char *s,t_vars *vars)
{
	int len_of_str;
	
	if (!s)
		s = "(null)";
	len_of_str = ft_strlen(s);
	if(vars->flags[width] == 1 && vars->flags[precision] != 1)
		handle_width(vars,len_of_str);
	//printf("LEN: %d",len_of_str);
	if(vars->state == 0)
	{
        ft_putstr_original(s,vars);
		return;
	}
	if(vars->flags[minus] == 1)
    {
		if(vars->flags[precision] == 1)
		{
			//printf("len_of_str %d %d\n",vars->flag_counter[precision],vars->flag_counter[minus]);
			if(vars->flag_counter[precision] > len_of_str)
				vars->flag_counter[precision] = len_of_str;
			handle_string_precision(vars,vars->flag_counter[precision],s);
			// if(n<0)
			// 	vars->flag_counter[minus]--;
			handle_padding(vars,vars->flag_counter[minus],vars->flag_counter[precision],' ');
			//printf("len_of_str %d %d\n",vars->flag_counter[precision],vars->flag_counter[minus]);
			vars->flags[minus] =0;
			vars->int_len[minus] = 0;
			vars->flag_counter[minus] = 0;
			
			vars->flags[precision] =0;
			vars->int_len[precision] = 0;
			vars->flag_counter[precision] = 0;
			vars->state=0;
			return;
		}
   		ft_putstr_original(s,vars);
        handle_padding(vars,vars->flag_counter[minus],len_of_str,' ');
        vars->flags[minus] =0;
		vars->int_len[minus] = 0;
		vars->flag_counter[minus] = 0;
		vars->state=0;
    }
	if(vars->flags[precision] == 1)
    {
		//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);
		if(vars->flag_counter[precision] < len_of_str)
			len_of_str = vars->flag_counter[precision];
		handle_width(vars,len_of_str);
		handle_string_precision(vars,vars->flag_counter[precision],s);
		vars->flags[precision] = 0;
		vars->int_len[precision] = 0;
		vars->flag_counter[precision] = 0;
		vars->state=0;
    }
}