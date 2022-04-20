/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:57:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/20 01:57:21 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_get_max_num(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static void	fill_stack(t_stack **stack)
{
	int		i;
	t_node	*tmp;

	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp->is_in_lis = false;
		tmp = tmp->next_node;
	}
}

int	*ft_lis(t_stack **stack)
{
	int		*lis;
	int		*nums;
	int		i;
	int		j;
	t_node	*tmp;

	lis = malloc(sizeof(int) * (*stack)->size);
	nums = malloc(sizeof(int) * (*stack)->size);
	i = -1;
	tmp = (*stack)->head;
	while (++i < (*stack)->size && tmp)
	{
		nums[i] = tmp->data;
		lis[i] = 1;
		tmp = tmp->next_node;
	}
	fill_stack(stack);
	i = (*stack)->size - 1;
	while (i--)
	{
		j = i;
		while (++j < (*stack)->size)
			if (nums[i] < nums[j])
				lis[i] = ft_get_max_num(lis[i], lis[j] + 1);
	}
	return (lis);
}

void	ft_birng_min_to_top(t_stack **stack)
{
	int		size;

	size = (*stack)->size;
	while (!((*stack)->min->data == (*stack)->head->data))
	{
		if ((*stack)->min->index >= (*stack)->size / 2)
			rotate_stack(stack, 'a');
		else
			reverse_rotate_stack(stack, 'a');\
	}
}

void	get_lis_from_stack(t_stack **stack)
{
	t_node	*tmp;
	t_node	*last_node;
	int		*lis;
	int		i;
	int		j;
	int		size;
	int		last_lis;

	size = (*stack)->size;
	ft_birng_min_to_top(stack);
	lis = ft_lis(stack);
	tmp = (*stack)->head;
	i = -1;
	while (tmp && ++i < size)
	{
		if (!i)
		{
			tmp->is_in_lis = true;
			last_node = tmp;
			last_lis = lis[i];
		}
		else
		{
			j = i;
			while (++j <= size)
			{
				if (last_lis == lis[i] + 1 && tmp->data > last_node->data)
				{
					tmp->is_in_lis = true;
					last_node = tmp;
					last_lis = lis[i];
					break ;
				}
			}
		}
		tmp = tmp->next_node;
	}
	tmp = (*stack)->head;
	while (tmp)
	{
		printf("%2d, ", tmp->data);
		tmp = tmp->next_node;
	}
	printf("\n");
	tmp = (*stack)->head;
	while (tmp)
	{
		printf("%2d, ", tmp->is_in_lis);
		tmp = tmp->next_node;
	}
	printf("\n");
	i = -1;
	while (++i < (*stack)->size)
		printf("%2d, ", lis[i]);
	printf("\n");
}
