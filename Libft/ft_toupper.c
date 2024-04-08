/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:58:57 by malee             #+#    #+#             */
/*   Updated: 2023/09/11 20:58:58 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert alpha character to higher case version*/

#include "libft.h"

int	ft_toupper(int input)
{
	if (input >= 97 && input <= 122)
		return (input - 32);
	return (input);
}
