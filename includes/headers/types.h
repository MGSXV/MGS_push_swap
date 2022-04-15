/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:55:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/14 21:55:12 by sel-kham         ###   ########.fr       */
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
	int				index;
	int				len;
	int				sub_seq;
	int				is_negative;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		is_sorted;
	int		max;
	int		min;
}	t_stack;

#endif