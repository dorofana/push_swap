#include "push_swap.h"

int	find_max(t_node *stack)
{
	int		max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
