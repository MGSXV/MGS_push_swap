/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:27:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/13 20:19:02 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_get_bits_num(t_stack *stack)
{
	int	bits;
	int	max;

	bits = 0;
	max = stack->size;
	while ((max >> bits))
		bits++;
	return (bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	num;
	int	bit_num;
	int	i;
	int	j;
	int	size;

	i = -1;
	bit_num = ft_get_bits_num(*stack_a);
	size = (*stack_a)->size;
	while (++i < bit_num)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->head->index;
			if (((num >> i) & 1))
				rotate_stack(stack_a, 'a');
			else if (!((num >> i) & 1) && !ft_is_increasing(stack_a))
				push_stack(stack_a, stack_b, 'b');
		}
		while ((*stack_b)->head)
			push_stack(stack_b, stack_a, 'a');	
	}
}
