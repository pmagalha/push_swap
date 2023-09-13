/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:16:20 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/13 12:09:53 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = biggest_node(*a);
	if (biggest == *a)
		*a = rotate_a(*a);
	else if (biggest == (*a)->next)
		*a = rev_rot_a(*a);
	if ((*a)->value > (*a)->next->value)
		*a = swap_a(*a);
}

int	get_distance(t_stack_node **a, t_stack_node *min)
{
	int				distance;
	t_stack_node	*head;

	distance = 0;
	head = *a;
	while (head)
	{
		if (head == min)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	sort4(t_stack_node **a, t_stack_node **b)
{
	int	distance;

	if (is_sorted(*a))
		return ;
	distance = get_distance(a, find_min(a));
	if (distance == 1)
		*a = rotate_a(*a);
	else if (distance == 2)
	{
		*a = rotate_a(*a);
		*a = rotate_a(*a);
	}
	else if (distance == 3)
		*a = rev_rot_a(*a);
	if (is_sorted(*a))
		return ;
	push_b(a, b);
	sort3(a);
	push_a(a, b);
}

void	sort5(t_stack_node **a, t_stack_node **b)
{
	int	distance;

	distance = get_distance(a, find_min(a));
	if (distance == 1)
		*a = rotate_a(*a);
	else if (distance == 2)
	{
		*a = rotate_a(*a);
		*a = rotate_a(*a);
	}
	else if (distance == 3)
	{
		*a = rev_rot_a(*a);
		*a = rev_rot_a(*a);
	}
	else if (distance == 4)
		*a = rev_rot_a(*a);
	if (is_sorted(*a))
		return ;
	push_b(a, b);
	sort4(a, b);
	push_a(a, b);
}
