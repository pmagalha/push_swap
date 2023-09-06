/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:46:35 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 10:58:53 by pmagalha         ###   ########.fr       */
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
	int				value;
	t_stack_node	*first;

	first = NULL;
	value = a->value;
	if (a != NULL || a->next != NULL)
	{
		first = insert_at_tail(a, value);
		first = delete_head_node(a);
	}
	ft_printf("ra\n");
	return (first);
}

t_stack_node	*rev_rot_a(t_stack_node *a)
{
	int				last_value;
	t_stack_node	*last;
	t_stack_node	*new_head;

	if (a == NULL || a->next == NULL)
		return (a);
	last = a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last_value = last->value;
	new_head = delete_tail_node(a);
	new_head = insert_at_head(a, last_value);
	ft_printf("rra\n");
	return (new_head);
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
