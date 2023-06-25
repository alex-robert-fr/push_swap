/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:42:48 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:43:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
