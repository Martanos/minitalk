/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:27:37 by malee             #+#    #+#             */
/*   Updated: 2023/09/14 20:50:35 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The  atoi() function converts the initial portion of the string pointed
	to by nptr to int.  The behavior is the same as

	strtol(nptr, NULL, 10);

	except that atoi() does not detect errors. */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	idx;
	int	neg;
	int	res;

	idx = 0;
	neg = 1;
	res = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = (str[idx] - '0') + (res * 10);
		idx++;
	}
	return (res * neg);
}
