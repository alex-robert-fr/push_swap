/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:45 by alex              #+#    #+#             */
/*   Updated: 2023/06/16 10:33:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "rules2000.h"
#include <stdlib.h>

void	algo4000(t_stack *a, t_stack *b, int *size)
{
	int		isTest = 0;
	int		cheapest_num;
	int		i;
	int		max_pos;

	push_b(a, b, isTest);
	push_b(a, b, isTest);
//	display(a->tab, b->tab, "push", *size);
	i = 0;
	while (i < *size - 2) {
//		ft_printf("------------------------------------------------------------------\n");
		cheapest_num = find_cheapest_num(a, b);
//		ft_printf("Cheapest Num = %i\n", cheapest_num);
		move_element(a, b, cheapest_num);
//		display(a->tab, b->tab, "", *size);
//		ft_printf("------------------------------------------------------------------\n");
		i++;
	}
	i = 0;
	max_pos = find_position(max_number(b), b);
//	ft_printf("MAX: %i, TOPB: %i\n", max_number(b), b->tab[0]);
//	ft_printf("POS: %i\n", max_pos);
	if (max_pos < *b->size - max_pos)
	{
		while (i < max_pos)
		{
			rotate_b(b, isTest);
			i++;
		}
	}
	else
	{
		while (i < *b->size - max_pos)
		{
			reverse_rotate_b(b, isTest);
			i++;
		}
	}
	i = 0;
	while (i < *size)
	{
		push_a(a, b, isTest);
		i++;
	}
}

t_stack	*init_stack(int *tab, int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->tab = tab;
	stack->size = ft_calloc(1, sizeof(int));
	*stack->size = size;
	return (stack);
}

int		find_cheapest_num(t_stack *a, t_stack *b)
{
	int	cheapest_num;
	int	min_cost;
	int	cost;
	int	i;
	
	min_cost = INT_MAX;
	i = 0;
	while (i < *a->size)
	{
		cost = calculate_cost(i, a, b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_num = a->tab[i];
		}
		i++;
//		ft_printf("COST IS %i\n\n\n", cost);
	}
	return (cheapest_num);
}

void	move_element(t_stack *a, t_stack *b, int cheapest_num)
{
	int	pos_a;
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	i_a;
	int	i_b;
	int	i;
	int	min_rot;

//	ft_printf("---------------------------------------------------------------\n");
	// NB ROTATION A
	pos_a = find_position(cheapest_num, a);
//	ft_printf("NUMBER: %i\n", a->tab[pos_a]);
	rot_a = min(pos_a, *a->size - pos_a);
//	ft_printf("A ROTATE: %i\n", rot_a);
	if(a->tab[pos_a] > max_number(b) || a->tab[pos_a] < lower_number(b))
	{
		pos_b = find_position(max_number(b), b);
//		ft_printf("Find pos: %i\n", pos_b);
	}
	else
	{
		pos_b = find_intern_position(a->tab[pos_a], b);
//		ft_printf("Find internal pos: %i\n", pos_b);
	}
	rot_b = min(pos_b, *b->size - pos_b);
	min_rot = min(rot_a, rot_b);
	i = 0;
	while (i < min_rot)
	{
	//	ft_printf("DOUBLE ROT x%i, ROTA: %i ROTB: %i\n", min_rot, rot_a, rot_b);
	//	ft_printf("NUM IS %i\n", cheapest_num);
	//	display(a->tab, b->tab, "DOUBLE ROT", 10);
		if (pos_a < *a->size - pos_a && pos_b < *b->size - pos_b)
		{
	//		ft_printf("ROTATE\n");
			rotate_ab(a, b, 0);
			pos_a = pos_a - 1;  // adjust positions
			pos_b = pos_b - 1;
			rot_a--;
			rot_b--;
		}
		else if (pos_a >= *a->size - pos_a && pos_b >= *b->size - pos_b)
		{
	//		ft_printf("REVERSE ROTATE x%i\n", min_rot);
			reverse_rotate_ab(a, b, 0);
			pos_a = pos_a + 1;  // adjust positions
			pos_b = pos_b + 1;
			rot_a--;
			rot_b--;
		}
		i++;
	}

	i_a = 0;
	if (pos_a < *a->size - pos_a)
	{
		while (i_a < pos_a)
		{
			rotate_a(a, 0);
			i_a++;
		}
	}
	else
	{
		while (i_a < *a->size - pos_a)
		{
			reverse_rotate_a(a, 0);
			i_a++;
		}
	}
	

	i_b = 0;
//	ft_printf("POSB %i , SIZEPOSB %i SIZE %i\n", pos_b, *b->size - pos_b, *b->size);
	if (pos_b < *b->size - pos_b)
	{
		while (i_b < pos_b)
		{
			rotate_b(b, 0);
			i_b++;
		}
	}
	else
	{
		while (i_b < *b->size - pos_b)
		{
			reverse_rotate_b(b, 0);
			i_b++;
		}
	}


	push_b(a, b, 0);
//	ft_printf("---------------------------------------------------------------\n");
}

int		calculate_cost(int pos_a, t_stack *a, t_stack *b)
{
	int	count;
	int	rotate_a;
	int	rotate_b;
	int pos_b;
	int	simultaneous_rotations;

//	ft_printf("NUMBER: %i\n", a->tab[pos_a]);
	rotate_a = min(pos_a, *a->size - pos_a);
//	ft_printf("A ROTATE: %i\n", rotate_a);
	if(a->tab[pos_a] > max_number(b) || a->tab[pos_a] < lower_number(b))
	{
		pos_b = find_position(max_number(b), b);
//		ft_printf("Find pos: %i\n", pos_b);
	}
	else
	{
		pos_b = find_intern_position(a->tab[pos_a], b);
//		ft_printf("Find internal pos: %i\n", pos_b);
	}
	rotate_b = min(pos_b, *b->size - pos_b);
//	ft_printf("B ROTATE: %i\n", rotate_b);
	count = rotate_a + rotate_b + 1;
	simultaneous_rotations = min(rotate_a, rotate_b);
	count -= simultaneous_rotations;
//	ft_printf("SIM ROTATE: %i\n", simultaneous_rotations);
	return (count);
}
/*
t_info	*init_info(t_stack *a, t_stack *b, int size_b)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	info->max_b = max_number(b->tab, size_b);
	info->min_b = lower_number(b->tab, size_b);
	info->min_move = 0;
	info->index_min_move = a[0];
	return (info);
}
*/
