#include "push_swap.h"

void	decide_cases_a(t_grid *push_swap, int a, int b, int c)
{
	if (a > b && a > c)
	{
		sa(push_swap);
		pb(push_swap);
		sa(push_swap);
		pa(push_swap);
		if (b > c)
			sa(push_swap);
	}
	else if (b > a && b > c)
	{
		pb(push_swap);
		sa(push_swap);
		pa(push_swap);
		if (a > c)
			sa(push_swap);
	}
	else if (a > b)
		sa(push_swap);
}

void	sort_top_three_a(t_grid *push_swap)
{
	int a;
	int b;
	int c;

	a = push_swap->stack_a->value;
	b = push_swap->stack_a->next->value;
	c = push_swap->stack_a->next->next->value;
	decide_cases_a(push_swap, a, b, c);
}

void	sort_top_three_b(t_grid *push_swap)
{
	pa(push_swap);
	pa(push_swap);
	pa(push_swap);
	sort_top_three_a(push_swap);
}
