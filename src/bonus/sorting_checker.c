/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:45:07 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 01:26:20 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static int	ft_cmpres(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	ft_free_and_exit(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_all(stack_b);
	ft_error("\033[0;31mError\n", stack_a);
}

void	exec_instructions(t_stack **stack_a, t_stack **stack_b, char *ins)
{
	if (ft_cmpres("pa\n", ins) == 0)
		push_stack(stack_b, stack_a, 0);
	else if (ft_cmpres("pb\n", ins) == 0)
		push_stack(stack_a, stack_b, 0);
	else if (ft_cmpres("sa\n", ins) == 0)
		swap_stack(stack_a, 0);
	else if (ft_cmpres("sb\n", ins) == 0)
		swap_stack(stack_b, 0);
	else if (ft_cmpres("ss\n", ins) == 0)
		sswap_stack(stack_b, stack_b, 0);
	else if (ft_cmpres("ra\n", ins) == 0)
		rotate_stack(stack_a, 0);
	else if (ft_cmpres("rb\n", ins) == 0)
		rotate_stack(stack_b, 0);
	else if (ft_cmpres("rr\n", ins) == 0)
		rrotate_stack(stack_a, stack_b, 0);
	else if (ft_cmpres("rra\n", ins) == 0)
		reverse_rotate_stack(stack_a, 0);
	else if (ft_cmpres("rrb\n", ins) == 0)
		reverse_rotate_stack(stack_b, 0);
	else if (ft_cmpres("rrr\n", ins) == 0)
		rreverse_rotate_stack(stack_a, stack_b, 0);
	else
		ft_free_and_exit(stack_a, stack_b);
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
	if (ft_is_increasing(stack_a) && !(*stack_b)->head)
		ft_printf("\033[0;32mOK\n");
	else
		ft_printf("\033[0;31mKO\n");
	free(line);
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
