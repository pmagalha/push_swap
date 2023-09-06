/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:41:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/30 10:43:19 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_list(t_stack_node *a)
{
    if (a == NULL)
        return ;
    if (a->next == NULL)
        return ;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        t_stack_node *current = a;
        t_stack_node *prev = NULL;
        
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
            if (current != NULL)
            {
                if (current->value < prev->value)
                {
                    int temp;
                    temp = prev->value;
                    prev->value = current->value;
                    current->value = temp;
                    swapped = true;
                }
            }
        }
    }
}