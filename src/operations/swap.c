/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:19:54 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/12 16:07:40 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_grid *push_swap)
{
	swap(&push_swap->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_grid *push_swap)
{
	swap(&push_swap->stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_grid *push_swap)
{
	swap(&push_swap->stack_a);
	swap(&push_swap->stack_b);
	write(1, "ss\n", 3);
}
