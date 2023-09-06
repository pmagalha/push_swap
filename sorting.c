/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:41:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 14:22:55 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
