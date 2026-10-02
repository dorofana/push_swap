#include "push_swap.h"

static void	init_t_bench(t_bench *ops_count)
{
	ops_count->sa = 0;
	ops_count->sb = 0;
	ops_count->ss = 0;
	ops_count->ra = 0;
	ops_count->rb = 0;
	ops_count->rr = 0;
	ops_count->rra = 0;
	ops_count->rrb = 0;
	ops_count->rrr = 0;
	ops_count->pa = 0;
	ops_count->pb = 0;
	ops_count->total_ops = 0;
}

static void	init_grid(t_grid *push_swap)
{
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->size_a = 0;
	push_swap->size_b = 0;
	push_swap->disorder = 0.0;
	push_swap->mode = MODE_ADAPTIVE;
	push_swap->bench_mode = 0;
	init_t_bench(&push_swap->ops_count);
}

int main(int argc, char **argv)
{
	t_grid push_swap;

	if (argc < 2)
		return (0);
	init_grid(&push_swap);
	parse_args(&push_swap, argc, argv);
	count_disorder(push_swap.stack_a, stack_size(push_swap.stack_a));
	/* SORTING MODES ARE HERE */
	free_stack(&push_swap.stack_a);
	free_stack(&push_swap.stack_b);
	return (0);
}
