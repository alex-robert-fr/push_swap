/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:47:34 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 11:50:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void	algo5(int *a, int *b)
{
	int	i;
	int	top_number;

	ft_printf("ALGO5\n");
	i = 1;
	rules_push(b, a, "pb");	
	rules_push(b, a, "pb");	
	algo3(a, b);
	rules_push(a, b, "pa");
	top_number = a[0];
	display(a, b, "Before", 5);
	while (i < 5) {
		ft_printf("%i: top: %i > a[i]: %i\n", i, top_number, a[i]);
		if (top_number > a[1])
		{
			rules_swap(a, "sa");
			rules_rot(a, "ra");
			display(a, b, "Pass", 5);
		}
		else
			break ;
		i++;
	}
	while (i > 1) {
		rules_reverse_rot(a, "rra");
		i--;
	}
	rules_push(a, b, "pa");
	top_number = a[0];
	while (i < 5) {
		ft_printf("%i: top: %i > a[i]: %i\n", i, top_number, a[i]);
		if (top_number > a[1])
		{
			rules_swap(a, "sa");
			rules_rot(a, "ra");
			display(a, b, "Pass", 5);
		}
		else
			break ;
		i++;
	}
	while (i > 1) {
		rules_reverse_rot(a, "rra");
		i--;
	}
	ft_printf("I: %i", i);
}
