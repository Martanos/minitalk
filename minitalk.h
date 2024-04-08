/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:32:56 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 16:23:07 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Libft/libft.h"
# include <signal.h>

# define SIGNAL_BIT_0 SIGUSR1
# define SIGNAL_BIT_1 SIGUSR2
# define SIGNAL_CHAR_END SIGUSR1

typedef struct s_message
{
	unsigned char	buffer[4];
	ssize_t			message_len;
}					t_message;

void				send_char(pid_t server_pid, unsigned char *utf8_char,
						int len);
void				send_string(pid_t server_pid, const char *str);
void				handle_signal(int signal);
void				receive_char(t_message utf8_char);

#endif