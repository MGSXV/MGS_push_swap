/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:51:38 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/06 20:33:15 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	ft_error(const char *err_msg)
{
	ft_printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

void	ft_handle_args(int ac, char *av)
{
	if (ac == 1)
		ft_error("Invalid number of arguments!\n\
Try \"--help\" for more information.\n");
	if (ac == 2)
	{
		if (!ft_strncmp(av, "--help", 6))
		{
			ft_error("\"push_swap\" requires minimum of one argument \
passed as fllows:\n$> ./push_swap arg1 arg2 arg3 arg4 ...\n");
		}
		else
			ft_error("Error!\n");
	}
}
