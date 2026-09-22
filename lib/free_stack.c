#include "push_swap.h"

/* IMPLEMENTED FOR PUSH_SWAP */
void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
