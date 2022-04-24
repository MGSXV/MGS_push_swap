/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:43:14 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 02:40:55 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

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

void	ft_insertion_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i ;
		while (++j <= size - 1)
		{
			if ((tab)[i] > (tab)[j])
				ft_swap(tab + i, tab + j);
		}
	}
}
