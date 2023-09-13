/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:52:25 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/13 12:08:15 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_stack2(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	free_all(t_stack_node *a, t_stack_node *b, t_stack_node *dup_pos)
{
	if (a)
		free_stack2(a);
	if (dup_pos)
		free_stack2(dup_pos);
	if (b)
		free_stack2(b);
}
