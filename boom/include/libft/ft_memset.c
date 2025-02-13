/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:05:18 by arphueng          #+#    #+#             */
/*   Updated: 2024/09/09 23:05:46 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		tmp[n - 1] = (char) c;
		n--;
	}
	return ((char *) tmp);
}

// int	main()
// {
// 	char str[3] = "abc";
// 	ft_memset(str, '2', 5);
// 	printf("%s\n", str);
// }
