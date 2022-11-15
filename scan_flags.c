/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/07 18:19:08 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/07 18:19:08 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags_properties(t_vars *vars, int index)
{
	(vars->str)++;
	vars->state = 1;
	vars->flags[index] = 1;
	vars->flag_counter[index] = ft_atoi((vars->str));
	if (*(vars->str) >= '0' && *(vars->str) <= '9')
		vars->int_len[index] = int_len(vars, vars->flag_counter[index]);
	else
		vars->int_len[index] = 0;
}

void	scan_flags2(t_vars *vars)
{
	if (*(vars->str) == '.')
		set_flags_properties(vars, precision);
	if (*(vars->str) == '#')
		set_flags_properties(vars, hashtag);
	if (*(vars->str) == '+')
		set_flags_properties(vars, plus);
	if (*(vars->str) == ' ')
		set_flags_properties(vars, space);
}

void	scan_flags(t_vars *vars)
{
	int	tmp;

	if (*(vars->str) == '-')
	{
		if (*(vars->str + 1) == '0')
		{
			(vars->str)++;
			return ;
		}
		set_flags_properties(vars, minus);
		return ;
	}
	if (*(vars->str) == '0')
	{
		set_flags_properties(vars, zero);
		return ;
	}
	tmp = ft_atoi(vars->str);
	if (tmp > 0)
	{
		vars->flags[width] = 1;
		vars->flag_counter[width] = tmp;
		vars->int_len[width] = int_len(vars, vars->flag_counter[width]);
	}
	scan_flags2(vars);
}
