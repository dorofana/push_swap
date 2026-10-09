/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:33:31 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:33:32 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack)
{
	int		index;
	t_node	*current;
	t_node	*to_compare;

	current = stack;
	while (current)
	{
		index = 0;
		to_compare = stack;
		while (to_compare)
		{
			if (to_compare->value < current->value)
				index++;
			to_compare = to_compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
