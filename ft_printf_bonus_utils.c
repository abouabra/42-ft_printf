/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/07 15:08:21 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width(t_vars *vars, int int_len)
{
	vars->flags[width] = 0;
	while (int_len < vars->flag_counter[width])
	{
		ft_putchar_original(' ', vars);
		int_len++;
	}
	vars->int_len[width] = 0;
	vars->flag_counter[width] = 0;
}

void	handle_padding(t_vars *vars, int flag_counter, int int_len, char c)
{
	if (vars->flags[minus] != 1 && vars->flags[width] == 1)
	{
		handle_width(vars, flag_counter);
	}
	while (int_len < flag_counter)
	{
		ft_putchar_original(c, vars);
		int_len++;
	}
}

void	set_the_end(t_vars *vars, int index)
{
	vars->flags[index] = 0;
	vars->int_len[index] = 0;
	vars->flag_counter[index] = 0;
	vars->state = 0;
}

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
