/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:36:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/07 23:38:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<limits.h>
# include "types.h"

// Manage errors functions
void	ft_error(const char *err_msg, t_stack **stack);
void	ft_free_all(t_stack **stack);
// Parssing arguments functions
int		is_in_int_range(long n);
char	*is_str_digit(char *s);
void	ft_parssing_args(int ac, char **av, t_stack **stack);
// Manage stacks functions
t_node	*ft_new_node(int data);
void	ft_add_node_at_first(t_stack **stack, t_node *new_node);
// Stack sorting instructions
void	swap_stack(t_stack **stack, char s);
void	sswap_stack(t_stack **stack_a, t_stack **stack_b);
void	push_stack(t_stack **stack_1, t_stack **stack_2, char s);
void	rotate_stack(t_stack **stack, char s);
void	rrotate_stack(t_stack **stack_1, t_stack **stack_2);
void	reverse_rotate_stack(t_stack **stack, char s);
void	rreverse_rotate_stack(t_stack **stack_1, t_stack **stack_2);

#endif