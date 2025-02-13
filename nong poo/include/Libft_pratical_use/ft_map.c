/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:40:40 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/02 02:00:47 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*map_case_str(char *str, int (*f)(int))
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = f(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
