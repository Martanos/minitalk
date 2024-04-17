# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 10:46:26 by malee             #+#    #+#              #
#    Updated: 2024/04/15 23:11:06 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -L$(LIBFT_DIR)
LIBFT_DIR = Libft

SRCS_CLIENT = client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER = server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: libft client server

libft:
	$(MAKE) -C $(LIBFT_DIR)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER) -L$(LIBFT_DIR) -lft

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f client server

re: fclean all