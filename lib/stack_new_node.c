#include "push_swap.h"

/* IMPLEMENTED FOR PUSH SWAP*/
t_node	*stack_new_node(int	new_value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = new_value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
