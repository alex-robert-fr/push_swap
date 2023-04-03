#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;
	int	**tmp;

	i = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		tmp = init_tab(argv[1], 1);
	else
		tmp = init_tab(argv, 0);
	a = tmp[0];
	b = tmp[1];
	while (a[i])
	{
		ft_printf("%i => %i\n", i, a[i]);
		i++;
	}
	if (check_array(tmp[0]))
	{
		ft_printf("Error\n");
		free(a);
		free(b);
		free(tmp);
		return (0);
	}
	free(a);
	free(b);
	free(tmp);
	return (0);
}

int	**init_tab(void *str, int one_arg)
{
	int	**tabs;
	int	tab_size;
	
	tabs = ft_calloc(2, sizeof(int*));
	if (one_arg)
	{
		ft_printf("ONE ARG\n");
		tab_size = get_size_arg((char*)str) + 1;
		tabs[0] = insert_arg_to_array((char*)str, tab_size);
		tabs[1] = ft_calloc(tab_size, sizeof(int));
	}
	else
	{
		ft_printf("ARGS\n");
	}
	return (tabs);
}
                                                      
int	get_size_arg(char *str)
{
	int	i;
	int	count_num;

	i = 0;
	count_num = 0;
	while (str[i])
	{
		if ((!i && ft_isdigit(str[i])) || (i && ft_isdigit(str[i]) && ft_find_char(str[i-1], " +-")))
			count_num++;
		if (!ft_find_char(str[i], " +-") && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (count_num);
}

int	*insert_arg_to_array(char *str, int	size)
{
	int	*a;
	int	i;
	int	i_tab;

	a = ft_calloc(size, sizeof(int));
	i = 0;
	i_tab = 0;
	while (str[i])
	{
		if ((!i && ft_isdigit(str[i])) || (i && ft_isdigit(str[i]) && ft_find_char(str[i-1], " +-")))
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
