# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 19:07:22 by krazikho          #+#    #+#              #
#    Updated: 2024/07/20 21:58:59 by krazikho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_putchar_len.c ft_printf/ft_puthex_len.c ft_printf/ft_putnbr_len.c ft_printf/ft_putptr_len.c ft_printf/ft_putstr_len.c ft_printf/ft_putunbr_len.c
SERVER_SRCS = server.c
CLIENT_SRCS = client.c mt_atoi.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c mt_atoi.c

FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o) $(FT_PRINTF_OBJS)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)  $(FT_PRINTF_OBJS) 
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o) $(FT_PRINTF_OBJS)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)  $(FT_PRINTF_OBJS) 


all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(CLIENT_OBJS) $(SERVER_OBJS) $(FT_PRINTF_OBJS)
	rm -rf $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re