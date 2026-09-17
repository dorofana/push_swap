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
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_grid
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	float	disorder;
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

#endif