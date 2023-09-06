/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:48:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/05 19:23:14 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    print_lists(t_stack_node *head)
{
	int				i;
	t_stack_node	*current;
	t_stack_node	*top_b;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}*/

//alterado o push para if (*b != NULL) em vez de if (b != NULL)
void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *top_b;
	
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
	t_stack_node *top_a;

	if (*a != NULL)
	{
		top_a = *a;
		*a = (*a)->next;
		top_a->next = *b;
		*b = top_a;
	}
	ft_printf("pb\n");
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

	t_stack_node *stackB = &value1;
	t_stack_node *stackA = NULL;

	printf("Before push:\n");
	printf("Stack A:\n");
	print_lists(stackA);
	printf("Stack B:\n");
	print_lists(stackB);
	printf("After push:\n");
	printf("Stack A:\n");
	stackA = push_a(&stackA, &stackB);
	print_lists(stackA);
	printf("Stack B:\n");
	print_lists(stackB);
}*/