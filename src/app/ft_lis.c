/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:57:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/18 05:09:06 by sel-kham         ###   ########.fr       */
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
		tmp = tmp->next_node;
	}
}

void	ft_lis(t_stack **stack)
{
	int		*lis;
	int		*nums;
	int		i;
	int		j;
	t_node	*tmp;

	lis = malloc(sizeof(int) * (*stack)->size);
	nums = malloc(sizeof(int) * (*stack)->size);
	i = -1;
	tmp = (*stack)->head;
	while (++i < (*stack)->size && tmp)
	{
		nums[i] = tmp->data;
		lis[i] = 1;
		tmp = tmp->next_node;
	}
	fill_stack(stack);
	i = (*stack)->size - 1;
	while (i--)
	{
		j = i;
		while (++j < (*stack)->size)
			if (nums[i] < nums[j])
				lis[i] = ft_get_max_num(lis[i], lis[j] + 1);
	}
}
