/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:58:31 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 17:56:22 by alex             ###   ########.fr       */
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
	int		i_global;
	int		a_size;

	i_global = 0;
	a_size = size;
	while (i_global < size)
	{
		info.min_number = lower_number(a, a_size);
		display(a, b, "Init", size);
		ft_printf("LOW NUMBER = %i\n", info.min_number);
		ft_printf("POSITION NUMBER: %i, TAB_SIZE: %i\n", get_position_number(a, info.min_number, size), size);
		i = 0;
		if (size / 2 >= get_position_number(a, info.min_number, size))
		{
			number_rot = get_position_number(a, info.min_number, size);
			while (i < number_rot)
			{
				rules_rot(a, a_size, "ra");
				i++;
			}
		}
		else
		{
			number_rot = a_size - get_position_number(a, info.min_number, size);
			while (i < number_rot)
			{
				rules_reverse_rot(a, a_size, "rra");
				display(a, b, "LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", size);
				i++;
			}
		}
		display(a, b, "Reverse", size);
		rules_push(b, a, a_size, "pb");
		display(a, b, "Push B", size);
		a_size--;
		i_global++;
	}
	i = 0;
	while (i < size)
	{
		rules_push(a, b, size, "pa");
		display(a, b, "push to A", size);
		i++;
	}
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
