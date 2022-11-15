/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:37:20 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/15 20:24:19 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(t_vars *vars, long n)
{
	int	counter;

	(void)vars;
	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		if (vars->flags[precision] != 1)
			counter++;
	}
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	final;

	i = 0;
	sign = 1;
	final = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + str[i] - '0';
		i++;
	}
	return (final * sign);
}

// void	ft_putnbr_original(int n, t_vars *vars)
// {
// 	long	nb;
	
// 	nb = n;
// 	if (nb < 0)
// 	{
// 		nb = nb * -1;
// 	}
// 	if (nb >= 10)
// 	{
// 		ft_putnbr_original(nb / 10, vars);
// 		ft_putnbr_original(nb % 10, vars);
// 	}
// 	else
// 		ft_putchar_original(nb + '0', vars);
// }
void	ft_putnbr_base_originalTEST(unsigned long long nb, char *base,t_vars *vars)
{
	unsigned long long baselen;

	baselen = ft_strlen(base);
	if (nb >= baselen)
	{
		ft_putnbr_base_originalTEST(nb / baselen, base, vars);
		ft_putnbr_base_originalTEST(nb % baselen, base ,vars);
	}
	else
		ft_putchar_original(nb + '0', vars);
}
void	ft_putnbr_base_original(long long nb, char *base,t_vars *vars)
{
	int baselen;

	baselen = ft_strlen(base);
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= baselen)
	{
		ft_putnbr_base_original(nb / baselen, base, vars);
		ft_putnbr_base_original(nb % baselen, base ,vars);
	}
	else
		ft_putchar_original(nb + '0', vars);
}