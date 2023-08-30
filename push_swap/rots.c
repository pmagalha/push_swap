/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:12:12 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/29 12:31:19 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    print_lists(t_stack_node *head)
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
}*/

void	rotate_a(t_stack_node *a)
{
	int				value;
	t_stack_node	*first;
	
	value = a->value;
	if (a != NULL || a->next != NULL)
	{
	first = insert_at_tail(a, value);
	first = delete_head_node(a);
	}
	ft_printf("ra\n");
}

void	rotate_b(t_stack_node *b)
{
	int				value;
	t_stack_node	*first;

	value = b->value;
	if (b == NULL || b->next == NULL)
	{
	first = insert_at_tail(b, value);
	first = delete_head_node(b);
	}
	ft_printf("rb\n");
}

void	rotate_rr(t_stack_node *head_a, t_stack_node *head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
}

/*int main (void)
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

	t_stack_node *newStack = rotate_a(&value1);

	printf("After rotate:\n");
	printf("Stack:\n");
	print_lists(newStack);
}*/