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

t_node	*t_new_node(int data, t_node *node)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next_node = NULL;
	new_node->previous_node = node;
	return (new_node);
}

t_node