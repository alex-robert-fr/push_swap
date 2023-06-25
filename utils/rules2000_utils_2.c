/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:48:59 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:49:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules2000.h"
#include "ft_printf.h"

void	push_b(t_stack *a, t_stack *b, int isTest)
{
	if (!isTest)
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
	if (!isTest)
		ft_printf("rr\n");
	rotate_a(a, 1);
	rotate_b(b, 1);
}

void	rotate_a(t_stack *a, int isTest)
{
	if (!isTest)
		ft_printf("ra\n");
	rotate(a->tab, *a->size);
}

void	rotate_b(t_stack *b, int isTest)
{
	if (!isTest)
		ft_printf("rb\n");
	rotate(b->tab, *b->size);
}
