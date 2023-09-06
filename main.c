/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:47:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/09/06 11:54:43 by pmagalha         ###   ########.fr       */
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
	bubble_sort(sorted);
	assign_index(sorted);
	dup_positive = NULL;
	while (original)
	{
		dup_positive = insert_at_tail(dup_positive, 
				find_index(original->value, sorted));
		original = original->next;
	}
	return (dup_positive);
}

void	init_stack(int argc, char **argv, t_stack_node **a)
{
	int				i;
	char			**split;

	i = 0;
	if (argc < 2)
		return ;
	if (check_args(argc, argv))
		return ;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		split = argv;
	}
	while (split[i] != NULL)
	{
		*a = insert_at_tail(*a, atoi(split[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*dup_pos;

	a = NULL;
	b = NULL;
	init_stack(argc, argv, &a);
	assign_index(a);
	dup_pos = create_pos(a);
	sort_functions(a, b, dup_pos);
	free(a);
}
