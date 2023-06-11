#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

// PASS
int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	size;
	int	**tmp;

	if (argc == 2)
		tmp = init_tab(argv[1]);
	else
		return (1);
	a = tmp[0];
	b = tmp[1];
	size = tmp[2][0];
	if (size == 3)
		algo3(a, b);
	else
		algo5(a, b, size);
	/*
	if (check_array(tmp[0]))
	{
		ft_printf("Error\n");
		free(a);
		free(b);
		free(tmp);
		return (0);
	}
	radix(a, b, size);
	*/
	free(a);
	free(b);
	free(tmp);
	return (0);
}

// PASS
int	**init_tab(void *str)
{
	int	**tabs;
	
	tabs = ft_calloc(3, sizeof(int*));
	tabs[2] = ft_calloc(2, sizeof(int));
	tabs[2][0] = get_size_arg((char*)str);
	tabs[0] = insert_arg_to_array((char*)str, tabs[2][0]);
	tabs[1] = ft_calloc(tabs[2][0] + 1, sizeof(int));
	return (tabs);
}

// PASS
int	get_size_arg(char *str)
{
	int	i;
	int	count_num;

	i = 0;
	count_num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && (!i || ft_find_char(str[i-1], " +-")))
			count_num++;
		if (!ft_find_char(str[i], " +-") && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (count_num);
}

// PASS
int	*insert_arg_to_array(char *str, int	size)
{
	int	*a;
	int	i;
	int	i_tab;

	a = ft_calloc(size + 1, sizeof(int));
	i = 0;
	i_tab = 0;
	while (str[i])
	{
		if ((!i || ft_find_char(str[i-1], " +-")) && ft_isdigit(str[i]))
		{
			a[i_tab] = ft_atoi(str + i);
			i_tab++;
		}
		i++;
	}
	return (a);
}

int	check_array(int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i;
		while (nums[j])
		{
			j++;
			if (nums[i] == nums[j])
				return (1);
		}
		i++;
	}
	return (0);
}


int	get_size_array(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
