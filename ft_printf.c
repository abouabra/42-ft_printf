/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 20:25:43 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	adress_helper(unsigned long long nb, int *tracker,t_vars *vars)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		adress_helper(nb / 16, tracker,vars);
		adress_helper(nb % 16, tracker,vars);
	}
	else
		ft_putchar(base[nb % 16], tracker,vars);
}

void	ft_put_adress(void *ptr, int *tracker,t_vars *vars)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	ft_putstr("0x", tracker,vars);
	adress_helper(nb, tracker,vars);
}

void	print_specifiers(va_list args, char str, int *tracker,t_vars *vars)
{
	if (str == 'c')
		ft_putchar(va_arg(args, int), tracker,vars);
	if (str == '%')
		ft_putchar('%', tracker,vars);
	if (str == 's')
		ft_putstr(va_arg(args, char *), tracker,vars);
	if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(args, int), tracker,vars);
	if (str == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), tracker,vars);
	if (str == 'x')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'x', tracker,vars);
	if (str == 'X')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'X', tracker,vars);
	if (str == 'p')
		ft_put_adress(va_arg(args, void *), tracker,vars);
}

void scan_flags(t_vars *vars,char *str)
{
	// reserved for width
	// if(*str == '-')
	// {
	// 	str++;
	// 	vars->flags[zero] = 1;
	// 	vars->flag_counter[zero] = atoi(str);
	// 	vars->int_len[zero] = int_len(vars->flag_counter[zero]);
	// 	return 1;
	// }
	if(*str == '0')
	{
		str++;
		vars->flags[zero] = 1;
		vars->flag_counter[zero] = ft_atoi(str);
		vars->int_len[zero] = int_len(vars->flag_counter[zero]);
		printf("flag counter: %d int len:%d\n",vars->flag_counter[zero],vars->int_len[zero]);
	}
	if(*str == '-')
	{
		str++;
		vars->flags[minus] = 1;
		vars->flag_counter[minus] = ft_atoi(str);
		vars->int_len[minus] = int_len(vars->flag_counter[minus]);
	}
	if(*str == '.')
	{
		str++;
		vars->flags[precision] = 1;
		vars->flag_counter[precision] = ft_atoi(str);
		vars->int_len[precision] = int_len(vars->flag_counter[precision]);
	}
	if(*str == '#')
	{
		str++;
		vars->flags[hashtag] = 1;
	}
	if(*str == '+')
	{
		str++;
		vars->flags[plus] = 1;
	}
	if(*str == ' ')
	{
		str++;
		vars->flags[space] = 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		tracker;
	va_list	args;
	t_vars *vars;

	vars = ft_calloc(1,sizeof(t_vars));
	if(!vars)
		return 0;
	tracker = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printf("STR1: %s  \n",str);
			scan_flags(vars,(char *)str);
			printf("STR2: %s  \n",str);
			str += vars->int_len[zero] + vars->int_len[precision] + vars->int_len[minus];
			printf("STR3: %s  \n",str);
			print_specifiers(args, *str, &tracker,vars);
		}
		else
			ft_putchar(*str, &tracker,vars);
		str++;
	}
	va_end(args);
	return (tracker);
}

int main()
{
	ft_printf("%0100d",100);
	return 0;
}