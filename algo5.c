/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:03:00 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 11:31:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules2000.h"

static void	move_min_to_top(t_stack *a)
{
	int	i;
	int	min;

	min = lower_number(a);
	i = find_position(min, a);
	while (i > 0)
	{
		rotate_a(a, 0);
		i--;
	}
}

void	algo5(t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	size = *a->size;
	if (*a->size == 5)
	{
		move_min_to_top(a);
		push_b(a, b, 0);
	}
	move_min_to_top(a);
	push_b(a, b, 0);
	algo3(a, b);
	i = 0;
	while (i < size - 3)
	{
		push_a(a, b, 0);
		i++;
	}
}
