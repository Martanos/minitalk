/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:46:48 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:06:24 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef struct s_conversion_handlers
{
	char			specifier;
	ssize_t			(*handler)(va_list * args);
}					t_conversion_handlers;

int					ft_printf(const char *__format, ...);
ssize_t				handle_digit(size_t n, int base, const char *symbols,
						int is_signed);
ssize_t				handle_string(va_list *args);
ssize_t				handle_char(va_list *args);
ssize_t				handle_upper_hex(va_list *args);
ssize_t				handle_lower_hex(va_list *args);
ssize_t				handle_int(va_list *args);
ssize_t				handle_uint(va_list *args);
ssize_t				handle_pointer(va_list *args);
ssize_t				ft_strlen(char *str);
char				*get_next_line(int fd);
char				*ft_strndup(char *str, size_t len);
char				*ft_strchr(const char *str, int element);
void				*fakelloc(size_t elementcount, size_t size);
ssize_t				read_to_buffer(int fd, char **payload, char *read_buffer,
						ssize_t *read_bytes);
char				*extract_line(char **payload);
void				buffer_clear(char *read_buffer);

#endif