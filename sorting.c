/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:41:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/13 12:10:26 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_min(t_stack_node **a)
{
	t_stack_node	*min;
	t_stack_node	*current;

	if (*a == NULL)
		return (NULL);
	min = *a;
	current = (*a)->next;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_stack_node	*biggest_node(t_stack_node *stack)
{
	t_stack_node	*biggest_node;
	long			biggest;
	int				len;

	biggest = -2148364748;
	len = list_lenght_iter(stack);
	if (stack == NULL || len == 1)
		return (NULL);
	biggest_node = stack;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

bool	sort_aux(t_stack_node *current)
{
	int				temp;
	t_stack_node	*prev;

	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		if (current != NULL)
		{
			if (current->value < prev->value)
			{
				temp = prev->value;
				prev->value = current->value;
				current->value = temp;
				return (true);
			}
		}
	}
	return (false);
}

void	sort_list(t_stack_node *a)
{
	bool			swapped;

	if (a == NULL)
		return ;
	if (a->next == NULL)
		return ;
	swapped = true;
	while (swapped)
	{
		swapped = sort_aux(a);
	}
}
