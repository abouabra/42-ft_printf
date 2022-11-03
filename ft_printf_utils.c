/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 20:20:31 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *tracker,t_vars *vars)
{
	write(1, &c, 1);
	(*tracker)++;
	(void)vars;
}

void	ft_putstr(char *s, int *tracker,t_vars *vars)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], tracker,vars);
		i++;
	}
}

void	ft_put_unsigned_nbr(unsigned int nb, int *tracker,t_vars *vars)
{
	if (nb >= 10)
	{
		ft_put_unsigned_nbr(nb / 10, tracker,vars);
		ft_put_unsigned_nbr(nb % 10, tracker,vars);
	}
	else
		ft_putchar(nb + '0', tracker,vars);
}

void	ft_put_hex_nbr(unsigned int nb, char x, int *tracker,t_vars *vars)
{
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_put_hex_nbr(nb / 16, x, tracker,vars);
		ft_put_hex_nbr(nb % 16, x, tracker,vars);
	}
	else
		ft_putchar(base[nb % 16], tracker,vars);
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