/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:15:46 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:46:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	free_memory(int **tmp, t_stack *a, t_stack *b, int *size)
{
	free_tmp(tmp);
	free(size);
	free(a->size);
	free(a);
	free(b->size);
	free(b);
}

static void	run_algorithm(t_stack *a, t_stack *b, int *size)
{
	if (*size == 2)
		algo2(a);
	else if (*size == 3)
		algo3(a, b);
	else if (*size <= 5)
		algo5(a, b);
	else
		algo4000(a, b, size);
}

static void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	*tmp_init(int argc, char *argv[])
{
	int		**tmp;

	tmp = NULL;
	if (argc == 2)
	{
		if (!check_is_valid(argv, 0))
			print_error_and_exit();
		tmp = init_tab(argv, 0);
	}
	else if (argc > 2)
	{
		if (!check_is_valid(argv, 1))
			print_error_and_exit();
		tmp = init_tab(argv, 1);
	}
	else
		print_error_and_exit();
	if (!tmp || tmp[2][0] < 2)
	{
		if (tmp)
			free_tmp(tmp);
		exit(1);
	}
	return (tmp);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		**tmp;
	int		*size;

	tmp = tmp_init(argc, argv);
	size = ft_calloc(1, sizeof(int));
	*size = tmp[2][0];
	a = init_stack(tmp[0], *size);
	b = init_stack(tmp[1], 0);
	if (check_array(a->tab, *size) == 1)
		ft_putstr_fd("Error\n", 2);
	if (check_array(a->tab, *size))
	{
		if (tmp)
			free_memory(tmp, a, b, size);
		return (1);
	}
	run_algorithm(a, b, size);
	free_memory(tmp, a, b, size);
	return (0);
}
