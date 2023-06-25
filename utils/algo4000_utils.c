/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4000_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:32:57 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 14:11:48 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules2000.h"

void	perform_rotation(t_rotation_data *data)
{
	if (!data)
		return ;
	if (*(data->pos_a) < *(data->a->size) - *(data->pos_a) && \
			*(data->pos_b) < *(data->b->size) - *(data->pos_b))
	{
		rotate_ab(data->a, data->b, 0);
		(*(data->pos_a))--;
		(*(data->pos_b))--;
		(*(data->rot_a))--;
		(*(data->rot_b))--;
	}
	else if (*(data->pos_a) >= *(data->a->size) - *(data->pos_a) && \
			*(data->pos_b) >= *(data->b->size) - *(data->pos_b))
	{
		reverse_rotate_ab(data->a, data->b, 0);
		(*(data->pos_a))++;
		(*(data->pos_b))++;
		(*(data->rot_a))--;
		(*(data->rot_b))--;
	}
}

void	rotate_a_to_position(t_stack *a, int pos_a)
{
	int	i_a;

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
}

void	rotate_b_to_position(t_stack *b, int pos_b)
{
	int	i_b;

	i_b = 0;
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
}

int	find_cheapest_num(t_stack *a, t_stack *b)
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
	}
	return (cheapest_num);
}

int	find_position_for_move(t_stack *a, t_stack *b, int pos_a)
{
	if (a->tab[pos_a] > max_number(b) || a->tab[pos_a] < lower_number(b))
		return (find_position(max_number(b), b));
	else
		return (find_intern_position(a->tab[pos_a], b));
}
