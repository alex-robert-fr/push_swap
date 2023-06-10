/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:13:27 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 17:26:48 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

void	header(char *str)
{
	ft_printf("\n--------------------------------\n");
	ft_printf("%s\n", str);
	ft_printf("--------------------------------\n");
}

void	test(int condition, char *str)
{
	if (condition)
	{
		ft_printf("\033[1m\033[38;2;185;231;28m[ OK ]\033[0m : %s\033[22m\n", str);
	}
	else
	{
		ft_printf("\033[91m[ KO ] : %s\033[0m\n", str);
	}
}
