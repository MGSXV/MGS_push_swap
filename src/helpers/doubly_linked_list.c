/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:06:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/05 23:04:07 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

t_node	*ft_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next_node = NULL;
	new_node->previous_node = NULL;
	return (new_node);
}

void	ft_add_node_at_first(t_stack **stack, t_node *new_node)
{
	if (!((*stack)->head))
	{
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
	}
	else
	{
		(*stack)->head->previous_node = new_node;
		new_node->next_node =(*stack)->head ;
		(*stack)->head = new_node;
		(*stack)->head->previous_node = (*stack)->tail;
	}
}
