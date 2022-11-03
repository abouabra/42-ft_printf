SRC= ft_printf.c ft_printf_utils.c ft_atoi.c ft_calloc.c ft_memset.c print_d.c

OBJS=$(SRC:.c=.o)
AR=ar -rcs
NAME=libftprintf.a
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o:%.c
	$(CC) -Wall -Wextra -Werror -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o libftprintf.a

re:fclean all

.PHONY: all clean fclean re