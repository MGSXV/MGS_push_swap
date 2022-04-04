/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:36:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/04 21:10:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "types.h"

void	ft_error(const char *err_msg);
t_node	*ft_new_node(int data);
void	ft_add_node_at_first(t_node *new_node, t_node **head);
void	ft_push_to_stack(t_node **head, char **v, int c);

#endif