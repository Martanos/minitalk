/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:49:25 by malee             #+#    #+#             */
/*   Updated: 2024/04/18 03:50:32 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_session	g_session = {
	.message = NULL,
	.bit_position = 7,
	.byte = {'\0', '\0'}
};

static void	handle_message(siginfo_t *info)
{
	char	*temp;

	if (g_session.byte[0] == '\0')
	{
		ft_printf("Received message: %s\n", g_session.message);
		free(g_session.message);
		g_session.message = NULL;
		kill(info->si_pid, ACK_MESSAGE_SIGNAL);
	}
	else
	{
		temp = g_session.message;
		if (!temp)
			g_session.message = ft_strdup(g_session.byte);
		else
			g_session.message = ft_strjoin(temp, g_session.byte);
		if (!g_session.message)
		{
			ft_printf("Error: Memory allocation failed\n");
			free(temp);
			temp = NULL;
			exit(1);
		}
		free(temp);
	}
}

static void	handle_bits(int sig, siginfo_t *info)
{
	if (sig == POSITIVE_BIT)
		g_session.byte[0] |= 1 << g_session.bit_position;
	g_session.bit_position--;
	if (g_session.bit_position == -1)
	{
		handle_message(info);
		g_session.bit_position = 7;
		g_session.byte[0] = '\0';
	}
	kill(info->si_pid, ACK_BIT_SIGNAL);
}

void	session_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == POSITIVE_BIT || sig == ZERO_BIT)
		handle_bits(sig, info);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = session_handler;
	sigaction(POSITIVE_BIT, &sa, NULL);
	sigaction(ZERO_BIT, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
