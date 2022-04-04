/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:06:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/04 22:00:09 by sel-kham         ###   ########.fr       */
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

void	ft_add_node_at_first(t_node *new_node, t_node **head)
{
	static t_node	*tail;

	
	if (!(*head))
	{
		*head = new_node;
		tail = new_node;
	}
	else
	{
		(*head)->previous_node = new_node;
		new_node->next_node = *head;
		*head = new_node;
		(*head)->previous_node = tail;
	}
}
