/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:19:25 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/31 15:51:54 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack_node    *delete_tail_node(t_stack_node  *head)
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

void    print_lists(t_stack_node *head)
{
	int				i;
	t_stack_node	*current;
	int				value;
	t_stack_node	*first;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

t_stack_node	*insert_at_head(t_stack_node *head, int new_value)
{
	t_stack_node	*new_node;

	new_node = calloc(1, sizeof(t_stack_node));
	new_node->value = new_value;
	if (head == NULL)
		return (new_node);
	else
	{
		new_node->next = head;
		return (new_node);
	}
}*/

t_stack_node    *rev_rot_a(t_stack_node *a)
{
    if (a == NULL || a->next == NULL)
        return a;

    t_stack_node *last = a;
    
    while (last->next != NULL)
    {
        last = last->next;
    }
    int last_value;
    last_value = last->value;
    t_stack_node    *new_head;
    new_head = delete_tail_node(a);
    new_head = insert_at_head(a, last_value);
    ft_printf("rra\n");
    return (new_head);
}

t_stack_node    *rev_rot_b(t_stack_node *b)
{
    if (b == NULL || b->next == NULL)
        return b;

    t_stack_node *last = b;
    
    while (last->next != NULL)
    {
        last = last->next;
    }
    int last_value;
    last_value = last->value;
    t_stack_node    *new_head;
    new_head = delete_tail_node(b);
    new_head = insert_at_head(b, last_value);
    ft_printf("rrb\n");
    return (new_head);
}

/*void	rev_rot_rr(t_stack_node *head_a, t_stack_node *head_b)
{
	rev_rotate(head_a);
	rev_rot_b(head_b);
}

int main (void)
{
	t_stack_node	value1;
	t_stack_node	value2;
	t_stack_node	value3;

	value1.value = 1;
	value2.value = 5;
	value3.value = 12;
	value1.next = &value2;
	value2.next = &value3;
	value3.next = NULL;

	printf("Before rotate:\n");
	printf("Stack:\n");
	print_lists(&value1);

	t_stack_node *newStack = rev_rot_a(&value1);

	printf("After rotate:\n");
	printf("Stack:\n");
	print_lists(newStack);
}*/