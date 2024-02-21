SRC= ft_printf.c scan_flags.c general_func.c ft_printf_utils.c ft_printf_bonus_utils.c printf_p.c printf_c.c printf_s.c ft_libft.c

OBJS=$(SRC:.c=.o)
AR=ar -rcs

OBJ_DIR = obj/
SRC_DIR = src/
OSRC = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
AR=ar -rcs
NAME=libftprintf.a

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: ascii $(NAME) 

$(NAME): $(OSRC)
	@$(AR) $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -Wall -Wextra -Werror -c $<  -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re:fclean all

ascii:
	@clear
	@printf "$(GREEN)\
                                                                                                                                                                                 \n\
    ffffffffffffffff           tttt                                                                           iiii                            tttt             ffffffffffffffff  \n\
   f::::::::::::::::f       ttt:::t                                                                          i::::i                        ttt:::t            f::::::::::::::::f \n\
  f::::::::::::::::::f      t:::::t                                                                           iiii                         t:::::t           f::::::::::::::::::f\n\
  f::::::fffffff:::::f      t:::::t                                                                                                        t:::::t           f::::::fffffff:::::f\n\
  f:::::f       ffffffttttttt:::::ttttttt                            ppppp   ppppppppp   rrrrr   rrrrrrrrr  iiiiiiinnnn  nnnnnnnn    ttttttt:::::ttttttt     f:::::f       ffffff\n\
  f:::::f             t:::::::::::::::::t                            p::::ppp:::::::::p  r::::rrr:::::::::r i:::::in:::nn::::::::nn  t:::::::::::::::::t     f:::::f             \n\
 f:::::::ffffff       t:::::::::::::::::t                            p:::::::::::::::::p r:::::::::::::::::r i::::in::::::::::::::nn t:::::::::::::::::t    f:::::::ffffff       \n\
 f::::::::::::f       tttttt:::::::tttttt                            pp::::::ppppp::::::prr::::::rrrrr::::::ri::::inn:::::::::::::::ntttttt:::::::tttttt    f::::::::::::f       \n\
 f::::::::::::f             t:::::t                                   p:::::p     p:::::p r:::::r     r:::::ri::::i  n:::::nnnn:::::n      t:::::t          f::::::::::::f       \n\
 f:::::::ffffff             t:::::t                                   p:::::p     p:::::p r:::::r     rrrrrrri::::i  n::::n    n::::n      t:::::t          f:::::::ffffff       \n\
  f:::::f                   t:::::t                                   p:::::p     p:::::p r:::::r            i::::i  n::::n    n::::n      t:::::t           f:::::f             \n\
  f:::::f                   t:::::t    tttttt                         p:::::p    p::::::p r:::::r            i::::i  n::::n    n::::n      t:::::t    tttttt f:::::f             \n\
 f:::::::f                  t::::::tttt:::::t                         p:::::ppppp:::::::p r:::::r           i::::::i n::::n    n::::n      t::::::tttt:::::tf:::::::f            \n\
 f:::::::f                  tt::::::::::::::t                         p::::::::::::::::p  r:::::r           i::::::i n::::n    n::::n      tt::::::::::::::tf:::::::f            \n\
 f:::::::f                    tt:::::::::::tt                         p::::::::::::::pp   r:::::r           i::::::i n::::n    n::::n        tt:::::::::::ttf:::::::f            \n\
 fffffffff                      ttttttttttt                           p::::::pppppppp     rrrrrrr           iiiiiiii nnnnnn    nnnnnn          ttttttttttt  fffffffff            \n\
                                             ________________________ p:::::p                                                                                                    \n\
                                             _::::::::::::::::::::::_ p:::::p                                                                                                    \n\
                                             ________________________p:::::::p                                                                                                   \n\
                                                                     p:::::::p                                                                      $(RED)by: abouabra $(GREEN)  \n\
                                                                     p:::::::p                                                                                                   \n\
                                                                     ppppppppp                                                                                                   \n\
                                                                                                                                                                                 \n$(RESET)\n"



.PHONY: all clean fclean re bonus