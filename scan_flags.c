/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/06 16:07:19 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	scan_flags4(t_vars *vars)
{
	if (*(vars->str) == '#')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[hashtag] = 1;
	}
	if (*(vars->str) == '+')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[plus] = 1;
	}
	if (*(vars->str) == ' ')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[space] = 1;
	}
}

void	scan_flags3(t_vars *vars)
{
	int	tmp;

	tmp = ft_atoi(vars->str);
	if (tmp > 0)
	{
		vars->flags[width] = 1;
		vars->flag_counter[width] = tmp;
		vars->int_len[width] = int_len(vars, vars->flag_counter[width]);
	}
	if (*(vars->str) == '.')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[precision] = 1;
		vars->flag_counter[precision] = ft_atoi((vars->str));
		if (*(vars->str) >= '0' && *(vars->str) <= '9')
			vars->int_len[precision] = int_len(vars,
					vars->flag_counter[precision]);
		else
			vars->int_len[precision] = 0;
	}
	scan_flags4(vars);
}

void	scan_flags2(t_vars *vars)
{
	if (*(vars->str) == '0')
	{
		(vars->str)++;
		vars->state = 1;
		vars->flags[zero] = 1;
		vars->flag_counter[zero] = ft_atoi(vars->str);
		if (*(vars->str) >= '0' && *(vars->str) <= '9')
			vars->int_len[zero] = int_len(vars, vars->flag_counter[zero]);
		else
			vars->int_len[zero] = 0;
		return ;
	}
	scan_flags3(vars);
}

void	scan_flags(t_vars *vars)
{
	if (*(vars->str) == '-')
	{
		(vars->str)++;
		if (*(vars->str) == '0')
		{
			(vars->str)++;
			return ;
		}
		vars->state = 1;
		vars->flags[minus] = 1;
		vars->flag_counter[minus] = ft_atoi((vars->str));
		if (*(vars->str) >= '0' && *(vars->str) <= '9')
			vars->int_len[minus] = int_len(vars, vars->flag_counter[minus]);
		else
			vars->int_len[minus] = 0;
		return ;
	}
	scan_flags2(vars);
}
