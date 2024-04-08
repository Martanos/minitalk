/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:45 by malee             #+#    #+#             */
/*   Updated: 2023/09/14 19:51:13 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares 2 strings and return
	the difference in their ASCII values*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (idx < n)
	{
		if (s1[idx] && s1[idx] == s2[idx])
		{
			while (s1[idx] && s1[idx] == s2[idx] && idx < n)
				idx++;
		}
		else
		{
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
	}
	return (0);
}
