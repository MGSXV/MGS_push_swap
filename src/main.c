/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/13 02:38:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

static void	ft_init_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->size = 0;
	(*stack)->is_sorted = 0;
}

void	ft_print_stack(t_stack **stack)
{
	t_node	*tmp;

	tmp = (*stack)->head;
	while (tmp)
	{
		ft_printf("%d, ", tmp->data, tmp->index);
		tmp = tmp->next_node;
	}
	ft_printf("\n");
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	if (ft_is_increasing(&stack_a))
		ft_error("", &stack_a);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	ft_init_stack(&stack_b);
	ft_init_stack(&stack_a);
	ft_parssing_args(c, v, &stack_a);
	ft_indexing(&stack_a);
	push_swap(&stack_a, &stack_b);
	ft_free_all(&stack_a);
	return (0);
}
