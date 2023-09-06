/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:19:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 12:12:20 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_functions(t_stack_node *a, t_stack_node *b, t_stack_node *dup_pos)
{
	if (!is_sorted(a))
	{
		if (list_lenght_iter(a) == 2)
			swap_a(a);
		if (list_lenght_iter(a) == 3)
			sort3(&a);
		if (list_lenght_iter(a) == 4)
			sort4(&a, &b);
		if (list_lenght_iter(a) == 5)
			sort5(&a, &b);
		else if (list_lenght_iter(a) > 5)
			radix_sort(&dup_pos, &b);
	}
}

int	get_max_bits(t_stack_node **dup_pos)
{
	t_stack_node	*head;
	int				max;
	int				max_bits;

	head = *dup_pos;
	max = head->value;
	max_bits = 0;
	while (head)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

bool	is_sorted(t_stack_node *dup_pos)
{
	t_stack_node	*current;

	current = dup_pos;
	while (current != NULL && current->next != NULL) 
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	radix_sort(t_stack_node **dup_pos, t_stack_node **b)
{
	t_stack_node	*head_dup_pos;
	int				i;
	int				j;
	int				size;
	int				max_bits;

	i = 0;
	head_dup_pos = *dup_pos;
	size = list_lenght_iter(head_dup_pos);
	max_bits = get_max_bits(dup_pos);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_dup_pos = *dup_pos;
			if (((head_dup_pos->value >> i) & 1) == 1)
				*dup_pos = rotate_a(*dup_pos);
			else
				push_b(dup_pos, b);
		}
		while (list_lenght_iter(*b) != 0)
			push_a(dup_pos, b);
		i++;
	}
}
