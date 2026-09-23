/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:07:43 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:07:45 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	find_max(t_node *stack)
{
	int		max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_grid *push_swap)
{
	int		max;
	t_node	*stack;
	int		check_stack;

	stack = push_swap->stack_a;
	check_stack = is_sorted(stack);
	if (check_stack == 1)
		return ;
	max = find_max(stack);
	if (stack->value == max)
		ra(push_swap);
	else if (stack->next->value == max)
		rra(push_swap);
	stack = push_swap->stack_a;
	if (stack->value > stack->next->value)
		sa(push_swap);
}
