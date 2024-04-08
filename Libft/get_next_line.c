/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:55:36 by malee             #+#    #+#             */
/*   Updated: 2024/04/08 15:04:02 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buffer_clear(char *read_buffer)
{
	if (read_buffer)
	{
		while (*read_buffer)
			*read_buffer++ = '\0';
	}
}

ssize_t	read_to_buffer(int fd, char **payload,
	char *read_buffer, ssize_t *read_bytes)
{
	char	*temp;

	if (!*payload)
	{
		*payload = fakelloc(1, sizeof(char));
		if (!*payload)
			return (-1);
	}
	*read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (*read_bytes > 0)
	{
		temp = ft_strjoin(*payload, read_buffer);
		free(*payload);
		*payload = temp;
		if (ft_strchr(*payload, '\n'))
			break ;
		if (*read_buffer)
			buffer_clear(read_buffer);
		*read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	return (*read_bytes);
}

char	*extract_line(char **payload)
{
	char	*line_end;
	char	*line;
	char	*temp;

	line_end = ft_strchr(*payload, '\n');
	if (line_end && *(line_end + 1))
	{
		line = ft_strndup(*payload, line_end - *payload + 1);
		if (!line)
			return (NULL);
		temp = ft_strndup(line_end + 1, ft_strlen(line_end + 1));
		free(*payload);
		*payload = temp;
	}
	else
	{
		line = ft_strndup(*payload, ft_strlen(*payload));
		if (!line)
			return (NULL);
		free(*payload);
		*payload = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*payload[1024];
	char		*read_buffer;
	ssize_t		read_bytes;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = fakelloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	read_bytes = -1;
	read_bytes = read_to_buffer(fd, &payload[fd], read_buffer, &read_bytes);
	free(read_buffer);
	if (read_bytes == 0 && !*payload[fd])
	{
		free(payload[fd]);
		payload[fd] = NULL;
		return (NULL);
	}
	if (read_bytes < 0)
	{
		free(payload[fd]);
		payload[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&payload[fd]));
}
