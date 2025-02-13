/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:43:14 by arphueng          #+#    #+#             */
/*   Updated: 2024/11/15 18:52:39 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *leftover)
{
	int		byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		tmp = leftover;
		leftover = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

char	*get_leftover(char *line)
{
	int		len;
	char	*leftover;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	if (line[len] == '\0' || line[1] == '\0')
		return (NULL);
	leftover = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
	}
	line[len + 1] = '\0';
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, leftover);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		leftover = NULL;
		return (NULL);
	}
	leftover = get_leftover(line);
	return (line);
}
