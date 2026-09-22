/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:25:46 by adorofei          #+#    #+#             */
/*   Updated: 2026/09/12 16:51:57 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>

// # include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef enum s_sort_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
} t_sort_mode;

typedef struct s_grid
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
	float		disorder;
	t_sort_mode	mode;
} t_grid;

/* OPERATIONS */
void	sa(t_grid *push_swap);
void	sb(t_grid *push_swap);
void	ss(t_grid *push_swap);
void	ra(t_grid *push_swap);
void	rb(t_grid *push_swap);
void	rr(t_grid *push_swap);
void	rra(t_grid *push_swap);
void	rrb(t_grid *push_swap);
void	rrr(t_grid *push_swap);
void	pa(t_grid *push_swap);
void	pb(t_grid *push_swap);

/* PARSING FLAGS */
int		is_flag(char *str);
void	indicate_flag(t_grid *push_swap, char *argv);

/* PARSING ARGV */
int	process_values(t_grid *push_swap, char *val_str);
void	parse_args(t_grid *push_swap, int argc, char **argv);

/* HELPER FUNCTIONS */
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		stack_add_back(t_node **stack, t_node *new);
t_node	*stack_new_node(int	new_value);
void	free_stack(t_node **stack);


#endif