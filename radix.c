/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:39:23 by alrobert          #+#    #+#             */
/*   Updated: 2023/06/07 15:46:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"
#include <stddef.h>

void	radix(int *a, int *b, int size)
{
	int 	i;
	int		max;
	int		min;
	size_t	len_max;
	size_t	len_min;

	i = 0;
	max = max_number(a);
	min = lower_number(a);
	len_max = ft_nblen(max);
	len_min = ft_nblen(min);
	display(a, b, "Init a and b", size);
	ft_printf("MAX: %i, LEN: %i, MIN: %i, LEN: %i, SIZE: %i\n", max, len_max, min, len_min, size);
	while (i < 7) {
		if (a[0] % 10 > a[1] % 10)
		{
			ft_printf("last number => %i\n", a[0] % 10);
			rules_swap(a);
		}
		rules_push(b, a);
		display(a, b, "Swap A", size);
		i++;
	}
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
