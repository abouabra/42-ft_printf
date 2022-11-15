/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/15 20:07:45 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	general_single_flag(t_vars *vars, int len_of_int, int n, int index)
{
	if (index == zero || index == precision)
		handle_padding(vars, vars->flag_counter[index], len_of_int, '0');
	if (index != precision || (index == precision && n != 0))
		ft_putnbr_base_original(n, BASE_D, vars);
	if (index == minus)
		handle_padding(vars, vars->flag_counter[index], len_of_int, ' ');
	set_the_end(vars, index);
}

void	general_multiple_flag(t_vars *vars, int len_of_int, int n, int index)
{
	if (n < 0)
		vars->flag_counter[index]--;
	if (vars->flag_counter[precision] < int_len(vars, n))
		vars->flag_counter[precision] = len_of_int;
	if (index == minus)
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
	else if (index == zero)
		handle_padding(vars, vars->flag_counter[zero],
			vars->flag_counter[precision], ' ');
	if (index == zero && n < 0)
	{
		ft_putchar_original('-', vars);
		vars->flag_counter[precision]--;
		len_of_int--;
	}
	if (index == zero)
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
	if (n != 0)
			ft_putnbr_base_original(n, BASE_D, vars);
	if (index == minus)
		handle_padding(vars, vars->flag_counter[minus],
			vars->flag_counter[precision], ' ');
	set_the_end(vars, precision);
	set_the_end(vars, index);
}

void	general_single_flag_b2(t_vars *vars, int len_of_int, int n, int index)
{
	vars->flags[index] = 0;
	if (n >= 0)
		len_of_int++;
	handle_width(vars, len_of_int);
	if (n < 0)
		ft_putchar_original('-', vars);
	if (n >= 0)
	{
		if (index == plus)
			ft_putchar_original('+', vars);
		else if (index == space)
			ft_putchar_original(' ', vars);
	}
	ft_putnbr_base_original(n, BASE_D, vars);
	set_the_end(vars, index);
}

void	print_flags(t_vars *vars, int len_of_int, int n)
{
	if (vars->flags[zero] == 1)
	{
		if (vars->flags[precision] == 1)
			general_multiple_flag(vars, len_of_int, n, zero);
		else
			general_single_flag(vars, len_of_int, n, zero);
	}
	if (vars->flags[minus] == 1)
	{
		if (vars->flags[precision] == 1)
			general_multiple_flag(vars, len_of_int, n, minus);
		else
			general_single_flag(vars, len_of_int, n, minus);
	}
	if (vars->flags[precision] == 1)
		general_single_flag(vars, len_of_int, n, precision);
	if (vars->flags[plus] == 1)
		general_single_flag_b2(vars, len_of_int, n, plus);
	if (vars->flags[space] == 1)
		general_single_flag_b2(vars, len_of_int, n, space);
}

void	ft_putnbr(int n, t_vars *vars)
{
	int	len_of_int;

	len_of_int = int_len(vars, n);
	if (n == 0 && vars->flags[precision] == 1)
		len_of_int--;
	if (vars->flags[plus] != 1 && vars->flags[space] != 1
		&& vars->flags[precision] != 1)
		handle_width(vars, int_len(vars, n));
	if (n < 0 && vars->flags[plus] != 1 && vars->flags[space] != 1
		&& (vars->flags[precision] != 1 || vars->flags[zero] != 1))
	{
		ft_putchar_original('-', vars);
	}
	if (vars->state == 0)
	{
		ft_putnbr_base_original(n, BASE_D, vars);
		return ;
	}
	print_flags(vars, len_of_int, n);
}
