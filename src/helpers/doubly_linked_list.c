/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:06:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/31 21:52:45 by sel-kham         ###   ########.fr       */
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

void	ft_add_node_at_first(int data, t_node **head)
{
	t_node	*new_node;

	new_node = ft_new_node(data);
	if (!new_node)
		return ;
	(*head)->next_node->previous_node = new_node;
	new_node->next_node = (*head);
	(*head) = new_node;
}
