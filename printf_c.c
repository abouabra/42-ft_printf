/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:23:12 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/06 19:23:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_original(char c, t_vars *vars)
{
	write(1, &c, 1);
	(*(vars->tracker))++;
	(void)vars;
}

void	ft_putchar(char c, t_vars *vars)
{
	handle_width(vars, 1);
	if (vars->state == 0)
	{
		ft_putchar_original(c, vars);
		return ;
	}
	if (vars->flags[minus] == 1)
	{
		ft_putchar_original(c, vars);
		handle_padding(vars, vars->flag_counter[minus], 1, ' ');
		vars->flags[minus] = 0;
		vars->int_len[minus] = 0;
		vars->flag_counter[minus] = 0;
		vars->state = 0;
	}
}
