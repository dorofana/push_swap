/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:35:20 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:35:20 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_grid *push_swap, int stack_size)
{
	int	current_size;

	if (stack_size <= 5)
	{
		tiny_sorting(push_swap);
		return ;
	}
	current_size = stack_size;
	while (current_size > 0)
	{
		push_min_to_b(push_swap, current_size);
		current_size--;
	}
	while (push_swap->stack_b != NULL)
		pa(push_swap);
}
