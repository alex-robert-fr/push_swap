/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:47:34 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 12:33:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void	algo5(int *a, int *b)
{
	int		i;
	int		top_number;
	t_info	info;
	t_info	info_current;

	i = 1;
	info.min_number = lower_number(a);
	info.max_number = max_number(a);
	ft_printf("MIN: %i, MAX: %i\n", info.min_number, info.max_number);
	display(a, b, "Before", 5);
	rules_push(b, a, "pb");	
	rules_push(b, a, "pb");	
	display(a, b, "Push", 5);
	algo3(a, b);
	display(a, b, "Algo 3", 5);
	while (b[0] != 0) {
		rules_push(a, b, "pa");
		info_current.min_number = lower_number(a);
		info_current.max_number = max_number(a);
		display(a, b, "Push to A", 5);
		if (a[0] == info_current.max_number)
		{
			rules_rot(a, "ra");
			display(a, b, "Rotation", 5);
			continue ;
		}
		top_number = a[0];
		while (i < 5) {
			display(a, b, "Sort 5", 5);
			if (top_number > a[1])
			{
				rules_swap(a, "sa");
				rules_rot(a, "ra");
			}
			else
				break ;
			i++;
		}
		display(a, b, "After Sort 5", 5);
		while (i > 1) {
			rules_reverse_rot(a, "rra");
			i--;
			display(a, b, "Reverse sort", 5);
		}
			display(a, b, "After Reverse sort", 5);
	}
	/*
	rules_push(a, b, "pa");
	top_number = a[0];
	while (i < 5) {
		if (top_number > a[1])
		{
			rules_swap(a, "sa");
			rules_rot(a, "ra");
		}
		else
			break ;
		i++;
	}
	while (i > 1) {
		rules_reverse_rot(a, "rra");
		i--;
	}
	*/
}

int	max_number(int *a)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (a[i])
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	lower_number(int *a)
{
	int	i;
	int	low;

	i = 0;
	low = a[0];
	while (a[i])
	{
		if (a[i] < low)
			low = a[i];
		i++;
	}
	return (low);
}
