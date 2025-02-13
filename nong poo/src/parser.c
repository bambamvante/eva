/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:58:32 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 22:14:32 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stack(t_prop *prop)
{
	prop->stack_a = ft_calloc(prop->size, sizeof(unsigned int));
	prop->stack_b = ft_calloc(prop->size, sizeof(unsigned int));
	if (!prop->stack_a || !prop->stack_b)
	{
		prop->err_stat = MEM_ERR;
		return (free(prop->stack_a), free(prop->stack_b));
	}
}

static int	parse_int(char **buf, t_prop *prop, int *stack, int i)
{
	long	num;

	num = 0;
	while (*buf != NULL)
	{
		num = ft_atol_kai(*buf);
		if (num < INT32_MIN || num > INT32_MAX || \
			in_range(stack, num, i))
		{
			prop->err_stat = INT_ERR;
			stack[i++] = 0;
		}
		else
			stack[i++] = (int)(num);
		buf++;
	}
	return (i);
}

static int	valid_str(char **argv, t_prop *prop)
{
	size_t	chng;
	int		i;

	while (*argv != NULL)
	{
		i = 0;
		chng = prop->size;
		while ((*argv)[i] != '\0' && (ft_isdigit((*argv)[i]) || \
				in((*argv)[i], " -+")))
		{
			while ((*argv)[i] != '\0' && in((*argv)[i], " -+"))
				i++;
			if (ft_isdigit((*argv)[i]))
				prop->size++;
			while (ft_isdigit((*argv)[i]))
				i++;
		}
		if ((*argv)[i] != '\0' || !prop->size || !i || !(prop->size - chng))
		{
			prop->err_stat = STR_ERR;
			return (0);
		}
		argv++;
	}
	return (1);
}

static void	indexer(t_prop *prop, int *raw_stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_stack(prop);
	while (i < prop->size)
	{
		j = 0;
		while (j < prop->size)
		{
			if (raw_stack[(prop->size - 1) - i] > raw_stack[j])
				prop->stack_a[i]++;
			j++;
		}
		i++;
	}
	prop->n_a = prop->size;
	free(raw_stack);
}

void	parser(char **argv, t_prop *prop)
{
	char	**buf;
	int		*raw_stack;
	int		i;

	i = 0;
	if (!valid_str(argv + 1, prop))
		return ;
	raw_stack = ft_calloc(prop->size, sizeof(int));
	if (!raw_stack)
	{
		prop->err_stat = MEM_ERR;
		return ;
	}
	while (*(argv + 1) != NULL)
	{
		buf = ft_split(*(argv + 1), ' ');
		i = parse_int(buf, prop, raw_stack, i);
		split_clear(buf);
		argv++;
	}
	indexer(prop, raw_stack);
}
