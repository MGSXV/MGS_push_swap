/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/24 04:32:53 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void	ft_init_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->max = NULL;
	(*stack)->min = NULL;
	(*stack)->size = 0;
	(*stack)->is_sorted = 0;
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	ft_init_stack(&stack_a);
	ft_parssing_args(c, v, &stack_a);
	if (ft_is_increasing(&stack_a))
		ft_error("", &stack_a);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	ft_init_stack(&stack_b);
	push_swap(&stack_a, &stack_b);
	ft_free_all(&stack_b);
	ft_free_all(&stack_a);
	return (0);
}
