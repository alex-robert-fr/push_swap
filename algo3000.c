/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:51:40 by alex              #+#    #+#             */
/*   Updated: 2023/06/13 18:41:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "rules2000.h"

void	algo3000(int *a, int *b, int size)
{
	int *size_a;
	int	*size_b;
	int	i;
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	size_a = ft_calloc(1, sizeof(int));
	size_b = ft_calloc(1, sizeof(int));
	*size_a = size;
	push_b(a, b, size_a, size_b, 0);
	push_b(a, b, size_a, size_b, 0);
	info->max_b = max_number(b, *size_b);
	info->min_b = lower_number(b, *size_b);
	info->min_move = 0;
	info->nb_min_move = a[0];
	i = 0;
	while (i < *size_a)
	{
		info->nb_move = 0;
		ft_printf("--------------INDEX %i------------------\n", i);
		find_cheapest_number(a, b, size_a, size_b, i, info);
		ft_printf("--------------FIN %i--------------------\n", i);
		i++;
	}
}

int	find_cheapest_number(int *a, int *b, int *size_a, int *size_b, int index, t_info *info)
{
	int	*copy_a;
	int	*copy_b;
	int size = 10;
	int *cp_size_a;
	int *cp_size_b;

	cp_size_a = int_copy(*size_a);
	cp_size_b = int_copy(*size_b);
	if (!cp_size_a || !cp_size_b)
	{
		cp_size_a = NULL;
		cp_size_b = NULL;
		return (-1);
	}
	copy_a = tab_copy(a, size);
	copy_b = tab_copy(b, size);
	if (!copy_a || !copy_b)
	{
		copy_a = NULL;
		copy_b = NULL;
		return (-1);
	}
	return (test_move_one_number(copy_a, copy_b, cp_size_a, cp_size_b, index, info));
}

int	test_move_one_number(int *a, int *b, int *size_a, int *size_b, int index, t_info *info)
{
	int	i;
	int	tmp;
	int	find_max;

	i = 0;
	find_max = 0;
	while (i < index)
	{
		rotate_a(a, *size_a, 0);
		info->nb_move++;
		i++;
	}
	ft_printf("MAX IN B: %i\n", info->max_b);
	ft_printf("MIN IN B: %i\n", info->min_b);
	display(a, b, "IN FIND GOOD NUM", 10);
	if(a[0] > info->max_b)
	{
		i = 0;
		ft_printf("Plus grand\n");
		while (i < *size_b / 2)
		{
			if (b[i] == info->max_b)
			{
				ft_printf("MAX TROUVER+\n");
				find_max = 1;
			}
			i++;
		}
		if (!find_max)
		{
			i = *size_b - 1;
			while (i >= (*size_b / 2))
			{
				if (b[i] == info->max_b)
				{
					ft_printf("MAX TROUVER-\n");
					find_max = 1;
					tmp = *size_b - i;
					while (tmp > 0)
					{
						reverse_rotate_b(b, *size_b, 0);
						info->nb_move++;
						tmp--;
					}
					push_b(a, b, size_a, size_b, 0);
					info->nb_move++;
				}
				i--;
			}
		}
	}
	else if(a[0] < info->min_b)
		ft_printf("Plus petit\n");
	else
	{
		i = 0;
		ft_printf("Ni l'un ni l'autre\n");
		ft_printf("GET MIDDLE SIZE: %i\n", *size_b / 2);
		while (i < *size_b / 2)
		{
			if (a[0] < b[i])
				ft_printf("PUSH+\n");
			ft_printf("TEST+: %i\n", b[i]);
			i++;
		}
		i = *size_b - 1;
		while (i >= (*size_b / 2))
		{
			if (a[0] < b[i])
			{
				tmp = *size_b - i;
				ft_printf("PUSH- i=%i nb de reverse rotate = %i\n", i, tmp);
				while (tmp > 0)
				{
					reverse_rotate_b(b, *size_b, 0);	
					info->nb_move++;
					tmp--;
				}
				push_b(a, b, size_a, size_b, 0);
				info->nb_move++;
			}
			ft_printf("TEST-: %i\n", b[i]);
			i--;
		}
	}
	if (info->nb_move < info->min_move || !info->min_move)
	{
		info->min_move = info->nb_move;
		info->nb_min_move = index;
	}
	ft_printf("nb_move: %i, min_move: %i, nb_min_move: %i\n", info->nb_move, info->min_move, info->nb_min_move);
	display(a, b, "IN FIND GOOD NUM", 10);
	(void)a;
	(void)size_a;
	return (0);
}

int	*tab_copy(int *original, int size)
{
	int	i;
	int	*copy;

	copy = ft_calloc(size, sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = original[i];
		i++;
	}
	return (copy);
}

int	*int_copy(int original)
{
	int	*copy;

	copy = ft_calloc(1, sizeof(int));
	*copy = original;
	return (copy);
}

int	max_number(int *tab, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	lower_number(int *tab, int size)
{
	int	i;
	int	low;

	i = 0;
	low = tab[0];
	while (i < size)
	{
		if (tab[i] < low)
			low = tab[i];
		i++;
	}
	return (low);
}
