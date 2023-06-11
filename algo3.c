/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:09:19 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 11:57:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void	algo3(int *a, int *b)
{
	(void)b;
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
	{
		rules_swap(a, "sa");
	}
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		rules_swap(a, "sa");
		rules_reverse_rot(a, "rra");
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
	{
		rules_rot(a, "ra");
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		rules_swap(a, "sa");
		rules_rot(a, "ra");
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		rules_reverse_rot(a, "rra");
	}
}
