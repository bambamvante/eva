/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:16:44 by arphueng          #+#    #+#             */
/*   Updated: 2024/11/13 16:15:24 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *buffer, int i)
{
	while (*buffer)
	{
		if (*buffer == i)
			return ((char *)buffer);
		buffer++;
	}
	if (i == '\0')
		return ((char *)buffer);
	return (0);
}

char	*ft_strjoin(char *buffer, char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(buffer) + ft_strlen(tmp) + 1);
	if (!str)
		return (NULL);
	while (buffer[i] != '\0')
	{
		str[i] = buffer[i];
		i++;
	}
	while (tmp[j] != '\0')
	{
		str[i + j] = tmp[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(buffer) + 1);
	if (!res)
		return (NULL);
	while (*buffer)
		res[i++] = *buffer++;
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *buffer, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (i >= start && j < len)
		{
			str[j] = buffer[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
