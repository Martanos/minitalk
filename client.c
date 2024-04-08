/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:49:23 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 16:21:26 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(pid_t server_pid, const char *str)
{
	int				len;
	unsigned char	utf8_char[4];

	while (*str)
	{
		len = 0;
		while ((*str & 0xC0) == 0x80)
			utf8_char[len++] = *str++;
		utf8_char[len++] = *str++;
		send_char(server_pid, utf8_char, len);
	}
}

void	send_char(pid_t server_pid, unsigned char *utf8_char, int len)
{
	int	bit_count;
	int	itr;

	bit_count = 0;
	while (bit_count < len)
	{
		itr = 7;
		while (itr >= 0)
		{
			if (utf8_char[bit_count] & (1 << itr))
				kill(server_pid, SIGNAL_BIT_1);
			else
				kill(server_pid, SIGNAL_BIT_0);
			usleep(100);
			itr--;
		}
		bit_count++;
	}
	kill(server_pid, SIGNAL_CHAR_END);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client [server_pid] [message]\n", 2);
		exit(1);
	}
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
