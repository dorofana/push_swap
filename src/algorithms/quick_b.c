#include "push_swap.h"

static int	sort_small_b(t_grid *push_swap, int len)
{
    if (len <= 3)
    {
        if (len == 1)
            pa(push_swap);
        else if (len == 2)
        {
            if (push_swap->stack_b->value < push_swap->stack_b->next->value)
                sb(push_swap);
            pa(push_swap);
            pa(push_swap);
        }
        else if (len == 3)
            sort_top_three_b(push_swap);
        return (1);
    }
    return (0);
}

static void	devide_stack_b(t_grid *push_swap, int len, int pivot, int *rotated, int *pushed)
{
	while (len > 0)
    {
        if (push_swap->stack_b->value >= pivot)
        {
            pa(push_swap);
            (*pushed)++;
        }
        else
        {
            rb(push_swap);
            (*rotated)++;
        }
        len--;
    }
}

static void	rotate_back_b(t_grid *push_swap, int rotated, int count_rotations)
{
if (count_rotations != 0) 
    {
        while (rotated > 0)
        {
            rrb(push_swap);
            rotated--;
        }
    }
}

void	quicksort_b(t_grid *push_swap, int len, int count_rotations)
{
    int pivot;
	int start_len;
    int rotated;
    int pushed;

    if (sort_small_b(push_swap, len) == 1)
        return ;
    pivot = get_median(push_swap->stack_b, len);
	start_len = len;
    rotated = 0;
    pushed = 0;
    devide_stack_b(push_swap, len, pivot, &rotated, &pushed);
    rotate_back_b(push_swap, rotated, count_rotations);
    quicksort_a(push_swap, pushed, 1);
    quicksort_b(push_swap, start_len / 2 + start_len % 2, 1);
    return ;
}
