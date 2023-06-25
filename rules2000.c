/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:44:03 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:49:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules2000.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	swap_ab(int *a, int *b, int size, int isTest)
{
	if (!isTest)
		ft_printf("ss\n");
	swap_a(a, size, 1);
	swap_b(b, size, 1);
}

void	swap_a(int *a, int size, int isTest)
{
	if (!isTest)
		ft_putstr_fd("sa\n", 1);
	swap(a, size);
}

void	swap_b(int *b, int size, int isTest)
{
	if (!isTest)
		ft_printf("sb\n");
	swap(b, size);
}

void	swap(int *tab, int size)
{
	if (size < 2)
		return ;
	tab[1] = tab[0] + tab[1];
	tab[0] = tab[1] - tab[0];
	tab[1] = tab[1] - tab[0];
}

void	push_a(t_stack *a, t_stack *b, int isTest)
{
	if (!isTest)
		ft_printf("pa\n");
	push(b->tab, a->tab, b->size, a->size);
}
