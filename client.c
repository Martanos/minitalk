/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:49:23 by malee             #+#    #+#             */
/*   Updated: 2024/04/18 03:50:45 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_acknowledgment_received = 0;

void	acknowledgment_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == ACK_BIT_SIGNAL)
		g_acknowledgment_received = 1;
	else if (sig == ACK_MESSAGE_SIGNAL)
		ft_printf("Server with pid: %d Received message\n", info->si_pid);
}

void	send_bit(pid_t server_pid, int bit)
{
	if (bit)
		kill(server_pid, POSITIVE_BIT);
	else
		kill(server_pid, ZERO_BIT);
	while (!g_acknowledgment_received)
		pause();
	g_acknowledgment_received = 0;
}

void	send_payload(pid_t server_pid, char *payload)
{
	int	jtr;

	while (*payload)
	{
		jtr = 7;
		while (jtr >= 0)
		{
			send_bit(server_pid, (*payload >> jtr) & 1);
			jtr--;
		}
		payload++;
	}
	jtr = 7;
	while (jtr >= 0)
	{
		send_bit(server_pid, 0);
		jtr--;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server_pid] [payload]\n");
		exit(1);
	}
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = acknowledgment_handler;
	sigaction(ACK_BIT_SIGNAL, &sa, NULL);
	sigaction(ACK_MESSAGE_SIGNAL, &sa, NULL);
	send_payload(ft_atoi(argv[1]), argv[2]);
	return (0);
}
