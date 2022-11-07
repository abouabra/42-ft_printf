/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/06 20:24:19 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flag_minus(t_vars *vars, int len_of_int, int n)
{
	if (vars->flags[precision] == 1)
	{
		handle_padding(vars, vars->flag_counter[precision],
			len_of_int, '0');
		if (n != 0)
			ft_putnbr_original(n, vars);
		if (n < 0)
			vars->flag_counter[minus]--;
		if (vars->flag_counter[precision] < int_len(vars, n))
			vars->flag_counter[precision] = len_of_int;
		handle_padding(vars, vars->flag_counter[minus],
			vars->flag_counter[precision], ' ');
		set_the_end(vars);
		return ;
	}
	ft_putnbr_original(n, vars);
	handle_padding(vars, vars->flag_counter[minus], len_of_int, ' ');
	set_the_end(vars);
}

void	handle_flag_zero(t_vars *vars, int len_of_int, int n)
{
	if (vars->flags[precision] == 1)
	{
		if (vars->flag_counter[precision] < int_len(vars, n))
			vars->flag_counter[precision] = len_of_int;
		if (n < 0)
			vars->flag_counter[zero]--;
		handle_padding(vars, vars->flag_counter[zero],
			vars->flag_counter[precision], ' ');
		if (n < 0)
		{
			ft_putchar_original('-', vars);
			vars->flag_counter[precision]--;
			len_of_int--;
		}
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
		if (n != 0)
			ft_putnbr_original(n, vars);
		set_the_end(vars);
		return ;
	}
	handle_padding(vars, vars->flag_counter[zero], len_of_int, '0');
	ft_putnbr_original(n, vars);
	set_the_end(vars);
}

void	put_nbr_b1(t_vars *vars, int len_of_int, int n)
{
	if (vars->flags[zero] == 1)
		handle_flag_zero(vars, len_of_int, n);
	if (vars->flags[minus] == 1)
		handle_flag_minus(vars, len_of_int, n);
	if (vars->flags[precision] == 1)
	{
		handle_padding(vars, vars->flag_counter[precision], len_of_int, '0');
		if (n != 0)
			ft_putnbr_original(n, vars);
		set_the_end(vars);
	}
}

void	put_nbr_b2(t_vars *vars, int len_of_int, int n)
{
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
		set_the_end(vars);
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
		set_the_end(vars);
	}
}

void	ft_putnbr(int n, t_vars *vars)
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
	put_nbr_b2(vars, len_of_int, n);
	put_nbr_b1(vars, len_of_int, n);
}
