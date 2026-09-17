/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:19:03 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/12 16:52:17 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*node;
	if (!src || !*src || !dest)
		return;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	*dest = node;
}

void	pa(t_grid *push_swap)
{
	push(&push_swap->stack_b, &push_swap->stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_grid *push_swap)
{
	push(&push_swap->stack_a, &push_swap->stack_b);
	write(1, "pb\n", 3);
}
