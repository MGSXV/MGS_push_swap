/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:55:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/04 03:10:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

struct s_node
{
	struct s_node	*next_node;
	struct s_node	*previous_node;
	int				data;
}	typedef t_node;

struct s_stack
{
	t_list	*head;
	t_list	*tail;
}	typedef t_stack;
