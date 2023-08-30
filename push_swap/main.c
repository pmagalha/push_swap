/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:47:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/29 12:40:54 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	t_stack_node	*a;
	t_stack_node	*b;
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
	
	push_b(&a, &b);

	printf("List a\n");
	print_lists(a);
	printf("List b\n");
	print_lists(b);
	
	push_a(&a, &b);
	
	printf("List a\n");
	print_lists(a);
	printf("List b\n");
	print_lists(b);

	free(a); // CRIAR FUNCAO PARA FAZER FREE DOS ELEMENTOS DE A
}