/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:58:31 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 16:15:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void algo2000(int *a, int *b, int size)
{
	t_info info;
	int		number_rot;
	int		i;

	info.min_number = lower_number(a, size);
	ft_printf("LOW NUMBER = %i\n", info.min_number);
	display(a, b, "Init", size);
	ft_printf("POSITION NUMBER: %i, TAB_SIZE: %i\n", get_position_number(a, info.min_number, size), size);
	i = 0;
	if (size / 2 >= get_position_number(a, info.min_number, size))
	{
		number_rot = get_position_number(a, info.min_number, size);
		while (i < number_rot)
		{
			rules_rot(a, size, "ra");
			i++;
		}
	}
	else
	{
		number_rot = size - get_position_number(a, info.min_number, size);
		while (i < number_rot)
		{
			rules_reverse_rot(a, "rra");
			i++;
		}
	}
	display(a, b, "Reverse", size);
	rules_push(b, a, size, "pb");
	display(a, b, "Push B", size);
}

int	get_position_number(int *tab, int find, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == find)
			return (i);
		i++;
	}
	return (-1);
}
