/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:44:13 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 14:37:21 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
		if (!is_valid_number(argv[i], 1))
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
		if (!is_valid_number(argv + i, 0))
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

int	is_valid_number(char *num, int is_multi)
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
	if (!is_valid(num, is_multi))
		return (0);
	return (1);
}

void	free_tmp(int **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}
