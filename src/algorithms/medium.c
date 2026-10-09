/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:34:29 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 16:34:30 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else
		return (30);
}

static void	push_chunks_to_b(t_grid *push_swap, int chunk_size)
{
	int	i;

	i = 0;
	while (push_swap->stack_a)
	{
		if (push_swap->stack_a->index <= i)
		{
			pb(push_swap);
			rb(push_swap);
			i++;
		}
		else if (push_swap->stack_a->index <= i + chunk_size)
		{
			pb(push_swap);
			i++;
		}
		else
			ra(push_swap);
	}
}

static	void	push_chunks_back(t_grid *push_swap)
{
	int	max_pos;

	while (push_swap->size_b > 0)
	{
		max_pos = find_max_pos(push_swap->stack_b);
		if (max_pos <= (push_swap->size_b / 2))
		{
			while (max_pos > 0)
			{
				rb(push_swap);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < push_swap->size_b)
			{
				rrb(push_swap);
				max_pos++;
			}
		}
		pa(push_swap);
	}
}

void	sort_medium(t_grid *push_swap)
{
	int	chunk_size;

	chunk_size = get_chunk_size(push_swap->size_a);
	push_chunks_to_b(push_swap, chunk_size);
	push_chunks_back(push_swap);
}
