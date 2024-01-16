NAME = libft.a

SRCS = ft_print_addr.c ft_print_hex.c ft_print_int.c ft_print_uint.c\
	ft_putchar_len.c ft_putstr_len.c ft_printf.c ft_atoi.c ft_isdigit.c\


OBJS = $(SRCS:.c=.o)


CC = @gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		echo "$(NAME) Creada"

%.o: %.c 
		$(CC) $(GFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) eliminado"

re: fclean all

.PHONY: clean fclean all re
