#include "push_swap.h"

/* IMPLEMENTED FOR PUSH_SWAP*/
int	stack_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return (1);
	if (!*stack)
	{
		*stack = new;
		return (0);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (0);
}
