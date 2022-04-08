/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/08 18:06:02 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_node	*tmp;
	int		i;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_a->head = NULL;
	ft_parssing_args(c, v, &stack_a);
	i = 0;
	tmp = stack_a->head;
	while (tmp)
	{
		ft_printf("Node %d: %d\n", ++i, tmp->data);
		tmp = tmp->next_node;
	}
	ft_free_all(&stack_a);
	return (0);
}
