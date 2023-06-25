/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:20:57 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 11:14:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules2000.h"

void	algo3(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] \
			&& a->tab[2] > a->tab[0])
		swap_a(a->tab, 3, 0);
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2] \
			&& a->tab[2] < a->tab[0])
	{
		swap_a(a->tab, 3, 0);
		reverse_rotate_a(a, 0);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] \
			&& a->tab[2] < a->tab[0])
		rotate_a(a, 0);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] \
			&& a->tab[2] > a->tab[0])
	{
		swap_a(a->tab, 3, 0);
		rotate_a(a, 0);
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] \
			&& a->tab[2] < a->tab[0])
		reverse_rotate_a(a, 0);
}
