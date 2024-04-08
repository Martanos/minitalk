/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:58:32 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:06:14 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t len)
{
	char	*dupper;
	size_t	count;

	if (!str)
		return (NULL);
	dupper = fakelloc(len + 1, sizeof(char));
	if (!dupper)
		return (NULL);
	count = 0;
	while (count < len)
	{
		dupper[count] = str[count];
		count++;
	}
	return (dupper);
}

char	*ft_strchr(const char *str, int element)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == element)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void	*fakelloc(size_t elementcount, size_t size)
{
	char	*array;

	array = malloc(elementcount * size);
	if (!array)
		return (NULL);
	while (elementcount > 0)
		array[--elementcount] = '\0';
	return ((void *)array);
}
