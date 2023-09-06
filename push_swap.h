/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:35:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 10:52:01 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}				t_stack_node;

// Lists auxiliaries
t_stack_node	*insert_at_head(t_stack_node *head, int new_value);
t_stack_node	*insert_at_tail(t_stack_node *head, int new_value);
t_stack_node	*delete_head_node(t_stack_node *head);
t_stack_node	*delete_tail_node(t_stack_node *head);
int				list_lenght_iter(t_stack_node *head);

// Operations
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*swap_a(t_stack_node *head);
t_stack_node	*rotate_a(t_stack_node *a);
t_stack_node	*rev_rot_a(t_stack_node *a);

// Indexation
void			assign_index(t_stack_node *sorted_stack);
int				find_index(int n, t_stack_node *sorted);

// Vibe check
// static int  repeat_nbr(int n, char **args, int i);
// static int  check_nbr (char *n);
// static int  check_array(char **args, int i);
int				check_args(int argc, char **argv);
void			cpy_stack_aux(t_stack_node *copied_head, t_stack_node *new_node,
					t_stack_node *copied_tail);

// sorting crap
void			bubble_sort(t_stack_node *a);
void			sort_functions(t_stack_node *a, t_stack_node *b,
					t_stack_node *dup_pos);
void			send_min(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_min(t_stack_node **a);
int				get_max_bits(t_stack_node **dup_pos);
void			sort3(t_stack_node **dup_pos);
void			sort4(t_stack_node **a, t_stack_node **b);
void			sort5(t_stack_node **a, t_stack_node **b);
bool			is_sorted(t_stack_node *dup_pos);
void			radix_sort(t_stack_node **dup_pos, t_stack_node **b);
int				count_digits(int num);
void			counting_sort(t_stack_node **a, int digit);
int				get_digit(int num, int digit);
void			radixSort(t_stack_node **dup_pos, t_stack_node **b);
int				get_distance(t_stack_node **a, t_stack_node *min);

#endif