/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:49:01 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 22:11:20 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_prop *prop)
{
	int				t_a;
	unsigned int	*stack;

	t_a = prop->n_a - 1;
	stack = prop->stack_a;
	if (stack[t_a - 1] > stack[t_a] && stack[t_a - 1] > stack[t_a - 2] && \
		stack[t_a] < stack[t_a - 2])
		act_swap(prop, A);
	else if (stack[t_a] > stack[t_a - 1] && stack[t_a] > stack[t_a - 2] && \
		stack[t_a - 1] > stack[t_a - 2])
		act_rotate(prop, A);
	if (stack[t_a] > stack[t_a - 1] && stack[t_a - 1] < stack[t_a - 2] && \
		stack[t_a] < stack[t_a - 2])
		act_swap(prop, A);
	else if (stack[t_a] < stack[t_a - 1] && stack[t_a - 1] > stack[t_a - 2] && \
		stack[t_a] > stack[t_a - 2])
		act_rvrotate(prop, A);
	else if (stack[t_a] > stack[t_a - 1] && stack[t_a] > stack[t_a - 2] && \
		stack[t_a - 1] < stack[t_a - 2])
		act_rotate(prop, A);
}

void	sort_four(t_prop *prop)
{
	while (prop->n_a > 2)
	{
		if (!prop->stack_a[prop->n_a - 1] || prop->stack_a[prop->n_a - 1] == 1)
			act_push(prop, B);
		else if (!prop->stack_a[prop->n_a - 2] || \
			prop->stack_a[prop->n_a - 2] == 1)
			act_swap(prop, A);
		else if (!prop->stack_a[0] || prop->stack_a[0] == 1)
			act_rvrotate(prop, A);
		else
			act_rotate(prop, A);
	}
	if (!is_sorted(prop->stack_a, prop->n_a, true))
		act_swap(prop, A);
	if (!is_sorted(prop->stack_b, prop->n_b, false))
		act_swap(prop, B);
	while (prop->n_b)
		act_push(prop, A);
}

void	sort_five(t_prop *prop)
{
	while (prop->n_a > 3)
	{
		if (!prop->stack_a[prop->n_a - 1] || prop->stack_a[prop->n_a - 1] == 1)
			act_push(prop, B);
		else if (!prop->stack_a[prop->n_a - 2] || \
			prop->stack_a[prop->n_a - 2] == 1)
			act_swap(prop, A);
		else if (!prop->stack_a[0] || prop->stack_a[0] == 1)
			act_rvrotate(prop, A);
		else
			act_rotate(prop, A);
	}
	sort_three(prop);
	if (!is_sorted(prop->stack_b, prop->n_b, false))
		act_swap(prop, B);
	while (prop->n_b)
		act_push(prop, A);
}
