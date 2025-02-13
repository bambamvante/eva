/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:52:47 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 22:25:17 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_prop(t_prop *prop)
{
	prop->err_stat = A_OK;
	prop->size = 0;
	prop->stack_a = NULL;
	prop->stack_b = NULL;
	prop->n_a = 0;
	prop->n_b = 0;
	prop->start = NULL;
	prop->tail = NULL;
}

static void	print_act(t_action act)
{
	if (act == sa)
		ft_putendl_fd("sa", 1);
	else if (act == sb)
		ft_putendl_fd("sb", 1);
	else if (act == ss)
		ft_putendl_fd("ss", 1);
	else if (act == pa)
		ft_putendl_fd("pa", 1);
	else if (act == pb)
		ft_putendl_fd("pb", 1);
	else if (act == ra)
		ft_putendl_fd("ra", 1);
	else if (act == rb)
		ft_putendl_fd("rb", 1);
	else if (act == rr)
		ft_putendl_fd("rr", 1);
	else if (act == rra)
		ft_putendl_fd("rra", 1);
	else if (act == rrb)
		ft_putendl_fd("rrb", 1);
	else if (act == rrr)
		ft_putendl_fd("rrr", 1);
	else
		ft_putendl_fd("ERROR", 1);
}

static void	release(t_event *act_lst)
{
	void	*tmp;

	while (act_lst != NULL)
	{
		tmp = act_lst;
		print_act(act_lst->act);
		act_lst = act_lst->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_prop	prop;

	if (argc < 2)
		return (1);
	init_prop(&prop);
	parser(argv, &prop);
	if (prop.err_stat == A_OK && !is_sorted(prop.stack_a, prop.n_a, true))
	{
		if (prop.size == 2 && prop.stack_a[0] < prop.stack_a[1])
			act_swap(&prop, A);
		else if (prop.size == 3)
			sort_three(&prop);
		else if (prop.size == 4)
			sort_four(&prop);
		else if (prop.size == 5)
			sort_five(&prop);
		else if (prop.size > 3)
			radix_ori(&prop);
		release(prop.start);
	}
	else if (prop.err_stat != A_OK)
		ft_putendl_fd("Error", 2);
	free(prop.stack_a);
	free(prop.stack_b);
}
