/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:09:35 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:09:43 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_node *stack)
{
	int	max;
	int	max_position;
	int	current_position;

	max = stack->value;
	max_position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (max_position);
}
