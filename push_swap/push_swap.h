/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:35:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/05 20:01:32 by pmagalha         ###   ########.fr       */
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
	int			index;
	struct node	*next;
}				t_stack_node;

// Lists auxiliaries
void			print_lists(t_stack_node *head);
t_stack_node	*insert_at_head(t_stack_node *head, int new_value);
t_stack_node	*insert_at_tail(t_stack_node *head, int new_value);
t_stack_node	*delete_head_node(t_stack_node *head);
t_stack_node    *delete_tail_node(t_stack_node  *head);
int				list_lenght_iter(t_stack_node *head);

// Operations
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*swap_a(t_stack_node *head);
t_stack_node	*swap_b(t_stack_node *head);
void			swap_ss(t_stack_node *head_a, t_stack_node *head_b);
t_stack_node	*rotate_a(t_stack_node *a);
void			rotate_b(t_stack_node *b);
void			rotate_rr(t_stack_node *head_a, t_stack_node *head_b);
t_stack_node    *rev_rot_a(t_stack_node *a);

//Vibe check
//static int  repeat_nbr(int n, char **args, int i);
//static int  check_nbr (char *n);
//static int  check_array(char **args, int i);
int		check_args(int argc, char **argv);
void    sort_list(t_stack_node *a);

//sorting tests
//void sort_three_numbers(t_stack_node **a);
void	send_min(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_min(t_stack_node **a);
int	get_max_bits(t_stack_node **dup_pos);
void	sort3(t_stack_node **dup_pos);
void	sort4(t_stack_node **a, t_stack_node **b);
void	sort5(t_stack_node **a, t_stack_node **b);
bool	is_sorted(t_stack_node *dup_pos);
void	radix_sort(t_stack_node **dup_pos, t_stack_node **b);
int count_digits(int num);
void counting_sort(t_stack_node **a, int digit);
int get_digit(int num, int digit);
void radixSort(t_stack_node **dup_pos, t_stack_node **b);
int	get_distance(t_stack_node **a, t_stack_node *min);

#endif