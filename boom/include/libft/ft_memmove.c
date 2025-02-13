/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:52:13 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/09 23:14:58 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	while (n--)
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return ((char *)dst);
}

// int	main()
// {
// 	char dst[100];
// 	printf("%s", (char *) ft_memmove(dst, "abcd", 3));
// }
