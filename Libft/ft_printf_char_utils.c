/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:50:55 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:05:24 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	handle_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (write(1, &c, 1));
}

ssize_t	handle_string(va_list *args)
{
	char	*str;
	ssize_t	count;

	count = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

ssize_t	handle_digit(size_t n, int base, const char *symbols, int is_signed)
{
	char	buffer[64];
	ssize_t	count;
	int		idx;

	count = 0;
	if (is_signed && (ssize_t)n < 0)
	{
		count += write(1, "-", 1);
		n = (size_t) - (ssize_t)n;
	}
	idx = 0;
	if (n == 0)
		buffer[idx++] = symbols[0];
	while (n > 0)
	{
		buffer[idx++] = symbols[n % base];
		n /= base;
	}
	while (idx > 0)
		count += write(1, &buffer[--idx], 1);
	return (count);
}
