/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:44:03 by alex              #+#    #+#             */
/*   Updated: 2023/06/16 15:59:23 by alex             ###   ########.fr       */
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
	if(!isTest)
		ft_putstr_fd("sa\n", 1);
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

void	push_a(t_stack *a, t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("pa\n");
	push(b->tab, a->tab, b->size, a->size);
}

void	push_b(t_stack *a, t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("pb\n");
	push(a->tab, b->tab, a->size, b->size);
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

void	rotate_ab(t_stack *a, t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("rr\n");
	rotate_a(a, 1);
	rotate_b(b, 1);
}
void	rotate_a(t_stack *a, int isTest)
{
	if(!isTest)
		ft_printf("ra\n");
	rotate(a->tab, *a->size);
}

void	rotate_b(t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("rb\n");
	rotate(b->tab, *b->size);
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

void	reverse_rotate_ab(t_stack *a, t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("rrr\n");
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
}

void	reverse_rotate_a(t_stack *a, int isTest)
{
	if(!isTest)
		ft_printf("rra\n");
	reverse_rotate(a->tab, *a->size);
}

void	reverse_rotate_b(t_stack *b, int isTest)
{
	if(!isTest)
		ft_printf("rrb\n");
	reverse_rotate(b->tab, *b->size);
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
