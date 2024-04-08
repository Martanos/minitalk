# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 10:46:26 by malee             #+#    #+#              #
#    Updated: 2024/04/08 16:04:41 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -L$(LIBFT_DIR)
LIBFT_DIR = Libft

all: libft client server

libft:
	$(MAKE) -C $(LIBFT_DIR)

client: client.c minitalk.h
	$(CC) $(CFLAGS) -o client client.c -L$(LIBFT_DIR) -lft

server: server.c minitalk.h
	$(CC) $(CFLAGS) -o server server.c -L$(LIBFT_DIR) -lft

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f client server

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all