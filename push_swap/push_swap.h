/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:35:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/29 12:32:04 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct node
{
	int			value;
	struct node	*next;
}				t_stack_node;

// Lists auxiliaries
void			print_lists(t_stack_node *head);
t_stack_node	*insert_at_head(t_stack_node *head, int new_value);
t_stack_node	*insert_at_tail(t_stack_node *head, int new_value);
t_stack_node	*delete_head_node(t_stack_node *head);
t_stack_node    *delete_tail_node(t_stack_node  *head);

// Operations
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*swap_a(t_stack_node *head);
t_stack_node	*swap_b(t_stack_node *head);
void			swap_ss(t_stack_node *head_a, t_stack_node *head_b);
void			rotate_a(t_stack_node *a);
void			rotate_b(t_stack_node *b);
void			rotate_rr(t_stack_node *head_a, t_stack_node *head_b);
t_stack_node    *rev_rot_a(t_stack_node *a);
t_stack_node    *rev_rot_b(t_stack_node *b);
void			rev_rot_rr(t_stack_node *head_a, t_stack_node *head_b);

//Vibe check
//static int  repeat_nbr(int n, char **args, int i);
//static int  check_nbr (char *n);
//static int  check_array(char **args, int i);
int		check_args(int argc, char **argv);
void    sort_list(t_stack_node *a);

#endif