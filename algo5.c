/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:47:34 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 15:55:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void	algo5(int *a, int *b, int size)
{
	int		i;
	int		top_number;
	t_info	info;
	t_info	info_current;

	i = 1;
	info.min_number = lower_number(a, size);
	info.max_number = max_number(a, size);
	ft_printf("MIN: %i, MAX: %i\n", info.min_number, info.max_number);
	display(a, b, "Before", size);
	rules_push(b, a, size, "pb");	
	rules_push(b, a, size, "pb");	
	display(a, b, "Push", size);
	algo3(a, b);
	display(a, b, "Algo 3", size);
	while (b[0] != 0) {
		rules_push(a, b, size, "pa");
		info_current.min_number = lower_number(a, size);
		info_current.max_number = max_number(a, size);
		display(a, b, "Push to A", size);
		if (a[0] == info_current.max_number)
		{
			rules_rot(a, size, "ra");
			display(a, b, "Rotation", size);
			continue ;
		}
		top_number = a[0];
		while (i < 5) {
			display(a, b, "Sort 5", size);
			if (top_number > a[1])
			{
				rules_swap(a, size, "sa");
				rules_rot(a, size, "ra");
			}
			else
				break ;
			i++;
		}
		display(a, b, "After Sort 5", size);
		while (i > 1) {
			rules_reverse_rot(a, "rra");
			i--;
			display(a, b, "Reverse sort", size);
		}
			display(a, b, "After Reverse sort", size);
	}
}

int	max_number(int *a, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	lower_number(int *a, int size)
{
	int	i;
	int	low;

	i = 0;
	low = a[0];
	while (i < size)
	{
		if (a[i] < low)
			low = a[i];
		i++;
	}
	return (low);
}
