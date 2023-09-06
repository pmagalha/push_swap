/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:47:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/05 20:19:37 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*cpy_stack(t_stack_node *original)
{
	int	value;
	t_stack_node	*new_node;
	t_stack_node	*copied_head;
	t_stack_node	*copied_tail;
	t_stack_node	*current;
	
	copied_head = NULL;
	copied_tail = NULL;
	current = original;
	while (current != NULL)
	{
		value = current->value;
		new_node = insert_at_tail(NULL, value);
		if (copied_tail == NULL)
		{
			copied_head = new_node;
			copied_tail = new_node;
		}
		else
		{
			copied_tail->next = new_node;
			copied_tail = new_node;
		}
		current = current->next;
	}
	return (copied_head);
}

void	assign_index(t_stack_node *sorted_stack)
{
	int	index;
	t_stack_node *current;
	
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
	int res;

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

t_stack_node	*create_pos(t_stack_node *original)
{
	t_stack_node	*sorted;
	t_stack_node	*dup_positive;
	
	sorted = cpy_stack(original);
	sort_list(sorted);
	assign_index(sorted);
	dup_positive = NULL;
	while (original)
	{ 
		dup_positive = insert_at_tail(dup_positive, find_index(original->value, sorted));
		original = original->next;
	}
	return (dup_positive);
}

int	main(int argc, char **argv)
{
	int				i;
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*dup_pos;
	char			**split;

	i = 0;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (check_args(argc, argv))
		return (1);
	
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		split = argv;
	}
	while (split[i] != NULL)
	{
		a = insert_at_tail(a, atoi(split[i]));
		i++;
	}
	
	assign_index(a);
	dup_pos = create_pos(a);

	if (!is_sorted(a))
	{
		if (list_lenght_iter(a) == 2)
			swap_a(a);
		if (list_lenght_iter(a) == 3)
			sort3(&a);
		if (list_lenght_iter(a) == 4)
			sort4(&a, &b);
		if (list_lenght_iter(a) == 5)
			sort5(&a, &b);
		else if (list_lenght_iter(a) > 5)
			radix_sort(&dup_pos, &b);
	}
	free(a); // CRIAR FUNCAO PARA FAZER FREE DOS ELEMENTOS DE A
}