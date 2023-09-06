/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:37:16 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/31 10:26:59 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    print_lists(t_stack_node *head)
{
	int				i;
	t_stack_node	*current;
	t_stack_node	*first;
	t_stack_node	*second;
	int				temp;

	i = 0;
	current = head;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}*/

t_stack_node	*swap_a(t_stack_node *a)
{
	int	temp;
	t_stack_node	*first;
	t_stack_node	*second;
	
	first = a;
	second = a->next;
	if (a == NULL || a->next == NULL)
		return (a);
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_printf("sa\n");
	return (a);
}

t_stack_node	*swap_b(t_stack_node *b)
{
	int	temp;
	t_stack_node	*first;
	t_stack_node	*second;
	
	if (b == NULL || b->next == NULL)
		return (b);
	first = b;
	second = b->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_printf("sb\n");
	return (b);
}

void	swap_ss(t_stack_node *head_a, t_stack_node *head_b)
{
	swap_a(head_a);
	swap_b(head_b);
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

	printf("Before swap:\n");
	printf("Stack:\n");
	print_lists(&value1);

	t_stack_node *newStackA = swap_a(&value1);
	value1 = *newStackA;

	printf("After swap:\n");
	printf("Stack:\n");
	print_lists(&value1);
}*/