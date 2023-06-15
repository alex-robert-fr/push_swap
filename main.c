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
	int	*size;
	int	**tmp;

	if (argc == 2)
		tmp = init_tab(argv, 0);
	else if (argc > 2)
		tmp = init_tab(argv, 1);
	else
		return (1);
	if (!tmp)
	{
		ft_printf("Error\n");
		return (1);
	}
	a = tmp[0];
	b = tmp[1];
	size = ft_calloc(1, sizeof(int));
	*size = tmp[2][0];
	display(a, b, "INIT", *size);
	algo4000(a, b, size);
	display(a, b, "FINAL", *size);
	free(a);
	free(b);
	free(tmp);
	return (0);
}

// PASS
int	**init_tab(char **str, int is_multi)
{
	int	**tabs;
	int	i;
	int	j;
	
	(void)is_multi;
	tabs = ft_calloc(3, sizeof(int*));
	tabs[2] = ft_calloc(2, sizeof(int));
	if (!is_multi)
	{
		tabs[2][0] = get_size_arg((char*)str[1]);
		tabs[0] = insert_arg_to_array(str[1], tabs[2][0]);
	}
	else
	{
		i = 1;
		while (str[i])
		{
	//		ft_printf("%s => %i\n", str[i], ft_atoi(str[i]));
			i++;
		}
		i--;
	//	ft_printf("SIZE: %i\n", i);
		tabs[2][0] = i;
		tabs[0] = ft_calloc(i, sizeof(int));
		i = 1;
		while (str[i])
		{
			j = 0;
		//	ft_printf("%s => %i\n", str[i], ft_atoi(str[i]));
			while (str[i][j])
			{
				if (!ft_find_char(str[i][j], "+-") && !ft_isdigit(str[i][j]))
				{
					free(tabs[0]);
					free(tabs[2]);
					free(tabs);
					return (NULL);
				}
				j++;
			}
			tabs[0][i-1] = ft_atoi(str[i]);
			i++;
		}
	}
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
		//	ft_printf("%s\n", str + i - 1);
		//	ft_printf("%i\n", ft_atoi(str + i -1));
			a[i_tab] = ft_atoi(str + i - 1);
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
