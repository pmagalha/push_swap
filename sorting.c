/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:41:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 11:15:46 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack_node *a)
{
	int				temp;
	bool			swapped;
	t_stack_node	*current;
	t_stack_node	*prev;

	current = a;
	prev = NULL;
	if (a == NULL)
		return ;
	if (a->next == NULL)
		return ;
	swapped = true;
	while (swapped)
	{
		swapped = false;
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
					swapped = true;
				}
			}
		}
	}
}
