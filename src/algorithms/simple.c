#include "push_swap.h"

void	sort_simple(t_grid *push_swap, int stack_size)
{
	int	current_size;

	if (stack_size <= 5)
	{
		tiny_sorting(push_swap);
		return ;
	}
	current_size = stack_size;
	while (current_size > 0)
	{
		push_min_to_b(push_swap, current_size);
		current_size--;
	}
	while (push_swap->stack_b != NULL)
        pa(push_swap);
}
