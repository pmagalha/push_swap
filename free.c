/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:52:25 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 17:18:12 by pmagalha         ###   ########.fr       */
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

/*t_stack_node	*free_stack(t_stack_node *stack)
{	
	t_stack_node *to_return;
	
    if (stack == NULL)
        return (NULL);
    else if (stack)
    {
        to_return = stack->next;
        free(stack);
        return(to_return);
    }
    return (0);
}*/

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*node;

	node = (stack);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void    free_stack2(t_stack_node *head)
{
    t_stack_node *current;
    
    current = head;
    while (current != NULL)
        current = delete_head_node(current);
}