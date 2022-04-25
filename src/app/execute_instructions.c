/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:41:42 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 01:08:34 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static void	similar_moves(t_node *node, t_stack **stack_a, t_stack **stack_b)
{
	while (node->move_a && node->move_b && node->move_a > 0 && node->move_b > 0)
	{
		rrotate_stack(stack_a, stack_b, 'r');
		node->move_a--;
		node->move_b--;
	}
	while (node->move_a && node->move_b && node->move_a < 0 && node->move_b < 0)
	{
		rreverse_rotate_stack(stack_a, stack_b, 'r');
		node->move_a++;
		node->move_b++;
	}
}

static void	other_moves(t_node *node, t_stack **stack_b)
{
	while (node->move_b)
	{
		if (node->move_b > 0)
		{
			rotate_stack(stack_b, 'b');
			node->move_b--;
		}
		else if (node->move_b < 0)
		{
			reverse_rotate_stack(stack_b, 'b');
			node->move_b++;
		}
	}
}

void	execte_moves(t_node *node, t_stack **stack_a, t_stack **stack_b)
{
	similar_moves(node, stack_a, stack_b);
	other_moves(node, stack_b);
	while (node->move_a)
	{
		if (node->move_a > 0)
		{
			rotate_stack(stack_a, 'a');
			node->move_a--;
		}
		else if (node->move_a < 0)
		{
			reverse_rotate_stack(stack_a, 'a');
			node->move_a++;
		}
	}
	push_stack(stack_b, stack_a, 'a');
}
