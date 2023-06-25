/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:15:46 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 11:12:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

static void	free_tmp(int **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

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

int	check_multi_valid(char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		if (!len)
			return (0);
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_single_valid(char *argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(argv);
	if (argv[i] == ' ')
		i++;
	if (!len || i == len)
		return (0);
	while (i < len)
	{
		if (!is_valid_number(argv + i))
			return (0);
		while (ft_isdigit(argv[i]) || ft_find_char(argv[i], "-+"))
			i++;
		if (argv[i] == ' ')
		{
			i++;
			continue ;
		}
		i++;
	}
	return (1);
}

int	check_is_valid(char **argv, int multi)
{
	if (multi)
		return (check_multi_valid(argv));
	else
		return (check_single_valid(argv[1]));
}

int	is_valid_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_find_char(num[i], " +-") && !ft_isdigit(num[i]))
			return (0);
		i++;
	}
	if (!ft_atoi(num))
	{
		i = 0;
		while (num[i])
		{
			if (!ft_find_char(num[i], "0"))
				return (0);
			i++;
		}
	}
	if (!is_valid(num))
		return (0);
	return (1);
}

int	**init_tab(char **str, int is_multi)
{
	int	**tabs;
	int	i;

	tabs = ft_calloc(3, sizeof(int *));
	tabs[2] = ft_calloc(2, sizeof(int));
	if (!is_multi)
	{
		tabs[2][0] = get_size_arg((char *)str[1]);
		if (tabs[2][0] < 2)
			return (tabs);
		tabs[0] = insert_arg_to_array(str[1], tabs[2][0]);
	}
	else
	{
		i = 1;
		while (str[i])
			i++;
		tabs[2][0] = i - 1;
		tabs[0] = ft_calloc(i, sizeof(int));
		i = 0;
		while (str[++i])
			tabs[0][i - 1] = ft_atoi(str[i]);
	}
	tabs[1] = ft_calloc(tabs[2][0] + 1, sizeof(int));
	return (tabs);
}

int	*insert_arg_to_array(char *str, int size)
{
	int	*a;
	int	i;
	int	i_tab;

	a = ft_calloc(size + 1, sizeof(int));
	i = 0;
	i_tab = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!i)
		{
			a[i_tab] = ft_atoi(str + i);
			while (str[i] != ' ')
				i++;
			i_tab++;
		}
		else if ((ft_find_char(str[i - 1], " +-")) && ft_isdigit(str[i]))
			a[i_tab++] = ft_atoi(str + i - 1);
		i++;
	}
	return (a);
}

int	check_array(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size - 1)
		{
			j++;
			if (nums[i] == nums[j])
				return (1);
		}
		i++;
	}
	j = 0;
	while (i < size - 1)
	{
		if (nums[i] < nums[i + 1])
			j++;
		i++;
	}
	if (j == size - 1)
		return (2);
	return (0);
}

int	get_size_arg(char *str)
{
	int	i;
	int	count_num;

	i = 0;
	count_num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && (!i || ft_find_char(str[i - 1], " +-")))
			count_num++;
		if (!ft_find_char(str[i], " +-") && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (count_num);
}

int	is_valid(char *num)
{
	int	i;

	i = 0;
	while (num[i] == ' ')
		i++;
	if (num[i] == '-')
		i++;
	else if (num[i] == '+')
		i++;
	while (num[i] == '0')
		i++;
	while (num[i] && num[i] != ' ')
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}
