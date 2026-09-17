/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:05:33 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/12 17:09:41 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_grid *push_swap)
{
	reverse(&push_swap->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_grid *push_swap)
{
	reverse(&push_swap->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_grid *push_swap)
{
	reverse(&push_swap->stack_a);
	reverse(&push_swap->stack_b);
	write(1, "rrr\n", 4);
}
