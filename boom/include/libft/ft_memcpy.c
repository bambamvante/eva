/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:07:07 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/09 23:12:34 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if ((!dst) && (!src))
		return (dst);
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

// int	main(void)
// {
// 	char	dst[6];

// 	printf("%s\n", (char *) ft_memcpy(dst, "hello world bam", 10));
// 	printf("%s\n", (char *) ft_memcpy(dst, "hello world bam", 0));
// }
