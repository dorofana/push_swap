/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:08:03 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/23 17:08:03 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_values(char **values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

static int	parse_argument(t_grid *push_swap, char *arg_str)
{
	char	**lst;
	int		i;

	lst = ft_split(arg_str, ' ');
	if (!lst || !lst[0])
	{
		free_values(lst);
		return (1);
	}
	i = 0;
	while (lst[i])
	{
		if (process_values(push_swap, lst[i]) == 1)
		{
			free_values(lst);
			return (1);
		}
		i++;
	}
	free_values(lst);
	return (0);
}

void	parse_args(t_grid *push_swap, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			indicate_flag(push_swap, argv[i]);
		else if (parse_argument(push_swap, argv[i]) == 1)
		{
			write(2, "Error\n", 6);
			free_stack(&push_swap->stack_a);
			return ;
		}
		i++;
	}
}
