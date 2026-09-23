/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:07:34 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:07:35 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int		count;
	t_node	*node;

	if (!stack)
		return (0);
	count = 0;
	node = stack;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
