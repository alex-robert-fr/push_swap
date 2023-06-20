#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		**tmp;
	int		*size;

	if (argc == 2)
	{
		if (!check_is_valid(argv, 0))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		tmp = init_tab(argv, 0);
	}
	else if (argc > 2)
	{
		if (!check_is_valid(argv, 1))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		tmp = init_tab(argv, 1);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!tmp || tmp[2][0] < 2)
	{
		if (tmp)
		{
			free(tmp[0]);
			free(tmp[1]);
			free(tmp[2]);
			free(tmp);
		}
		return (1);
	}
	size = ft_calloc(1, sizeof(int));
	*size = tmp[2][0];
	a = init_stack(tmp[0], *size);
	b = init_stack(tmp[1], 0);
	if (check_array(a->tab, *size) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		if (tmp)
		{
			free(tmp[0]);
			free(tmp[1]);
			free(tmp[2]);
			free(tmp);
			free(size);
			free(a->size);
			free(a);
			free(b->size);
			free(b);
		}
		return (1);
	}
	if (*size == 2)
		algo2(a);
	else if (*size == 3)
		algo3(a, b);
	else if (*size <= 5)
		algo5(a, b);
	else
		algo4000(a, b, size);
	//display(a->tab, b->tab, "FINAL", *size);
	free(a->size);
	free(b->size);
	free(a);
	free(b);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	free(size);
	return (0);
}

int	check_is_valid(char **argv, int multi)
{
	int	i;
	int	len;

	if (multi)
	{
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
	}
	else
	{
		i = 0;
		len = ft_strlen(argv[1]);
		if (argv[1][i] == ' ')
			i++;
		if (!len || i == len)
			return (0);
		while (i < len)
		{
			if (!is_valid_number(argv[1] + i))
				return (0);
			while (ft_isdigit(argv[1][i]))
				i++;
			if (argv[1][i] == ' ')
			{
				i++;
				continue ;
			}
			i++;
		}
	}
	return (1);
}

int is_valid_number(char *num)
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
	
	tabs = ft_calloc(3, sizeof(int*));
	tabs[2] = ft_calloc(2, sizeof(int));
	if (!is_multi)
	{
		tabs[2][0] = get_size_arg((char*)str[1]);
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
		i = 1;
		while (str[i])
		{
			tabs[0][i-1] = ft_atoi(str[i]);
			i++;
		}
	}
	tabs[1] = ft_calloc(tabs[2][0] + 1, sizeof(int));
	return (tabs);
}

int	*insert_arg_to_array(char *str, int	size)
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
		else if ((ft_find_char(str[i-1], " +-")) && ft_isdigit(str[i]))
		{
			a[i_tab] = ft_atoi(str + i - 1);
			i_tab++;
		}
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
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (nums[i] < nums[i + 1])
			j++;
		i++;
	}
	if (j == size - 1)
		exit(1);
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
		if (ft_isdigit(str[i]) && (!i || ft_find_char(str[i-1], " +-")))
			count_num++;
		if (!ft_find_char(str[i], " +-") && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (count_num);
}

int is_valid(char *num) {
    int i = 0;
    int is_negative = 0;
    int digit_count = 0;

    while (num[i] == ' ')
	{
        i++;
    }
    if (num[i] == '-') {
        is_negative = 1;
        i++;
    } else if (num[i] == '+') {
        i++;
    }
	while (num[i] == '0')
	{
        i++;
    }
    while (num[i] && num[i] != ' ') {
        if (!ft_isdigit(num[i]))
		{
            return 0;
		}
        digit_count++;
        i++;
    }
	if ((digit_count > 10) || 
    (digit_count == 10 && !is_negative && (num[i - 10] > '2' || (num[i - 10] == '2' && num[i - 9] > '1'))) || 
    (digit_count == 10 && is_negative && (num[i - 10] > '2' || (num[i - 10] == '2' && num[i - 9] > '1'))))
	{
        return 0;
    }
    return 1;
}

