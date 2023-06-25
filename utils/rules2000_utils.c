/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:47:29 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:47:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules2000.h"
#include "ft_printf.h"

void	rotate(int *stack, int size)
{
	int	i;
	int	tmp;

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
	if (!isTest)
		ft_printf("rrr\n");
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
}

void	reverse_rotate_a(t_stack *a, int isTest)
{
	if (!isTest)
		ft_printf("rra\n");
	reverse_rotate(a->tab, *a->size);
}

void	reverse_rotate_b(t_stack *b, int isTest)
{
	if (!isTest)
		ft_printf("rrb\n");
	reverse_rotate(b->tab, *b->size);
}

void	reverse_rotate(int *stack, int size)
{
	int	i;
	int	tmp;

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
