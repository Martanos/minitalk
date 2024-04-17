/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:32:56 by malee             #+#    #+#             */
/*   Updated: 2024/04/18 00:20:58 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Libft/libft.h"
# include <stdint.h>
# include <sys/signal.h>
# include <sys/types.h>

# define POSITIVE_BIT SIGUSR1
# define ZERO_BIT SIGUSR2
# define ACK_BIT_SIGNAL SIGUSR1
# define ACK_MESSAGE_SIGNAL SIGUSR2

typedef struct s_session
{
	char	*message;
	int		bit_position;
	char	byte[2];
}			t_session;

#endif