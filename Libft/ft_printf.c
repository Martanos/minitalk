/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:55:48 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:55:48 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_handlers(t_conversion_handlers *handlers)
{
	handlers[0] = (t_conversion_handlers){'c', &handle_char};
	handlers[1] = (t_conversion_handlers){'s', &handle_string};
	handlers[2] = (t_conversion_handlers){'p', &handle_pointer};
	handlers[3] = (t_conversion_handlers){'x', &handle_lower_hex};
	handlers[4] = (t_conversion_handlers){'X', &handle_upper_hex};
	handlers[5] = (t_conversion_handlers){'i', &handle_int};
	handlers[6] = (t_conversion_handlers){'d', &handle_int};
	handlers[7] = (t_conversion_handlers){'u', &handle_uint};
	handlers[8] = (t_conversion_handlers){'\0', NULL};
}

int	execute_handler(va_list *ap, const char **format,
		t_conversion_handlers *handlers)
{
	ssize_t	count;
	char	specifier;
	size_t	idx;

	specifier = **format;
	(*format)++;
	idx = 0;
	while (handlers[idx].handler)
	{
		if (handlers[idx].specifier == specifier)
		{
			count = handlers[idx].handler(ap);
			return (count);
		}
		idx++;
	}
	count = write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	t_conversion_handlers	handlers[9];
	ssize_t					count;

	init_handlers(handlers);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += write(1, format++, 1);
			else
				count += execute_handler(&ap, &format, handlers);
		}
		else
			count += write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}

// int main() {
//     printf("Test 6: (void *)LONG_MIN, (void *)LONG_MAX\n");
//     printf("Actual: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
//     ft_printf("Custom: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);

//     printf("\nTest 8: (void *)ULONG_MAX, (void *)-ULONG_MAX\n");
//     printf("Actual: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
//     ft_printf("Custom: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);

//     printf("\nTest 9: (void *)0, (void *)0\n");
//     printf("Actual: %p %p \n", (void *)0, (void *)0);
//     ft_printf("Custom: %p %p \n", (void *)0, (void *)0);

//     return (0);
// }