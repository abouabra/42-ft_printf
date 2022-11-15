/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:18:14 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/15 20:06:07 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long n)
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

void	adress_helper(unsigned long long nb, t_vars *vars)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		adress_helper(nb / 16, vars);
		adress_helper(nb % 16, vars);
	}
	else
		ft_putchar_original(base[nb % 16], vars);
}

void	ft_put_adress_original(void *ptr, t_vars *vars)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	adress_helper(nb, vars);
}

void	ft_put_adress(void *ptr, t_vars *vars)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	if (vars->flags[precision] != 1)
		handle_width(vars, ptr_len(nb) + 2);
	if (vars->flags[zero] != 1)
		ft_putstr_original("0x", vars);
	if (vars->state == 0)
	{
		ft_put_adress_original(ptr, vars);
		return ;
	}
	if (vars->flags[zero] == 1)
	{
		handle_padding(vars, vars->flag_counter[zero], ptr_len(nb) + 2, '0');
		ft_putstr_original("0x", vars);
		ft_put_adress_original(ptr, vars);
		set_the_end(vars, zero);
	}
	if (vars->flags[minus] == 1)
	{
		ft_put_adress_original(ptr, vars);
		handle_padding(vars, vars->flag_counter[minus], ptr_len(nb) + 2, ' ');
		set_the_end(vars, minus);
	}
}
