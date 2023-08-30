/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vibe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:45:09 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/29 11:17:41 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  repeat_nbr(int n, char **args, int i)
{
    while (args[++i])
    {
        if(ft_atoi(args[i]) == n)
        {
            write (2, "Error\n", 6);
            return (1);
        }
    }
    return (0);
}

static int  check_nbr (char *n)
{
    int i;

    i = 0;
    if (n[0] == '-' || n[0] == '+')
        i++;
    if (!n[i])
    {
        write(2, "Error\n", 6);
        return (1);
    }
    while (n[i])
    {
        if (!ft_isdigit(n[i++]))
        {
            write(2, "Error\n", 6);
            return (1);
        }
    }
    return (0);
}

static int  check_array(char **args, int i)
{
    long    tmp;

    while (args[i])
    {
        tmp = ft_atol(args[i]);
        if (check_nbr(args[i]))
            return (1);
        if (repeat_nbr((int)tmp, args, i))
			return (1);
        if (tmp < -2147483648 || tmp > 2147483648)
        {
            write (2, "Error\n", 6);
            return (1);
        }
        i++;
    }
    return (0);
}

int check_args(int argc, char **argv)
{
    char **args;
    int     i;
    int     valid;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    valid = check_array(args, i);
    if (!args[0])
    {
        free(args); // mudar para free array
        return (1);
    }
    if (argc == 2)
        free(args); // mudar para free array
    if (valid)
        return (1);
    return (0);
}