/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4000_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:15 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:40:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*init_stack(int *tab, int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->tab = tab;
	stack->size = ft_calloc(1, sizeof(int));
	*stack->size = size;
	return (stack);
}

int	calculate_cost(int pos_a, t_stack *a, t_stack *b)
{
	int	count;
	int	rotate_a;
	int	rotate_b;
	int	pos_b;
	int	simultaneous_rotations;

	rotate_a = min(pos_a, *a->size - pos_a);
	if (a->tab[pos_a] > max_number(b) || a->tab[pos_a] < lower_number(b))
		pos_b = find_position(max_number(b), b);
	else
		pos_b = find_intern_position(a->tab[pos_a], b);
	rotate_b = min(pos_b, *b->size - pos_b);
	count = rotate_a + rotate_b + 1;
	simultaneous_rotations = min(rotate_a, rotate_b);
	count -= simultaneous_rotations;
	return (count);
}
