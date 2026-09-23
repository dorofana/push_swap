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
