/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:31:19 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/22 02:17:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_index_stack(t_stack **stack)
{
	int		i;
	t_node	*tmp;

	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next_node;
	}
}

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
			if (tmp->index)
			{
				while (tmp->index)
				{
					if (tmp->index <= (*stack_a)->size)
						rotate_stack(stack_a, 'a');
					else
						reverse_rotate_stack(stack_a, 'a');
					ft_index_stack(stack_a);
				}
			}
			push_stack(stack_a, stack_b, 'b');
			tmp = (*stack_a)->head;
			ft_index_stack(stack_a);
		}
	}
	ft_index_stack(stack_a);
	ft_index_stack(stack_b);
}
