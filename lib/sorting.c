/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:07:43 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 17:32:33 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sorting(t_grid *push_swap)
{
	if (push_swap->size_a == 2)
		sa(push_swap);
	else if (push_swap->size_a == 3)
		sort_three(push_swap);
	else if (push_swap->size_a == 4)
		sort_four(push_swap, 4);
	else if (push_swap->size_a == 5)
		sort_five(push_swap, 5);
}

void	push_min_to_b(t_grid *push_swap, int stack_size)
{
	int	min_pos;

	min_pos = find_min_pos(push_swap->stack_a);
	if (min_pos <= (stack_size / 2))
	{
		while (min_pos > 0)
		{
			ra(push_swap);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_size)
		{
			rra(push_swap);
			min_pos++;
		}
	}
	pb(push_swap);
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

void	sort_four(t_grid *push_swap, int stack_size)
{
	if (is_sorted(push_swap->stack_a) == 1)
		return ;
	push_min_to_b(push_swap, stack_size);
	sort_three(push_swap);
	pa(push_swap);
}

void	sort_five(t_grid *push_swap, int stack_size)
{
	if (is_sorted(push_swap->stack_a) == 1)
		return ;
	push_min_to_b(push_swap, stack_size);
	sort_four(push_swap, stack_size - 1);
	pa(push_swap);
}
