/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:00:48 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 19:57:28 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	base_factor(size_t size)
{
	int	bit_size;

	bit_size = 0;
	while (size > 1 && ++bit_size)
		size /= 2;
	return (bit_size);
}

void	radix_ori_b(t_prop *prop, size_t n_b, int i, int fac)
{
	int	j;

	j = n_b;
	while (j-- && i <= fac && !is_sorted(prop->stack_a, prop->n_a, true))
	{
		if (((prop->stack_b[prop->n_b - 1] >> i) & 1) == 0)
			act_rotate(prop, B);
		else
			act_push(prop, A);
	}
	if (is_sorted(prop->stack_a, prop->n_a, true))
		while (prop->n_b)
			act_push(prop, A);
}

void	radix_ori(t_prop *prop)
{
	int	i;
	int	j;
	int	fac;

	fac = base_factor(prop->n_a);
	i = 0;
	while (i <= fac)
	{
		j = prop->n_a;
		while (j-- && !is_sorted(prop->stack_a, prop->n_a, true))
		{
			if (((prop->stack_a[prop->n_a - 1] >> i) & 1) == 0)
				act_push(prop, B);
			else
				act_rotate(prop, A);
		}
		i++;
		radix_ori_b(prop, prop->n_b, i, fac);
	}
	while (prop->n_b)
		act_push(prop, A);
}
