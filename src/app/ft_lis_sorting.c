/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:31:19 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 02:42:11 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*tmp;

	get_lis_from_stack(stack_a);
	tmp = (*stack_a)->head;
	while (tmp)
	{
		if (tmp->is_in_lis)
			tmp = tmp->next_node;
		else
		{
			while (tmp->index)
			{
				if (tmp->index <= (*stack_a)->size / 2)
					rotate_stack(stack_a, 'a');
				else
					reverse_rotate_stack(stack_a, 'a');
				ft_index_stack(stack_a);
			}
			push_stack(stack_a, stack_b, 'b');
			tmp = (*stack_a)->head;
			ft_index_stack(stack_a);
		}
	}
}

int	calculate_move_a(t_node *node, t_stack *stack_a)
{
	int		i;
	t_node	*tmp1;
	t_node	*tmp2;

	i = 0;
	tmp1 = stack_a->head;
	tmp2 = NULL;
	while (tmp1)
	{
		if (!tmp2 && tmp1->sorted_index < node->sorted_index)
			tmp2 = tmp1;
		if (tmp1->sorted_index < node->sorted_index && \
			tmp1->sorted_index > tmp2->sorted_index)
			tmp2 = tmp1;
		tmp1 = tmp1->next_node;
	}
	i = (tmp2->index + 1) % stack_a->size;
	if (i <= stack_a->size / 2)
		return (i);
	return (-(stack_a->size - i));
}

t_node	*get_lowest_moves_node(t_stack *stack_b)
{
	t_node	*out_node;
	t_node	*tmp;

	out_node = stack_b->head;
	tmp = stack_b->head;
	while (tmp)
	{
		if (ft_abs(tmp->move_a) + ft_abs(tmp->move_b) < \
			ft_abs(out_node->move_a) + ft_abs(out_node->move_b))
			out_node = tmp;
		tmp = tmp->next_node;
	}
	return (out_node);
}

void	ft_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*tmp;
	int		i;

	i = -1;
	tmp = (*stack_b)->head;
	while (tmp && ++i < (*stack_b)->size)
	{
		if (i <= (*stack_b)->size / 2)
			tmp->move_b = i;
		else
			tmp->move_b = -((*stack_b)->size - i);
		tmp->move_a = calculate_move_a(tmp, (*stack_a));
		tmp = tmp->next_node;
	}
	tmp = get_lowest_moves_node(*stack_b);
	execte_moves(tmp, stack_a, stack_b);
	ft_index_stack(stack_a);
	ft_index_stack(stack_b);
}

void	put_lowest_to_top(t_stack **stack_a)
{
	t_node	*node;

	node = (*stack_a)->min;
	if (node->index <= (*stack_a)->size / 2)
		while ((*stack_a)->head != node)
			rotate_stack(stack_a, 'a');
	else if (node->index > (*stack_a)->size / 2)
		while ((*stack_a)->head != node)
			reverse_rotate_stack(stack_a, 'a');
}
