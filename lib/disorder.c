/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:06:37 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:06:39 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	count_disorder(t_node *stack, int size)
{
	t_node	*current;
	t_node	*to_compare;
	int		inversions;
	int		max_inversions;

	if (!stack || !stack->next || size <= 1)
		return (0.0);
	max_inversions = (size * (size - 1)) / 2;
	inversions = 0;
	current = stack;
	while (current)
	{
		to_compare = current->next;
		while (to_compare)
		{
			if (current->value > to_compare->value)
				inversions++;
			to_compare = to_compare->next;
		}
		current = current->next;
	}
	return ((float)inversions / (float)max_inversions);
}
