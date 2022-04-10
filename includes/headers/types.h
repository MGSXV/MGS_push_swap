/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:55:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/10 21:38:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	struct s_node	*next_node;
	struct s_node	*previous_node;
	int				data;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		is_sorted;
}	t_stack;

#endif