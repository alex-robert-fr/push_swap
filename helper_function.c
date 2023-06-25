/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:34:30 by alex              #+#    #+#             */
/*   Updated: 2023/06/22 16:38:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	check_length_and_validity(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (!len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!is_valid_number(str + i))
			return (0);
		while (ft_isdigit(str[i]) || ft_find_char(str[i], "-+"))
			i++;
		if (str[i] == ' ')
			i++;
	}
	return (1);
}
