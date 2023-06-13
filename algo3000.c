/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:51:40 by alex              #+#    #+#             */
/*   Updated: 2023/06/13 14:26:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "rules2000.h"

void	algo3000(int *a, int *b, int size)
{
	int *size_a;
	int	*size_b;

	size_a = ft_calloc(1, sizeof(int));
	size_b = ft_calloc(1, sizeof(int));
	*size_a = size;
	push_b(a, b, size_a, size_b, 0);
	push_b(a, b, size_a, size_b, 0);
	push_b(a, b, size_a, size_b, 0);
	push_b(a, b, size_a, size_b, 0);
	push_b(a, b, size_a, size_b, 0);
	find_cheapest_number(a, b, size_a, size_b);
}

int	find_cheapest_number(int *a, int *b, int *size_a, int *size_b)
{
	int	*copy_a;
	int	*copy_b;
	int size = 10;
	int *cp_size_a;
	int *cp_size_b;

	cp_size_a = int_copy(*size_a);
	cp_size_b = int_copy(*size_b);
	ft_printf("COPY SIZE A: %i\n", *cp_size_a);
	ft_printf("COPY SIZE B: %i\n", *cp_size_b);
	copy_a = tab_copy(a, size);
	copy_b = tab_copy(b, size);
	push_b(copy_a, copy_b, cp_size_a, cp_size_b, 1);
	display(copy_a, copy_b, "Cheapest Number COPY", size);
	return (0);
}

int	*tab_copy(int *original, int size)
{
	int	i;
	int	*copy;

	copy = ft_calloc(size, sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = original[i];
		i++;
	}
	return (copy);
}

int	*int_copy(int original)
{
	int	*copy;

	copy = ft_calloc(1, sizeof(int));
	*copy = original;
	return (copy);
}
