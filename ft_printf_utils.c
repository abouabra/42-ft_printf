/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 19:51:43 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putstr(char *s,t_vars *vars)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar_original(s[i],vars);
		i++;
	}
}



int	int_len(t_vars *vars,long n)
{
	int	counter;
	(void) vars;
	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		if(vars->flags[precision] != 1)
			counter++;
	}
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}