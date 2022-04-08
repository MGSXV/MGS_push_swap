/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:21:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/07 23:38:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	swap_stack(t_stack **stack, char s)
{
	if (s)
		ft_printf("s%c\n", s);
}

void	sswap_stack(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a, '\0');
	swap_stack(stack_b, '\0');
	ft_printf("ss\n");
}

void	push_stack(t_stack **stack_1, t_stack **stack_2, char s)
{
	ft_printf("p%c\n", s);
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
