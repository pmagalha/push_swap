/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:56:55 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/05 10:38:32 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*insert_at_head(t_stack_node *head, int new_value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	new_node->value = new_value;
	if (head == NULL)
		return (new_node);
	else
	{
		new_node->next = head;
		return (new_node);
	}
}

t_stack_node	*insert_at_tail(t_stack_node *head, int new_value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = malloc(sizeof(t_stack_node));
	new_node->value = new_value;
	current = head;
	if (head == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		return (head);
	}
}

t_stack_node	*delete_head_node(t_stack_node *head)
{
	t_stack_node	*to_return;

	to_return = head->next;
	if (head == NULL)
		return (NULL);
	else if (head)
	{
		free(head);
		return (to_return);
	}
	return (0);
}

t_stack_node    *delete_tail_node(t_stack_node  *head)
{
    t_stack_node  *current;
    
    if (head == NULL)
        return (NULL);
    else if (head->next == NULL)
    {    
        free (head);
        return (NULL);   
    }
    else
    {
        current = head;
        t_stack_node  *prev = NULL;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
    prev->next = NULL;
    return (head);
    }
}

int	list_lenght_iter(t_stack_node *head)
{
	int	i;
	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}
