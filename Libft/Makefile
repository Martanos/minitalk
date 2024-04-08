# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 20:12:49 by malee             #+#    #+#              #
#    Updated: 2024/04/08 15:47:35 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
       ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
       ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
       ft_lstiter.c ft_lstmap.c \
       ft_printf.c ft_printf_char_utils.c ft_printf_integer_utils.c \
       get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
