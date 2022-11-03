/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:11 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 20:21:52 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putnbr_original(int n, int *tracker,t_vars *vars)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', tracker,vars);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, tracker,vars);
		ft_putnbr(nb % 10, tracker,vars);
	}
	else
		ft_putchar(nb + '0', tracker,vars);
}
void handle_padding(t_vars *vars,int flag_counter,int int_len,char c)
{
    while(int_len < flag_counter)
    {
        (void) vars;
        write(1, &c,1);
        int_len++;
    }
}

void	ft_putnbr(int n, int *tracker,t_vars *vars)
{
	if(vars->flags[zero] == 1)
    {
        vars->flags[zero] = 0;
        handle_padding(vars,vars->flag_counter[zero],int_len(n),'0');
        ft_putnbr_original(n,tracker,vars);
    }
}