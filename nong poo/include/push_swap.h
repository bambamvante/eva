/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:22:38 by kawaii            #+#    #+#             */
/*   Updated: 2024/12/05 22:07:54 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./Libft_pratical_use/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef enum e_error
{
	A_OK,
	STR_ERR,
	INT_ERR,
	MEM_ERR
}	t_error;

typedef enum e_action
{
	NONE_ACT,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_action;

typedef enum e_label
{
	A,
	B
}	t_label;

typedef struct s_event
{
	t_action		act;
	struct s_event	*next;
}	t_event;

typedef struct s_prop
{
	size_t			size;
	unsigned int	*stack_a;
	unsigned int	*stack_b;
	int				n_a;
	int				n_b;
	int				err_stat;
	t_event			*start;
	t_event			*tail;
}	t_prop;

void	ft_swap(unsigned int *n, unsigned int *m);

void	act_swap(t_prop *prop, t_label opt);
void	act_push(t_prop *prop, t_label opt);
void	act_rotate(t_prop *prop, t_label opt);
void	act_rvrotate(t_prop *prop, t_label opt);

long	ft_atol_kai(char const *str);
int		in_range(int *set, int n, int limit);

int		is_sorted(unsigned int *arr, size_t size, bool reverse);
void	sort_three(t_prop *prop);
void	sort_four(t_prop *prop);
void	sort_five(t_prop *prop);
void	radix_ori(t_prop *prop);

void	parser(char **argv, t_prop *prop);

#endif
