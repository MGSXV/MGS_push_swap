/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:27:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/13 00:49:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	num;
	int	i;
	int	j;
	int	size;

	i = -1;
	size = (*stack_a)->size;
	while (++i < 7)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->head->index;
			if (((num >> i) & 1))
				rotate_stack(stack_a, 'a');
			else if (!((num >> i) & 1) && !ft_is_sorted(stack_a))
				push_stack(stack_a, stack_b, 'b');
		}
		while ((*stack_b)->head)
			push_stack(stack_b, stack_a, 'a');
	}
}
