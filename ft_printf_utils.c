/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 03:42:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c,t_vars *vars)
{
	write(1, &c, 1);
	(*(vars->tracker))++;
	(void) vars;
}

void	ft_putstr(char *s,t_vars *vars)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i],vars);
		i++;
	}
}

void	ft_put_unsigned_nbr(unsigned int nb,t_vars *vars)
{
	if (nb >= 10)
	{
		ft_put_unsigned_nbr(nb / 10,vars);
		ft_put_unsigned_nbr(nb % 10,vars);
	}
	else
		ft_putchar(nb + '0',vars);
}


int	int_len(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		counter++;
	}
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}