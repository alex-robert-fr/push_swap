#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "rules.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	count_num_arg(argv[1]);
	// int	*a;
	// int	*b;

	// a = ft_calloc(10, sizeof(int));
	// b = ft_calloc(10, sizeof(int));
	
	// free(a);
	// free(b);
	return (0);
}

int	count_num_arg(char *str)
{
	int	i;
	int	count_num;
	
	i = 0;
	count_num = 0;
	while (str[i])
	{
		if ((i == 0 && ft_isdigit(str[i])) || (i > 0 && ft_isdigit(str[i]) && ft_find_char(str[i - 1], " +-")))
		{
			ft_printf("NUMBER = %i\n", ft_atoi(str + i));
			count_num++;
		}
		if (!ft_find_char(str[i], " +-") && !ft_isdigit(str[i]))
			ft_exit();
		i++;
	}
	ft_printf("%s\n%i\n", str, count_num);
	return (count_num);
}

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}