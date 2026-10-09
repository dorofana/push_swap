/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:09:52 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:09:52 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_node *stack)
{
	int	min;
	int	min_position;
	int	current_position;

	min = stack->value;
	min_position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (min_position);
}
