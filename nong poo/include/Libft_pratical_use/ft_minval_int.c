/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minval_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:54:35 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/02 01:55:46 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that will return the lowest value in an integer array
 * 
 * @param num_arr An integer array to search for target value
 * 
 * @return The lowest value from parameter
 */
int	ft_minval_int(int *num_arr, size_t size)
{
	size_t	i;
	int		res;

	if (num_arr == NULL || !*num_arr)
		return (0);
	i = 0;
	res = num_arr[i++];
	while (i < size)
	{
		if (num_arr[i] < res)
			res = num_arr[i];
		i++;
	}
	return (res);
}
