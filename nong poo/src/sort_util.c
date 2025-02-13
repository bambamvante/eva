/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:19:36 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 15:23:11 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(unsigned int *arr, size_t size, bool reverse)
{
	size_t	i;

	i = 0;
	if (reverse)
	{
		while (i < size - 1)
		{
			if (arr[i] < arr[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}
