/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:21:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/10 02:44:32 by sel-kham         ###   ########.fr       */
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

/*
 *	Takes the top of the src_stack and push it to the top of dst_stack
 */

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
	t_node	*tmp;

	if (stack && *stack)
	{
		if ((*stack)->head)
		{
			tmp = (*stack)->head;
			(*stack)->head = (*stack)->head->next_node;
			tmp->next_node = NULL;
			(*stack)->tail->next_node = tmp;
			(*stack)->tail = tmp;
			if (s)
				ft_printf("r%c\n", s);
		}
	}
}

void	reverse_rotate_stack(t_stack **stack, char s)
{
	t_node	*tmp;

	if (stack && *stack)
	{
		if ((*stack)->head)
		{
			tmp = (*stack)->tail;
			(*stack)->tail = tmp->previous_node;
			(*stack)->tail->next_node = NULL;
			tmp->next_node = (*stack)->head;
			(*stack)->head = tmp;
			if (s)
				ft_printf("r%c\n", s);
		}
	}
}
