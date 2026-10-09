/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:31:10 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 17:31:10 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_small_b(t_grid *push_swap, int len)
{
	if (len <= 3)
	{
		if (len == 1)
			pa(push_swap);
		else if (len == 2)
		{
			if (push_swap->stack_b->value < push_swap->stack_b->next->value)
				sb(push_swap);
			pa(push_swap);
			pa(push_swap);
		}
		else if (len == 3)
			sort_top_three_b(push_swap);
		return (1);
	}
	return (0);
}

static void	devide_stack_b(t_grid *push_swap, t_sort *qs, int len)
{
	while (len > 0)
	{
		if (push_swap->stack_b->value >= qs->pivot)
		{
			pa(push_swap);
			qs->pushed++;
		}
		else
		{
			rb(push_swap);
			qs->rotated++;
		}
		len--;
	}
}

static void	rotate_back_b(t_grid *push_swap, t_sort *qs, int count_rotations)
{
	if (count_rotations != 0)
	{
		while (qs->rotated > 0)
		{
			rrb(push_swap);
			qs->rotated--;
		}
	}
}

void	quicksort_b(t_grid *push_swap, int len, int count_rotations)
{
	t_sort	quick_sort;

	if (sort_small_b(push_swap, len) == 1)
		return ;
	quick_sort.pivot = get_median(push_swap->stack_b, len);
	quick_sort.start_len = len;
	quick_sort.rotated = 0;
	quick_sort.pushed = 0;
	devide_stack_b(push_swap, &quick_sort, len);
	rotate_back_b(push_swap, &quick_sort, count_rotations);
	quicksort_a(push_swap, quick_sort.pushed, 1);
	quicksort_b(push_swap, quick_sort.rotated, 1);
	return ;
}
