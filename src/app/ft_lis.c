/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:57:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/15 23:48:28 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_get_max_num(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static	void	print_results(t_stack *stack)
{
	t_node	*tmp;
	
	tmp = stack->head;
	ft_printf("index : ");
	while (tmp)
	{
		ft_printf("%d | ", tmp->index);
		tmp = tmp->next_node;
	}
	tmp = stack->head;
	ft_printf("\n");
	ft_printf("Length : ");
	while (tmp)
	{
		ft_printf("%d | ", tmp->len);
		tmp = tmp->next_node;
	}
	tmp = stack->head;
	ft_printf("\n");
	ft_printf("Sub seq : ");
	while (tmp)
	{
		ft_printf("%d | ", tmp->sub_seq);
		tmp = tmp->next_node;
	}
	ft_printf("\n");
}

static void	fill_stack(t_stack **stack)
{

	int		i;

	t_node	*tmp;

	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tmp->len = 1;
		tmp->index = i++;
		tmp->sub_seq = -1;
		tmp = tmp->next_node;
	}
}

void	ft_lis(t_stack **stack)
{
	int 	nmber_befor ;
    int 	index_befor;
	t_node	*current;
	t_node	*next;
	
	fill_stack(stack);
	next = (*stack)->head->next_node;
	while (next)
	{
		current = (*stack)->head;
		while (current && current != next)
		{
			if (current->data < next->data)
			{
				if (current->len + 1 > next->len)
				{
					next->len = current->len + 1;
					next->sub_seq = current->index;
					nmber_befor = current->data;
    				index_befor = current->index;
				}
				else if (current->len + 1 == next->len)
				{
					if (current->data < nmber_befor)
						next->sub_seq = current->index;
					else
						next->sub_seq = index_befor;
				}
				
			}
			current = current->next_node;
		}
		next = next->next_node;
	}
	print_results(*stack);
}