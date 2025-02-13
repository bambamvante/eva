/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 03:37:44 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/03 20:40:52 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	add_action(t_prop *prop, t_action act)
{
	if (!prop->start)
	{
		prop->start = malloc(sizeof(t_event));
		if (!prop->start)
		{
			prop->err_stat = MEM_ERR;
			return ;
		}
		prop->start->act = act;
		prop->start->next = NULL;
		prop->tail = prop->start;
	}
	else
	{
		prop->tail->next = malloc(sizeof(t_event));
		if (!prop->tail->next)
		{
			prop->err_stat = MEM_ERR;
			return ;
		}
		prop->tail = prop->tail->next;
		prop->tail->act = act;
		prop->tail->next = NULL;
	}
}

void	act_swap(t_prop *prop, t_label opt)
{
	if (opt == A && prop->n_a > 1)
	{
		ft_swap(&prop->stack_a[prop->n_a - 2], &prop->stack_a[prop->n_a - 1]);
		add_action(prop, sa);
	}
	else if (opt == B && prop->n_b > 1)
	{
		ft_swap(&prop->stack_b[prop->n_b - 2], &prop->stack_b[prop->n_b - 1]);
		add_action(prop, sb);
	}
}

void	act_rotate(t_prop *prop, t_label opt)
{
	unsigned int	tmp;

	if (opt == A && prop->n_a > 1)
	{
		tmp = prop->stack_a[prop->n_a - 1];
		ft_memmove(prop->stack_a + 1, prop->stack_a, \
					(prop->n_a - 1) * sizeof(unsigned int));
		prop->stack_a[0] = tmp;
		add_action(prop, ra);
	}
	if (opt == B && prop->n_b > 1)
	{
		tmp = prop->stack_b[prop->n_b - 1];
		ft_memmove(prop->stack_b + 1, prop->stack_b, \
					(prop->n_b - 1) * sizeof(unsigned int));
		prop->stack_b[0] = tmp;
		add_action(prop, rb);
	}
}

void	act_rvrotate(t_prop *prop, t_label opt)
{
	unsigned int	tmp;

	if (opt == A && prop->n_a > 1)
	{
		tmp = prop->stack_a[0];
		ft_memmove(prop->stack_a, prop->stack_a + 1, \
					(prop->n_a - 1) * sizeof(unsigned int));
		prop->stack_a[prop->n_a - 1] = tmp;
		add_action(prop, rra);
	}
	if (opt == B && prop->n_b > 1)
	{
		tmp = prop->stack_b[0];
		ft_memmove(prop->stack_b, prop->stack_b + 1, \
					(prop->n_b - 1) * sizeof(unsigned int));
		prop->stack_b[prop->n_b - 1] = tmp;
		add_action(prop, rrb);
	}
}

void	act_push(t_prop *prop, t_label opt)
{
	unsigned int	n;

	if (opt == A && prop->n_b)
	{
		prop->n_b--;
		n = prop->stack_b[prop->n_b];
		prop->stack_b[prop->n_b] = 0;
		prop->stack_a[prop->n_a] = n;
		prop->n_a++;
		add_action(prop, pa);
	}
	else if (opt == B && prop->n_a)
	{
		prop->n_a--;
		n = prop->stack_a[prop->n_a];
		prop->stack_a[prop->n_a] = 0;
		prop->stack_b[prop->n_b] = n;
		prop->n_b++;
		add_action(prop, pb);
	}
}
