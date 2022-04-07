/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:24:30 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/07 05:05:43 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	is_in_int_range(long n)
{
	if (n <= INT_MAX && n >= INT_MIN)
		return (1);
	return (0);
}

char	*is_str_digit(char *s)
{
	int	n;
	int	i;

	n = ft_atoi(s);
	i = -1;
	if (!s[0])
		return (NULL);
	while (s[++i])
	{
		if (i == 0)
		{
			if (s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
				return (NULL);
		}
		else
		{
			if (!ft_isdigit(s[i]))
				return (NULL);
		}
	}
	return (s);
}

int	ft_is_num_dup(t_node **head, int num)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->data == num)
			return (0);
		tmp = tmp->next_node;
	}
	return (1);
}

static void	ft_check_args(int ac, char **av, t_stack **stack)
{
	if (ac == 1)
		ft_error("Invalid number of arguments!\n\
Try \"--help\" for more information.\n", stack);
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "--help", 6))
			ft_error("\"push_swap\" requires minimum of one argument \
passed as fllows:\n$> ./push_swap arg1 arg2 arg3 arg4 ...\n", stack);
		else
			if (!is_str_digit(av[1]) || !is_in_int_range(ft_atoi(av[1])))
				ft_error("Error!\n", stack);
	}
}

void	ft_parssing_args(int ac, char **av, t_stack **stack)
{
	int		i;
	long	num;

	i = ac;
	ft_check_args(ac, av, stack);
	if (ac > 2)
	{
		while (--i)
		{
			num = ft_atoi(av[i]);
			if (!is_str_digit(av[i]) || !is_in_int_range(num)
				|| !ft_is_num_dup(&(*stack)->head, num))
				ft_error("Error!\n", stack);
			ft_add_node_at_first(stack, ft_new_node(num));
		}
	}
}
