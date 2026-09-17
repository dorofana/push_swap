/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:45:43 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/12 17:09:11 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_grid *push_swap)
{
	rotate(&push_swap->stack_a);
	write(1,"ra\n", 3);
}

void	rb(t_grid *push_swap)
{
	rotate(&push_swap->stack_b);
	write(1,"rb\n", 3);
}

void	rr(t_grid *push_swap)
{
	rotate(&push_swap->stack_a);
	rotate(&push_swap->stack_b);
	write(1, "rr\n", 3);
}
