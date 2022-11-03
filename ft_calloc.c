/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:27:26 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 18:11:24 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	if (size >= SIZE_MAX || nitems >= SIZE_MAX)
		return (0);
	str = malloc(nitems * size);
	if (!str)
		return (0);
	ft_memset(str, 0,nitems * size);
	return (str);
}
