/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:07:20 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:07:20 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* IMPLEMENTED FOR PUSH_SWAP*/
int	stack_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return (1);
	if (!*stack)
	{
		*stack = new;
		return (0);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (0);
}
