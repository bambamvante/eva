/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:29:04 by arphueng          #+#    #+#             */
/*   Updated: 2024/12/29 18:57:21 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

// # include "./libft/libft.h"
// # include "./printf/ft_printf.h"
// # include "./get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}  	t_stack;

t_stack	*stack_new(int num);
void	stack_addback(t_stack **stack, t_stack *new);

#endif