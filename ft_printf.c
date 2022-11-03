/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 15:35:47 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
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

void	ft_put_adress(void *ptr,t_vars *vars)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	ft_putstr("0x",vars);
	adress_helper(nb,vars);
}

void	print_specifiers(va_list args,t_vars *vars)
{
	if (*(vars->str) == 'c')
		ft_putchar(va_arg(args, int),vars);
	if (*(vars->str) == '%')
		ft_putchar('%',vars);
	if (*(vars->str) == 's')
		ft_putstr(va_arg(args, char *),vars);
	if (*(vars->str) == 'd' || *(vars->str) == 'i')
		ft_putnbr(va_arg(args, int),vars);
	if (*(vars->str) == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int),vars);
	if (*(vars->str) == 'x')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'x',vars);
	if (*(vars->str) == 'X')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'X',vars);
	if (*(vars->str) == 'p')
		ft_put_adress(va_arg(args, void *),vars);
}

void scan_flags(t_vars *vars)
{
	int tmp;
	// reserved for width
	// if(*str == '-')
	// {
	// 	str++;
	// 	vars->flags[zero] = 1;
	// 	vars->flag_counter[zero] = atoi(str);
	// 	vars->int_len[zero] = int_len(vars->flag_counter[zero]);
	// 	return 1;
	// }
	if(*(vars->str) == '-')
	{
		(vars->str)++;
		if(*(vars->str) == '0')
		{
			(vars->str)++;
			return;	
		}
		vars->state = 1;
		vars->flags[minus] = 1;
		vars->flag_counter[minus] = ft_atoi((vars->str));
		if(*(vars->str ) >= '0' && *(vars->str) <= '9')
			vars->int_len[minus] = int_len(vars,vars->flag_counter[minus]);
		else
			vars->int_len[minus] = 0;
		//printf("flag - counter: %d len:%d\n",vars->flag_counter[minus],vars->int_len[minus]);
		return;
	}
	if(*(vars->str) == '0')
	{
		(vars->str)++ ;
		vars->state = 1;
		vars->flags[zero] = 1;
		vars->flag_counter[zero] = ft_atoi(vars->str);
		if(*(vars->str ) >= '0' && *(vars->str) <= '9')
			vars->int_len[zero] = int_len(vars,vars->flag_counter[zero]);
		else
			vars->int_len[zero] = 0;
		//printf("flag 0 counter: %d len:%d\n",vars->flag_counter[zero],vars->int_len[zero]);
		return;
	}
	tmp = ft_atoi(vars->str);
	if(tmp > 0)
	{
		vars->flags[width] = 1;
		vars->flag_counter[width] = tmp;
		vars->int_len[width]=int_len(vars,vars->flag_counter[width]);
		//printf("flag width counter: %d len:%d\n",vars->flag_counter[width],vars->int_len[width]);
	}

	if(*(vars->str) == '.')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[precision] = 1;
		vars->flag_counter[precision] = ft_atoi((vars->str));
		if(*(vars->str ) >= '0' && *(vars->str) <= '9')
			vars->int_len[precision] = int_len(vars,vars->flag_counter[precision]);
		else
			vars->int_len[precision] = 0;
		//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);
	}
	if(*(vars->str) == '#')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[hashtag] = 1;
	}
	if(*(vars->str) == '+')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[plus] = 1;
	}
	if(*(vars->str) == ' ')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[space] = 1;
	}
}
#include <string.h>
int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_vars *vars;
	int tracker;
	int i;
	
	vars = libft_calloc(1,sizeof(t_vars));
	if(!vars)
		return 0;
	va_start(args, str);
	tracker = 0;
	vars->tracker = &tracker;
	vars->str = ft_strdup((char *)str);
	char *tmp;
	tmp = vars->str;
	while (*(vars->str))
	{
		if (*(vars->str) == '%')
		{
			(vars->str)++;
			while(!ft_strchr("cspdiuxX%",*(vars->str)))
			{	
				//printf("\nREAD: %s\n",vars->str);
				i=-1;
				while(++i<7)
					vars->int_len[i] = 0;
				scan_flags(vars);
				vars->str += vars->int_len[width] + vars->int_len[zero] + vars->int_len[precision] + vars->int_len[minus];
				//printf("flag . counter: %d len:%d\n",vars->flag_counter[precision],vars->int_len[precision]);
			}
			print_specifiers(args,vars);
		}
		else
			ft_putchar(*(vars->str),vars);		
		(vars->str)++;
	}
	va_end(args);
	free(tmp);
	free(vars);
	return (tracker);
}

