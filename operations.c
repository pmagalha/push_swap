/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:46:35 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/13 12:07:20 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_b;

	if (*b != NULL)
	{
		top_b = *b;
		*b = (*b)->next;
		top_b->next = *a;
		*a = top_b;
	}
	ft_printf("pa\n");
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_a;

	if (*a != NULL)
	{
		top_a = *a;
		*a = (*a)->next;
		top_a->next = *b;
		*b = top_a;
	}
	ft_printf("pb\n");
}

t_stack_node	*rotate_a(t_stack_node *a)
{
	t_stack_node	*first;
	t_stack_node	*current;

	first = a;
	if (a != NULL && a->next != NULL)
	{
		current = a;
		while (current->next != NULL)
			current = current->next;
		current->next = a;
		a = a->next;
		current->next->next = NULL;
	}
	ft_printf("ra\n");
	return (a);
}

t_stack_node	*rev_rot_a(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*prev;

	current = a;
	prev = NULL;
	if (a == NULL || a->next == NULL)
		return (a);
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = a;
	ft_printf("rra\n");
	return (current);
}

t_stack_node	*swap_a(t_stack_node *a)
{
	int				temp;
	t_stack_node	*first;
	t_stack_node	*second;

	first = a;
	second = a->next;
	if (a == NULL || a->next == NULL)
		return (a);
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_printf("sa\n");
	return (a);
}
