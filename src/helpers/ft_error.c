/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:51:38 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 01:26:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_init_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->max = NULL;
	(*stack)->min = NULL;
	(*stack)->size = 0;
	(*stack)->is_sorted = 0;
}


void	ft_error(const char *err_msg, t_stack **stack)
{
	ft_free_all(stack);
	ft_printf("%s", err_msg);
	exit(EXIT_SUCCESS);
}

void	ft_free_all(t_stack **stack)
{
	t_node	*tmp;

	if (stack && *stack)
	{
		if ((*stack)->head)
		{
			tmp = (*stack)->head;
			while (tmp)
			{
				(*stack)->head = (*stack)->head->next_node;
				free(tmp);
				tmp = (*stack)->head;
			}
			(*stack)->head = NULL;
			free((*stack)->head);
		}
		free(*stack);
	}
}
