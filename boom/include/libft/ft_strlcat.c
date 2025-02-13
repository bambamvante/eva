/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:14:24 by arphueng          #+#    #+#             */
/*   Updated: 2024/08/31 16:59:03 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	buffer;

	i = 0;
	j = ft_strlen(dst);
	buffer = ft_strlen(dst) + ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[i] && j < size - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (buffer);
}

// int	main(void)
// {
// 	char dest[] = "01";
// 	char src[] = "234";
// 	printf("%zu\n", ft_strlcat(dest, src, 10));
// 	printf("dest: %s\nsrc:	%s\n", dest, src);
// }