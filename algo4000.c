/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:45 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 14:20:55 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "rules2000.h"
#include <stdlib.h>

static void	move_cheapest_elements(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	cheapest_num;

	i = 0;
	while (i < size - 2)
	{
		cheapest_num = find_cheapest_num(a, b);
		move_element(a, b, cheapest_num);
		i++;
	}
}

void	algo4000(t_stack *a, t_stack *b, int *size)
{
	int		i;
	int		max_pos;

	push_b(a, b, 0);
	push_b(a, b, 0);
	move_cheapest_elements(a, b, *size);
	i = 0;
	max_pos = find_position(max_number(b), b);
	if (max_pos < *b->size - max_pos)
		while (i++ < max_pos)
			rotate_b(b, 0);
	else
	{
		while (i < *b->size - max_pos)
		{
			reverse_rotate_b(b, 0);
			i++;
		}
	}
	i = 0;
	while (i < *size)
	{
		push_a(a, b, 0);
		i++;
	}
}

void	init_rotation_data(t_rotation_data *data, int pos_a, int pos_b, int rot_a, int rot_b)
{
	data->pos_a = &pos_a;
	data->pos_b = &pos_b;
	data->rot_a = &rot_a;
	data->rot_b = &rot_b;
}

t_rotation_data	*init_move_element(t_stack *a, t_stack *b, int cheapest_num)
{
	int				pos_a;
	int				pos_b;
	int				rot_a;
	int				rot_b;
	t_rotation_data	*rotation_data;

	rotation_data = ft_calloc(1, sizeof(t_rotation_data));
	pos_a = find_position(cheapest_num, a);
	pos_b = find_position_for_move(a, b, pos_a);
	rot_a = min(pos_a, *a->size);
	rot_b = min(pos_b, *b->size);
	init_rotation_data(rotation_data ,pos_a, pos_b, rot_a, rot_b);
	return (rotation_data);
}

void	move_element(t_stack *a, t_stack *b, int cheapest_num)
{
	int				min_rot;
	int				pos_a;
	int				pos_b;
	int				i;
	t_rotation_data	*rotation_data;

	pos_a = find_position(cheapest_num, a);
	pos_b = find_position_for_move(a, b, pos_a);
	min_rot = min(min(pos_a, *a->size), \
			min(pos_b, *b->size));
	i = 0;
	rotation_data = init_move_element(a, b, cheapest_num);
	rotation_data->a = a;
	rotation_data->b = b;
	while (i < min_rot)
	{
		perform_rotation(rotation_data);
		i++;
	}
	rotate_a_to_position(a, pos_a);
	rotate_b_to_position(b, pos_b);
	push_b(a, b, 0);
}
