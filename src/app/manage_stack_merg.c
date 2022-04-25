/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack_merg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:43:50 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 01:07:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	sswap_stack(t_stack **stack_a, t_stack **stack_b, char c)
{
	swap_stack(stack_a, '\0');
	swap_stack(stack_b, '\0');
	if (c == 'r')
		ft_printf("ss\n");
}

void	rrotate_stack(t_stack **stack_1, t_stack **stack_2, char c)
{
	rotate_stack(stack_1, '\0');
	rotate_stack(stack_2, '\0');
	if (c == 'r')
		ft_printf("rr\n");
}

void	rreverse_rotate_stack(t_stack **stack_1, t_stack **stack_2, char c)
{
	reverse_rotate_stack(stack_1, '\0');
	reverse_rotate_stack(stack_2, '\0');
	if (c == 'r')
		ft_printf("rrr\n");
}
