/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:24:30 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/07 00:00:12 by sel-kham         ###   ########.fr       */
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

void	ft_parssing_args(int ac, char **av)
{
	int	i;

	i = 0;
	ac = 0;
	while (av[++i])
		if (!is_str_digit(av[i]) || !is_in_int_range(ft_atoi(av[i])))
			ft_error("Error!\n");
	ft_error("Good!\n");
}
