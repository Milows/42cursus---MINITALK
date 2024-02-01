LIBFT = libft/libft.a
SRCS = server.c client.c
SRCS_BNS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

CC = @gcc
GFLAGS = -Wall -Werror -Wextra

all: server client

bonus: server_bonus client_bonus 

$(LIBFT): 
		@make -C libft -s

server: server.o $(LIBFT)
		$(CC) $(GFLAGS) server.c $(LIBFT) -o $@
		@echo "Server created"

client: client.o $(LIBFT)
		$(CC) $(GFLAGS) client.c $(LIBFT) -o $@
		@echo "Client created"

server_bonus: server_bonus.o $(LIBFT)
		$(CC) $(GFLAGS) server_bonus.c $(LIBFT) -o $@
		@echo "Server_bonus created"

client_bonus: client_bonus.o $(LIBFT)
		$(CC) $(GFLAGS) client_bonus.c $(LIBFT) -o $@
		@echo "Client_bonus created"

%.o: %.c 
		$(CC) $(GFLAGS) -c $< -o $@

clean: 
		@rm -rf $(OBJS) $(OBJS_BNS)
		@make clean -C libft -s
		@echo "Archivos de objetos eliminados"

fclean: clean
		@make fclean -C libft -s
		@rm -rf server client client_bonus server_bonus
		@echo "Ejecutables eliminados"

re: fclean all

.PHONY: clean fclean all re