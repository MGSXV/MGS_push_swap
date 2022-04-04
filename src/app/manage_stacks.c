/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:21:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/04 22:30:44 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_push_to_stack(t_node **head, char **v, int c)
{
	int		i;

	i = c;
	while (--i > 0)
		ft_add_node_at_first(ft_new_node(ft_atoi(v[i])), head);
}
