/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:39:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/13 00:47:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_node	*tmp;

	if (stack && *stack)
	{
		tmp = (*stack)->head;
		while (tmp)
		{
			if (!tmp->next_node)
				break ;
			if (tmp->data > tmp->next_node->data)
				return (0);
			tmp = tmp->next_node;
		}
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

int	get_index(int *tab, int num, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] == num)
			return (i);
	return (-1);
}

void	ft_indexing(t_stack **stack)
{
	t_node	*tmp;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (*stack)->size);
	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next_node;
		i++;
	}
	ft_insertion_sort(tab, (*stack)->size);
	tmp = (*stack)->head;
	while (tmp)
	{
		tmp->index = get_index(tab, tmp->data, (*stack)->size) + 1;
		tmp = tmp->next_node;
		i++;
	}
	free(tab);
}
