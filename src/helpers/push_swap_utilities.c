/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:39:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/11 23:14:41 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_node	*tmp;

	tmp = (*stack)->head;
	while (tmp)
	{
		if (tmp->data > tmp->next_node->data)
			return (0);
		tmp = tmp->next_node;
	}
	return (1);
}

void	ft_get_max_and_min(t_stack **stack, int num)
{
	if ((*stack)->size == 0)
	{
		(*stack)->max = num;
		(*stack)->min = num;
		return ;
	}
	if (num > (*stack)->max)
		(*stack)->max = num;
	if (num < (*stack)->min)
		(*stack)->min = num;
	return ;
}
