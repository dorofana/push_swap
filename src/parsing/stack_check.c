/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:08:14 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:08:14 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] =='+' || nbr[i] == '-')
			i++;
	if (nbr[i] =='+' || nbr[i] == '-' || !nbr[i])
		return (1);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	process_values(t_grid *push_swap, char *val_str)
{
	long	num;

	if (check_nbr(val_str) == 1)
		return (1);
	num = ft_atol(val_str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (has_duplicate(push_swap->stack_a, (int)num) == 1)
		return (1);
	if (stack_add_back(&push_swap->stack_a, stack_new_node((int)num)) == 1)
		return (1);
	return (0);
}
