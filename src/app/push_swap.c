/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:14:37 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/23 02:42:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_sort_base_case(t_stack **stack_a)
{
	if ((*stack_a)->head->data > (*stack_a)->tail->data)
	{
		rotate_stack(stack_a, 'a');
		ft_sort_base_case(stack_a);
	}
	if (((*stack_a)->head->next_node->data > (*stack_a)->head->data)
		&& ((*stack_a)->head->next_node->data > (*stack_a)->tail->data))
	{
		reverse_rotate_stack(stack_a, 'a');
		ft_sort_base_case(stack_a);
	}
	if ((*stack_a)->head->data > (*stack_a)->head->next_node->data)
	{
		swap_stack(stack_a, 'a');
		ft_sort_base_case(stack_a);
	}
}

// void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_push_to_stack_b(stack_a, stack_b);
// }

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 4)
		ft_sort_base_case(stack_a);
	else
	{
		ft_sorted_indexing(stack_a);
		ft_push_to_stack_b(stack_a, stack_b);
		while ((*stack_b)->size)
			ft_best_move(stack_a, stack_b);
		put_lowest_to_top(stack_a);
	}
}
