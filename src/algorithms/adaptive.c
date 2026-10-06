#include "push_swap.h"

void	sort_adaptive(t_grid *push_swap)
{
	if (push_swap->disorder < 0.2)
		sort_simple(push_swap, push_swap->size_a);
	else if (push_swap->disorder >= 0.2 && push_swap->disorder < 0.5)
		sort_medium(push_swap);
	else
		//sort_complex(push_swap);
}
