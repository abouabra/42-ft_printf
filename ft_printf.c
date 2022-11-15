/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:01:40 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/07 18:31:25 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifiers(va_list args, t_vars *vars)
{
	if (*(vars->str) == 'c')
		ft_putchar(va_arg(args, int), vars);
	if (*(vars->str) == '%')
		ft_putchar('%', vars);
	if (*(vars->str) == 's')
		ft_putstr(va_arg(args, char *), vars);
	if (*(vars->str) == 'd' || *(vars->str) == 'i')
		ft_putnbr(va_arg(args, int), vars);
	if (*(vars->str) == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), vars);
	if (*(vars->str) == 'x')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'x', vars);
	if (*(vars->str) == 'X')
		ft_put_hex_nbr(va_arg(args, unsigned int), 'X', vars);
	if (*(vars->str) == 'p')
		ft_put_adress(va_arg(args, void *), vars);
}

void	scan_str(va_list args, t_vars *vars)
{
	int	i;

	while (*(vars->str))
	{
		if (*(vars->str) == '%')
		{
			(vars->str)++;
			while (!ft_strchr("cspdiuxX%", *(vars->str)))
			{
				i = -1;
				while (++i < 7)
					vars->int_len[i] = 0;
				scan_flags(vars);
				vars->str += vars->int_len[width] + vars->int_len[zero]
					+ vars->int_len[precision] + vars->int_len[minus];
			}
			print_specifiers(args, vars);
		}
		else
			ft_putchar_original(*(vars->str), vars);
		(vars->str)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_vars	*vars;
	int		tracker;
	char	*tmp;

	vars = libft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (0);
	va_start(args, str);
	tracker = 0;
	vars->tracker = &tracker;
	vars->str = ft_strdup((char *)str);
	tmp = vars->str;
	scan_str(args, vars);
	va_end(args);
	free(tmp);
	free(vars);
	return (tracker);
}
