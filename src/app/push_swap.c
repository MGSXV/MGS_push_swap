/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:14:37 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 02:37:06 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->head->data > (*stack_a)->tail->data)
	{
		rotate_stack(stack_a, 'a');
		ft_sort_three(stack_a);
	}
	if (((*stack_a)->head->next_node->data > (*stack_a)->head->data)
		&& ((*stack_a)->head->next_node->data > (*stack_a)->tail->data))
	{
		reverse_rotate_stack(stack_a, 'a');
		ft_sort_three(stack_a);
	}
	if ((*stack_a)->head->data > (*stack_a)->head->next_node->data)
	{
		swap_stack(stack_a, 'a');
		ft_sort_three(stack_a);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i++ < 2)
	{
		while ((*stack_a)->min != (*stack_a)->head)
		{
			if ((*stack_a)->min->index <= (*stack_a)->size / 2)
				rotate_stack(stack_a, 'a');
			else
				reverse_rotate_stack(stack_a, 'a');
		}
		push_stack(stack_a, stack_b, 'b');
		(*stack_a)->min = (*stack_a)->max;
		tmp = (*stack_a)->head;
		while (tmp)
		{
			ft_get_max_and_min(stack_a, tmp);
			tmp = tmp->next_node;
		}
	}
	ft_sort_three(stack_a);
	push_stack(stack_b, stack_a, 'a');
	push_stack(stack_b, stack_a, 'a');
}

void	ft_sort_base_case(t_stack **stack_a, t_stack **stack_b)
{
	ft_index_stack(stack_a);
	if ((*stack_a)->size > 3)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_three(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 6)
		ft_sort_base_case(stack_a, stack_b);
	else
	{
		ft_sorted_indexing(stack_a);
		ft_push_to_stack_b(stack_a, stack_b);
		while ((*stack_b)->size)
			ft_best_move(stack_a, stack_b);
		put_lowest_to_top(stack_a);
	}
}
