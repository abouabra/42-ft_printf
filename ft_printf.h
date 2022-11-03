/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:18:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/11/03 19:46:20 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_vars{
    char *str;
    int *tracker;
    int flags[7];
    int int_len[7];
    int flag_counter[7];
    int state;
} t_vars;

enum {
    zero,
    precision,
    minus,
    plus,
    hashtag,
    space,
    width,
};

int		ft_printf(const char *str, ...);

void	ft_putnbr(int n,t_vars *vars);
void	ft_putnbr_original(int n,t_vars *vars);

void	ft_put_hex_original(unsigned int nb, char x,t_vars *vars);
void	ft_put_hex_nbr(unsigned int nb, char x,t_vars *vars);
void handle_width(t_vars *vars, int int_len);
void handle_padding(t_vars *vars,int flag_counter,int int_len,char c);

void	ft_putchar(char c,t_vars *vars);
void	ft_putchar_original(char c,t_vars *vars);
int     ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	ft_putstr(char *s,t_vars *vars);
void	ft_put_unsigned_nbr(unsigned int nb,t_vars *vars);
void	ft_put_adress(void *ptr,t_vars *vars);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*libft_calloc(size_t nitems, size_t size);
int	int_len(t_vars *vars,long n);
int     hex_len(unsigned int n);
int     ft_atoi(char *str);

#endif
