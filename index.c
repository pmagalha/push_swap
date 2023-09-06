/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:09:49 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 10:29:35 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack_node *sorted_stack)
{
	int				index;
	t_stack_node	*current;

	index = 0;
	current = sorted_stack;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

int	find_index(int n, t_stack_node *sorted)
{
	int	res;

	res = 0;
	while (sorted)
	{
		if (n == sorted->value)
			break ;
		sorted = sorted->next;
		res++;
	}
	return (res);
}
