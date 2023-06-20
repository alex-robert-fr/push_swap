/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:03:00 by alex              #+#    #+#             */
/*   Updated: 2023/06/17 14:00:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules2000.h"

void	algo5(t_stack *a, t_stack *b)
{
	int	i;
	int size;
	int	min;

	size = *a->size;
	if (*a->size == 5)
	{
		min = lower_number(a);
		i = find_position(min, a);
		while (i > 0)
		{
			rotate_a(a, 0);
			i--;
		}
		push_b(a, b, 0);

	}
	min = lower_number(a);
	i = find_position(min, a);
	while (i > 0)
	{
		rotate_a(a, 0);
		i--;
	}
	push_b(a, b, 0);
	algo3(a, b);
	i = 0;
//	display(a->tab, b->tab, "Algo 5", size);
	while (i < size - 3)
	{
		//while (a->tab[0] < b->tab[0])
		//{
			//rotate_a(a, 0);
		//}
		push_a(a, b, 0);
		//display(a->tab, b->tab, "Algo 5", size);
		i++;
	}
	/*
	min = lower_number(a);
	min = find_position(min, a);
	//ft_printf("LOW: %i\n", min);
	if (min > size / 2)
	{
		i = 0;
		//ft_printf("Bas\n");
		while (i < size - min)
		{
			reverse_rotate_a(a, 0);
			i++;
		}
	}
	else
	{
		i = min;
		//ft_printf("Haut\n");
		while (i > 0)
		{
			rotate_a(a, 0);
			i--;
		}
	}
	*/
}
