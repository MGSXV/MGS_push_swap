/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:45:07 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 00:32:29 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static int    ft_cmpres(char *s1, char *s2)
{
    int    i;

    i = 0;
    if (!s1 || !s2)
        return (-1);
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    if (s1[i] == s2[i])
        return (0);
    else
        return (s1[i] - s2[i]);
}

void	ft_init_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->max = NULL;
	(*stack)->min = NULL;
	(*stack)->size = 0;
	(*stack)->is_sorted = 0;
}

void	exec_instructions(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (ft_cmpres("pa\n", instruction) == 0)
		push_stack(stack_b, stack_a, 0);
	else if (ft_cmpres("pb\n", instruction) == 0)
		push_stack(stack_a, stack_b, 0);
	else if (ft_cmpres("sa\n", instruction) == 0)
		swap_stack(stack_a, 0);
	else if (ft_cmpres("sb\n", instruction) == 0)
		swap_stack(stack_b, 0);
	else if (ft_cmpres("ss\n", instruction) == 0)
		sswap_stack(stack_b, stack_b);
	else if (ft_cmpres("ra\n", instruction) == 0)
		rotate_stack(stack_a, 0);
	else if (ft_cmpres("rb\n", instruction) == 0)
		rotate_stack(stack_b, 0);
	else if (ft_cmpres("rr\n", instruction) == 0)
		rrotate_stack(stack_a, stack_b);
	else if (ft_cmpres("rra\n", instruction) == 0)
		reverse_rotate_stack(stack_a, 0);
	else if (ft_cmpres("rrb\n", instruction) == 0)
		reverse_rotate_stack(stack_b, 0);
	else if (ft_cmpres("rrr\n", instruction) == 0)
		rreverse_rotate_stack(stack_a, stack_b);
	else
	{
		ft_free_all(stack_b);
		ft_error("\033[0;31mError\n", stack_a);
	}
}

void	read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_instructions(stack_a, stack_b, line);
		line = get_next_line(0);
	}
	if (ft_is_increasing(stack_a) || (*stack_b)->head)
		ft_printf("\033[0;32mOK\n");
	else
		ft_printf("\033[0;31mKO\n");
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	ft_init_stack(&stack_a);
	ft_parssing_args(c, v, &stack_a);
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	ft_init_stack(&stack_b);
	read_instructions(&stack_a, &stack_b);
	ft_free_all(&stack_b);
	ft_free_all(&stack_a);
	return (0);
}
