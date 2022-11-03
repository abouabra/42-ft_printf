SRC= ft_printf.c ft_printf_utils.c printf_d.c printf_x.c printf_p.c ft_libft.c

OBJS=$(SRC:.c=.o)
AR=ar -rcs
NAME=libftprintf.a
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

%.o:%.c
	@$(CC) -Wall -Wextra -Werror -c $<

bonus: fclean all

printf: fclean $(NAME)
	@gcc main.c $(NAME)
	@./a.out
clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o libftprintf.a

re:fclean all

.PHONY: all clean fclean re