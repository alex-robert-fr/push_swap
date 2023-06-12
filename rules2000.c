/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:44:03 by alex              #+#    #+#             */
/*   Updated: 2023/06/12 14:14:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	swap_a(int *a, int size)
{
	ft_printf("sa\n");
	if (size > 1)
	{
		a[1] = a[0] + a[1];
		a[0] = a[1] - a[0];
		a[1] = a[1] - a[0];
	}
}

void	swap_b(int *b, int size)
{
	ft_printf("sb\n");
	if (size > 1)
	{
		b[1] = b[0] + b[1];
		b[0] = b[1] - b[0];
		b[1] = b[1] - b[0];
	}
}

void	swap_ab(int *a, int *b, int size)
{
	swap_a(a, size);
	swap_b(b, size);
}
