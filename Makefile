SERVER = server
CLIENT = client
LIBFT = libft/libft.a
SRCS = server.c client.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
GFLAGS = -Wall -Werror -Wextra

all: server client libft


server: server.o $(LIBFT)
		$(CC) $(GFLAGS) server.c $(LIBFT) -o $@
		@echo "$(SERVER) creado"

client: client.o $(LIBFT)
		$(CC) $(GFLAGS) client.c $(LIBFT) -o $@
		@echo "$(CLIENT) creado"

$(LIBFT): 
		@make -C libft -s

clean: 
		@rm -rf $(OBJS)
		@make clean -C libft -s
		@echo "Archivos de objetos eliminados"

fclean: clean
		@make fclean -C libft -s
		@rm -rf $(SERVER) $(CLIENT)
		@echo "Ejecutables $(SERVER) y $(CLIENT) eliminados"

.PHONY: libft server clean fclean all