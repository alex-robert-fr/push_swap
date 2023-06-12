/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:53:25 by alex              #+#    #+#             */
/*   Updated: 2023/06/12 13:40:24 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"
void	algo3000(int *a, int *b, int size)
{
	int	i;
	int	split;
	int	max_num;

	(void)a;
	(void)b;
	split = size / 2;
	max_num = max_number(a, size);
	ft_printf("\x1b[36mSPLIT\x1b[0m: %i\n", split);
	ft_printf("\x1b[36mMAX\x1b[0m: %i\n", max_num);
	display(a, b, "Init", size);
	i = 0;
	while (i < split) {
		if (a[0] == max_num)
		{
			rules_rot(a, size - i, "ra");
			rules_push(b, a, size, "pb");
		}
		else
			rules_push(b, a, size, "pb");
		i++;
	}
	display(a, b, "Push B", size);
	//if (size % 2 == 1)
	//	split++;
	//ft_printf("\x1b[36mSPLIT\x1b[0m: %i\n", split);
	i = 0;
	while (i < size)
	{
		ft_printf("%i < %i ?\n", a[0], b[0]);
		if (a[0] < b[0])
		{
			ft_printf("PASS");
			rules_push(a, b, size, "pa");
			//display(a, b, "IN WHILE PA", size);

			rules_rot(a, size - i, "ra");
			//display(a, b, "IN WHILE RA", size);
			
			rules_push(b, a, size, "pb");
			//display(a, b, "IN WHILE PB", size);

			rules_rot(b, size - i, "rb");
			//display(a, b, "IN WHILE RB", size);
		}
		else
			rules_rot_all(a, b, size - i);
		i++;
		display(a, b, "IN WHILE", size);
	}
	display(a, b, "First sort", size);
}
