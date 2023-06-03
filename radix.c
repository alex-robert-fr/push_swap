/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:39:23 by alrobert          #+#    #+#             */
/*   Updated: 2023/04/09 16:39:25 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "rules.h"
#include <stddef.h>

void	radix(int *a, int *b)
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
	display(a, b, "Init a and b");
	ft_printf("MAX: %i, LEN: %i, MIN: %i, LEN: %i\n", max, len_max, min, len_min);
//	while (i > 0)
//	{
//		i = 0;
//	ft_printf("a[%i] = %i, len_max = %i\n", a[i], ft_nblen(a[i]), len_max);
		while (i < 22)
		{
			if (ft_nblen(a[0]) == len_max)
				rules_push(b, a);
			else
				rules_rot(a);
			if (i == 12)
				len_max = ft_nblen(max_number(a));
			i++;
		}
//	}
	display(a, b, "Push");
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
