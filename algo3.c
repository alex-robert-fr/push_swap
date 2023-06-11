/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:09:19 by alex              #+#    #+#             */
/*   Updated: 2023/06/11 10:41:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

void	algo3(int *a, int *b)
{
	ft_printf("ALGO3: 0:%i 1:%i 2:%i\n", a[0], a[1], a[2]);
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
	{
		ft_printf("ALGO3 n1\n");
		rules_swap(a);
		display(a, b, "yo1", 3);
	}
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_printf("ALGO3 n2\n");
		rules_swap(a);
		rules_reverse_rot(a);
		display(a, b, "yo2", 3);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
	{
		ft_printf("ALGO3 n3\n");
		rules_rot(a);
		display(a, b, "yo3", 3);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		ft_printf("ALGO3 n4\n");
		rules_swap(a);
		rules_rot(a);
		display(a, b, "yo4", 3);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_printf("ALGO3 n5\n");
		rules_reverse_rot(a);
		display(a, b, "yo4", 3);
	}
}
