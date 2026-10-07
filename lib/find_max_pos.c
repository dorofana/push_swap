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
