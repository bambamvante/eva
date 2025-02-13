/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:31:20 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/08 18:16:36 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char )c)
			return (tmp);
		tmp++;
	}
	if ((char )c == '\0')
		return (tmp);
	return (NULL);
}

// int main()
// {
//     printf("%s\n", ft_strchr("123421335", '5'));
// }