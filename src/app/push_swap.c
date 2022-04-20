/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:14:37 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/19 01:53:50 by sel-kham         ###   ########.fr       */
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

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = NULL;
	get_lis_from_stack(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 4)
		ft_sort_base_case(stack_a);
	else
		ft_sort_stack(stack_a, stack_b);
}
