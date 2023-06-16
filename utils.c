/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:13:54 by alex              #+#    #+#             */
/*   Updated: 2023/06/16 14:00:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max_number(t_stack *tab)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < *tab->size)
	{
		if (tab->tab[i] > max)
			max = tab->tab[i];
		i++;
	}
	return (max);
}

int		lower_number(t_stack *tab)
{
	int	i;
	int	low;

	i = 0;
	low = tab->tab[0];
	while (i < *tab->size)
	{
		if (tab->tab[i] < low)
			low = tab->tab[i];
		i++;
	}
	return (low);
}

int find_position(int num, t_stack *tab) {
	int	i;

	i = 0;
    while(i < *tab->size) {
        if (tab->tab[i] == num) {
            return (i);
        }
		i++;
    }
	return (-1);
}

int find_intern_position(int num, t_stack *tab) {
    int pos;

	pos = 0;
//	ft_printf("----------------------------------------\n");
    while(pos < *tab->size) {
        if(tab->tab[pos] > num && tab->tab[(pos+1) % *tab->size] < num) {
            return pos + 1;
        }
		pos++;
    }
    return *tab->size;
}
