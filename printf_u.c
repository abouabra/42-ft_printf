/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:17:29 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/07 18:10:31 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_int_len(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

void	ft_put_unbr_original(unsigned int nb, t_vars *vars)
{
	if (nb >= 10)
	{
		ft_put_unbr_original(nb / 10, vars);
		ft_put_unbr_original(nb % 10, vars);
	}
	else
		ft_putchar_original(nb + '0', vars);
}

void	unsigned_flag_minus(t_vars *vars, int len_of_int, unsigned int nb)
{
	if (vars->flags[minus] == 1)
	{
		if (vars->flags[precision] == 1)
		{
			handle_padding(vars, vars->flag_counter[precision],
				len_of_int, '0');
			if (nb != 0)
				ft_put_unbr_original(nb, vars);
			if (vars->flag_counter[precision] < u_int_len(nb))
				vars->flag_counter[precision] = len_of_int;
			handle_padding(vars, vars->flag_counter[minus],
				vars->flag_counter[precision], ' ');
			set_the_end(vars, precision);
			set_the_end(vars, minus);
			return ;
		}
		ft_put_unbr_original(nb, vars);
		handle_padding(vars, vars->flag_counter[minus], len_of_int, ' ');
		set_the_end(vars, minus);
	}
}

void	unsigned_flag_zero(t_vars *vars, int len_of_int, unsigned int nb)
{
	if (vars->flags[zero] == 1)
	{
		if (vars->flags[precision] == 1)
		{
			if (vars->flag_counter[precision] < u_int_len(nb))
				vars->flag_counter[precision] = len_of_int;
			handle_padding(vars, vars->flag_counter[zero],
				vars->flag_counter[precision], ' ');
			handle_padding(vars, vars->flag_counter[precision],
				len_of_int, '0');
			if (nb != 0)
				ft_put_unbr_original(nb, vars);
			set_the_end(vars, precision);
			set_the_end(vars, zero);
			return ;
		}
		handle_padding(vars, vars->flag_counter[zero], len_of_int, '0');
		ft_put_unbr_original(nb, vars);
		set_the_end(vars, zero);
	}
}

void	ft_put_unsigned_nbr(unsigned int nb, t_vars *vars)
{
	int	len_of_int;

	len_of_int = u_int_len(nb);
	if (nb == 0 && vars->flags[precision] == 1)
		len_of_int--;
	if (vars->flags[precision] != 1)
		handle_width(vars, u_int_len(nb));
	if (vars->state == 0)
	{
		ft_put_unbr_original(nb, vars);
		return ;
	}
	unsigned_flag_zero(vars, len_of_int, nb);
	unsigned_flag_minus(vars, len_of_int, nb);
	if (vars->flags[precision] == 1)
	{
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
		if (nb != 0)
			ft_put_unbr_original(nb, vars);
		set_the_end(vars, precision);
	}
}
