/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:44:03 by alex              #+#    #+#             */
/*   Updated: 2023/06/13 14:23:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules2000.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	swap_ab(int *a, int *b, int size, int isTest)
{
	swap_a(a, size, isTest);
	swap_b(b, size, isTest);
}

void	swap_a(int *a, int size, int isTest)
{
	if(!isTest)
		ft_printf("sa\n");
	swap(a, size);
}

void	swap_b(int *b, int size, int isTest)
{
	if(!isTest)
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

void	push_a(int *a, int *b, int *size_a, int *size_b, int isTest)
{
	if(!isTest)
		ft_printf("pa\n");
	push(b, a, size_b, size_a);
}

void	push_b(int *a, int *b, int *size_a, int *size_b, int isTest)
{
	if(!isTest)
		ft_printf("pb\n");
	push(a, b, size_a, size_b);
}

void	push(int *start, int *end, int *size_start, int *size_end)
{
	int	i;

	if (*size_start < 1)
		return ;
	i = *size_end;
	while (i > 0)
	{
		end[i] = end[i - 1];
		i--;
	}
	end[0] = start[0];
	i = 0;
	while (i < *size_start)
	{
		start[i] = start[i + 1];
		i++;
	}
	(*size_end)++;
	(*size_start)--;
}

void	rotate_ab(int *a, int *b, int size_a, int size_b, int isTest)
{
	if(!isTest)
		ft_printf("rr\n");
	rotate_a(a, size_a, isTest);
	rotate_b(b, size_b, isTest);
}
void	rotate_a(int *a, int size, int isTest)
{
	if(!isTest)
		ft_printf("ra\n");
	rotate(a, size);
}

void	rotate_b(int *b, int size, int isTest)
{
	if(!isTest)
		ft_printf("rb\n");
	rotate(b, size);
}

void	rotate(int *stack, int size)
{
	int	i;
	int tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

void	reverse_rotate_ab(int *a, int *b, int size_a, int size_b, int isTest)
{
	if(!isTest)
		ft_printf("rrr\n");
	reverse_rotate(a, size_a);
	reverse_rotate(b, size_b);
}

void	reverse_rotate_a(int *a, int size, int isTest)
{
	if(!isTest)
		ft_printf("rra\n");
	reverse_rotate(a, size);
}

void	reverse_rotate_b(int *b, int size, int isTest)
{
	if(!isTest)
		ft_printf("rrb\n");
	reverse_rotate(b, size);
}

void	reverse_rotate(int *stack, int size)
{
	int	i;
	int tmp;

	if (size < 2)
		return ;
	tmp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}
