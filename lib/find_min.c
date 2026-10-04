#include "push_swap.h"

int	find_min(t_node *stack)
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
