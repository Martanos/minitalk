/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:49:25 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 16:43:53 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static t_message	utf8_char;
	static int			bit_count;

	if (signal == SIGNAL_BIT_0)
		bit_count++;
	else if (signal == SIGNAL_BIT_1)
	{
		utf8_char.buffer[utf8_char.message_len] |= (1 << (7 - bit_count % 8));
		bit_count++;
	}
	if (bit_count == 8)
	{
		utf8_char.message_len++;
		bit_count = 0;
		if ((utf8_char.buffer[utf8_char.message_len - 1] & 0xC0) != 0xC0 ||
			utf8_char.message_len == 4)
		{
			receive_char(utf8_char);
			ft_memset(&utf8_char, 0, sizeof(t_message));
			utf8_char.message_len = 0;
		}
	}
}

void	receive_char(t_message utf8_char)
{
	write(1, utf8_char.buffer, utf8_char.message_len);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGNAL_BIT_0, &sa, NULL) == -1
		|| sigaction(SIGNAL_BIT_1, &sa, NULL) == -1
		|| sigaction(SIGNAL_CHAR_END, &sa, NULL) == -1)
	{
		ft_printf("Error: sigaction failed\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
