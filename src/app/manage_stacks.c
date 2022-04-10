/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:21:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/10 01:25:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	swap_stack(t_stack **stack, char s)
{
	t_node	*tmp;

	if (!(*stack)->head || !(*stack)->head->next_node)
		return ;
	tmp = (*stack)->head;
	(*stack)->head = (*stack)->head->next_node;
	tmp->next_node = (*stack)->head->next_node;
	(*stack)->head->previous_node = (*stack)->tail;
	(*stack)->head->next_node = tmp;
	tmp->previous_node = (*stack)->head;
	if (tmp->next_node)
		tmp->next_node->previous_node = tmp;
	if (s)
		ft_printf("s%c\n", s);
}

void	sswap_stack(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a, '\0');
	swap_stack(stack_b, '\0');
	ft_printf("ss\n");
}
// Takes the first element at the top of the src_stack and push it to the top of dst_stack
void	push_stack(t_stack **src_stack, t_stack **dst_stack, char s)
{
	t_node	*tmp;

	if (src_stack && *src_stack)
	{
		if ((*src_stack)->head)
		{
			tmp = (*src_stack)->head->next_node;
			ft_add_node_at_first(dst_stack, (*src_stack)->head);
			(*src_stack)->head = tmp;
			(*src_stack)->head->previous_node = (*src_stack)->tail;
			ft_printf("p%c\n", s);
		}
	}
}

void	rotate_stack(t_stack **stack, char s)
{
	if (s)
		ft_printf("r%c\n", s);
}

void	rrotate_stack(t_stack **stack_1, t_stack **stack_2)
{
	rotate_stack(stack_1, '\0');
	rotate_stack(stack_2, '\0');
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_stack **stack, char s)
{
	if (s)
		ft_printf("r%c\n", s);
}

void	rreverse_rotate_stack(t_stack **stack_1, t_stack **stack_2)
{
	reverse_rotate_stack(stack_1, '\0');
	reverse_rotate_stack(stack_2, '\0');
	ft_printf("rrr\n");
}
