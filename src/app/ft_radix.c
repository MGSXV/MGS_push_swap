/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:27:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/12 05:13:22 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void    ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_num;
	int	num;
	int	i;
	int	j;

	max_num = (*stack_a)->max;
	i = -1;
	while (++i < 32)
	{
		j = -1;
		while (++j < (*stack_a)->size)
		{
			num = (*stack_a)->head->data;
			if (i != 31)
			{
				if ((num >> i) & 1)
					rotate_stack(stack_a, 'a');
				else
					push_stack(stack_a, stack_b, 'b');
			}
			else
			{
				if (!((num >> i) & 1))
					rotate_stack(stack_a, 'a');
				else
					push_stack(stack_a, stack_b, 'b');
			}
		}
		while ((*stack_b)->head)
			push_stack(stack_b, stack_a, 'a');
	}
}