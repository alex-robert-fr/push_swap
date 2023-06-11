#include "rules.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	rules_swap(int *a, int size, char *str)
{
	ft_printf("%s\n", str);
	if (size > 1)
	{
		ft_printf("Before: %i\n", a[0]);
		a[1] = a[0] + a[1];
		a[0] = a[1] - a[0];
		a[1] = a[1] - a[0];
		ft_printf("After: %i\n", a[0]);
	}
}

void	rules_swap_all(int *a, int *b, int size)
{
	rules_swap(a, size, "sa");
	rules_swap(b, size, "sb");
}

void	rules_push(int *a, int *b, int size, char *str)
{
	ft_printf("%s\n", str);
	ft_printf("Before: a%i b%i\n", a[0], b[0]);
	down_array(a, b[0]);
	up_array(b, size);
	ft_printf("After: a%i b%i\n", a[0], b[0]);
	(void)size;
}

void	rules_rot(int *a, int size, char *str)
{
	int	index;
	int	top;

	ft_printf("%s\n", str);
	top = a[0];
	index = up_array(a, size);
	a[index - 1] = top;
}

void	rules_rot_all(int *a, int *b, int size)
{
	rules_rot(a, size, "ra");
	rules_rot(b, size, "rb");
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

int	up_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
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

// PASS
void	display(int *a, int *b, char *str, int size)
{
	int	i;

	i = 0;
	ft_printf("%s\n", str);
	ft_printf("----------------------------\n");
	ft_printf("   a b\n");
	ft_printf("=========\n");
	while (i < size)
	{
		ft_printf("%5i %i\n", a[i], b[i]);
		i++;
	}
	ft_printf("----------------------------\n");
}
