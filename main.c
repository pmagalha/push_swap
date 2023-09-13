/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:47:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:48 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*cpy_stack(t_stack_node *original)
{
	int				value;
	t_stack_node	*new_node;
	t_stack_node	*copied_head;
	t_stack_node	*copied_tail;

	copied_head = NULL;
	copied_tail = NULL;
	new_node = NULL;
	while (original != NULL)
	{
		value = original->value;
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
		original = original->next;
	}
	return (copied_head);
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
		dup_positive = insert_at_tail(dup_positive, 
				find_index(original->value, sorted));
		original = original->next;
	}
	free_stack2(sorted);
	return (dup_positive);
}

t_stack_node	*init_stack(int argc, char **argv)
{
	int				i;
	char			**split;
	t_stack_node	*stack;

	stack = NULL;
	i = 0;
	if (argc < 2)
		return (NULL);
	if (check_args(argc, argv))
		return (NULL);
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		split = argv;
	}
	while (split[i] != NULL)
	{
		stack = insert_at_tail(stack, ft_atol(split[i]));
		i++;
	}
	if (argc == 2)
		free_array(split);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*dup_pos;

	a = init_stack(argc, argv);
	b = NULL;
	assign_index(a);
	dup_pos = NULL;
	dup_pos = create_pos(a);
	if (!is_sorted(a))
	{
		if (list_lenght_iter(a) == 3)
			sort3(&a);
		if (list_lenght_iter(a) == 4)
			sort4(&a, &b);
		if (list_lenght_iter(a) == 5)
			sort5(&a, &b);
		else if (list_lenght_iter(a) > 5)
			radix_sort(&dup_pos, &b);
	}
	free_all(a, b, dup_pos);
}
