/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:18:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 20:04:59 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_vars{
    int width;
    int flags[6];
    int int_len[3];
    int flag_counter[3];
    int state;
} t_vars;

enum {
    zero,
    precision,
    minus,
    plus,
    hashtag,
    space,
};

int		ft_printf(const char *str, ...);

void	ft_putnbr(int n, int *tracker,t_vars *vars);
void	ft_putnbr_original(int n, int *tracker,t_vars *vars);


void	ft_putchar(char c, int *tracker,t_vars *vars);
void	ft_putstr(char *s, int *tracker,t_vars *vars);
void	ft_put_unsigned_nbr(unsigned int nb, int *tracker,t_vars *vars);
void	ft_put_hex_nbr(unsigned int nb, char x, int *tracker,t_vars *vars);
void	ft_put_adress(void *ptr, int *tracker,t_vars *vars);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t nitems, size_t size);
int     int_len(long n);
int     ft_atoi(const char *str);

#endif
