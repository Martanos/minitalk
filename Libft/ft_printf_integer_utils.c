/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:34:30 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:06:27 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	handle_int(va_list *args)
{
	return (handle_digit((long long)va_arg(*args, int), 10, "0123456789", 1));
}

ssize_t	handle_uint(va_list *args)
{
	return (handle_digit((unsigned long)va_arg(*args, unsigned int), 10,
			"0123456789", 0));
}

ssize_t	handle_lower_hex(va_list *args)
{
	return (handle_digit(va_arg(*args, unsigned int), 16, "0123456789abcdef",
			0));
}

ssize_t	handle_upper_hex(va_list *args)
{
	return (handle_digit(va_arg(*args, unsigned int), 16, "0123456789ABCDEF",
			0));
}

ssize_t	handle_pointer(va_list *args)
{
	ssize_t	count;
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	count += handle_digit((size_t)ptr, 16, "0123456789abcdef", 0);
	return (count);
}
