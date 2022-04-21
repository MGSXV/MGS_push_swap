/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:57:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/21 02:24:43 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_get_max_num(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static void	fill_stack(t_stack **stack)
{
	int		i;
	t_node	*tmp;

	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp->lis = 1;
		tmp->is_in_lis = false;
		tmp = tmp->next_node;
	}
}

void	ft_lis(t_stack **stack)
{
	int		i;
	t_node	*current;
	t_node	*previous;

	fill_stack(stack);
	current = (*stack)->tail;
	i = -1;
	while (++i < (*stack)->size)
	{
		previous = current;
		while (previous->next_node)
		{
			previous = previous->next_node;
			if (current->data < previous->data)
				current->lis = ft_get_max_num(current->lis, previous->lis + 1);
		}
		current = current->previous_node;
	}
}

void	ft_birng_min_to_top(t_stack **stack)
{
	int		size;

	size = (*stack)->size;
	while (!((*stack)->min->data == (*stack)->head->data))
	{
		if ((*stack)->min->index >= (*stack)->size / 2)
			rotate_stack(stack, 'a');
		else
			reverse_rotate_stack(stack, 'a');
	}
}

void	get_lis_from_stack(t_stack **stack)
{
	t_node	*tmp;
	int		searcher;

	ft_birng_min_to_top(stack);
	ft_lis(stack);
	tmp = (*stack)->head;
	tmp->is_in_lis = true;
	searcher = tmp->lis;
	while (tmp)
	{
		if (tmp->lis == searcher - 1)
		{
			tmp->is_in_lis = true;
			searcher--;
		}
		tmp = tmp->next_node;
	}
}
