/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:04 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/31 22:01:29 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

int	main(int c, char **v)
{
	int		i;
	t_node	*head;

	i = -1;
	head = (t_node **) malloc(sizeof(t_node *));
	if (!head)
		ft_error("Could not initialize the program!\n");
	if (c > 3)
    	ft_error("Not enough arguements!\n");
	while (++i < c - 1)
	{
		  
	}
	
}