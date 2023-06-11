#include "rules.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	rules_swap(int *a, char *str)
{
	ft_printf("%s\n", str);
	if (a[1] != '\0')
	{
		a[1] = a[0] + a[1];
		a[0] = a[1] - a[0];
		a[1] = a[1] - a[0];
	}
}

void	rules_swap_all(int *a, int *b)
{
	rules_swap(a, "sa");
	rules_swap(b, "sb");
}

void	rules_push(int *a, int *b, char *str)
{
	ft_printf("%s\n", str);
	if (!b[0])
		return ;
	down_array(a, b[0]);
	up_array(b);
}

void	rules_rot(int *a, char *str)
{
	int	index;
	int	top;

	ft_printf("%s\n", str);
	top = a[0];
	index = up_array(a);
	a[index - 1] = top;
}

void	rules_rot_all(int *a, int *b)
{
	rules_rot(a, "ra");
	rules_rot(b, "rb");
}

void	rules_reverse_rot(int *a, char *str)
{
	int	i;
	int	top;

	ft_printf("%s\n", str);
	i = 0;
	while (a[i])
		i++;
	top = a[i-1];
	down_array(a, top);
	a[i] = 0;
}

void	rules_reverse_rot_all(int *a, int *b)
{
	rules_reverse_rot(a, "rra");
	rules_reverse_rot(b, "rrb");
}

int	up_array(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		array[i] = array[i+1];
		i++;
	}
	return (i);
}
 void	down_array(int *array, int top)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	if (!i)
		array[0] = top;
	else
	{

		while (i)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[i] = top;
	}
}
