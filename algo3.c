/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:09:19 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 16:34:45 by alex             ###   ########.fr       */
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
		rules_swap(a, 3, "sa");
	}
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		rules_swap(a, 3, "sa");
		rules_reverse_rot(a, 3, "rra");
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
	{
		rules_rot(a, 3, "ra");
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		rules_swap(a, 3, "sa");
		rules_rot(a, 3, "ra");
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		rules_reverse_rot(a, 3, "rra");
	}
}
