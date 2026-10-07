#include "push_swap.h"

void	bubble_sort_array(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median(t_node *stack, int len)
{
	int		*arr;
	int		i;
	int		median;
	t_node	*current;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	current = stack;
	i = 0;
	while (i < len && current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
    bubble_sort_array(arr, len);
    median = arr[len / 2];
    free(arr);
    return (median);
}
