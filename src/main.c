/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/10 21:43:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void	ft_init_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->size = 0;
	(*stack)->is_sorted = 0;
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		i;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	ft_init_stack(&stack_b);
	ft_init_stack(&stack_a);
	ft_parssing_args(c, v, &stack_a);
	// i = 0;
	// tmp_a = stack_a->head;
	// while (tmp_a)
	// {
	// 	ft_printf("Node %d: %d | Addr: %p\n", ++i, tmp_a->data, tmp_a);
	// 	tmp_a = tmp_a->next_node;
	// }
	// ft_printf("---------------------------------------------------------------\n");
	// swap_stack(&stack_a, 'a');
	// tmp_a = stack_a->head;
	// i = 0;
	// while (tmp_a)
	// {
	// 	ft_printf("{STACK A}: Node %d: %d | Addr: %p\n", ++i, tmp_a->data, tmp_a);
	// 	tmp_a = tmp_a->next_node;
	// }
	// ft_printf("---------------------------------------------------------------\n");
	ft_printf("{STACK A SIZE}: %d\n", stack_a->size);
	push_stack(&stack_a, &stack_b, 'a');
	push_stack(&stack_a, &stack_b, 'a');
	push_stack(&stack_a, &stack_b, 'a');
	tmp_a = stack_a->head;
	i = 0;
	while (tmp_a)
	{
		ft_printf("{STACK A}: Node %d: %d | Addr: %p\n", ++i, tmp_a->data, tmp_a);
		tmp_a = tmp_a->next_node;
	}
	ft_printf("{STACK A SIZE}: %d\n", stack_a->size);
	i = 0;
	tmp_b = stack_b->head;
	ft_printf("{STACK B SIZE}: %d\n", stack_b->size);
	while (tmp_b)
	{
		ft_printf("{STACK B}: Node %d: %d | Addr: %p\n", ++i, tmp_b->data, tmp_b);
		tmp_b = tmp_b->next_node;
	}
	ft_printf("{STACK B SIZE}: %d\n", stack_b->size);
	// ft_printf("---------------------------------------------------------------\n");
	// rotate_stack(&stack_a, 'a');
	// tmp_a = stack_a->head;
	// i = 0;
	// while (tmp_a)
	// {
	// 	ft_printf("{STACK A}: Node %d: %d | Addr: %p\n", ++i, tmp_a->data, tmp_a);
	// 	tmp_a = tmp_a->next_node;
	// }
	// ft_printf("---------------------------------------------------------------\n");
	// reverse_rotate_stack(&stack_a, 'a');
	// tmp_a = stack_a->head;
	// i = 0;
	// while (tmp_a)
	// {
	// 	ft_printf("{STACK A}: Node %d: %d | Addr: %p\n", ++i, tmp_a->data, tmp_a);
	// 	tmp_a = tmp_a->next_node;
	// }
	ft_free_all(&stack_a);
	return (0);
}
