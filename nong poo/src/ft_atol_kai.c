/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_kai.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:05:38 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 22:21:44 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief This atol has special prupose for parsing integer
 * but will return in long type so but inside the function
 * will check for the integer overflow and return it immediatly
 */
long	ft_atol_kai(char const *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		if (res * sign < (long long)INT32_MIN \
			|| res * sign > (long long)INT32_MAX)
			return (res * sign);
		res += str[i++] - '0';
	}
	if (str[i] != '\0')
		return ((long)(INT32_MAX) + 1);
	return (res * sign);
}
