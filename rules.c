#include "rules.h"
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	rules_swap(int *a)
{

	if (a[1] != '\0')
	{
		a[1] = a[0] + a[1];
		a[0] = a[1] - a[0];
		a[1] = a[1] - a[0];
	}
}

void	rules_swap_all(int *a, int *b)
{
	rules_swap(a);
	rules_swap(b);
}

void	rules_push(int *a, int *b)
{
	if (!b[0])
		return ;
	down_array(a, b[0]);
	up_array(b);
}

void	rules_rot(int *a)
{
	int	index;
	int	top;

	top = a[0];
	index = up_array(a);
	a[index - 1] = top;
}

void	rules_rot_all(int *a, int *b)
{
	rules_rot(a);
	rules_rot(b);
}

void	rules_reverse_rot(int *a)
{
	int	i;
	int	top;

	i = 0;
	while (a[i])
		i++;
	top = a[i-1];
	ft_printf("LAST: %i\n", top);
	down_array(a, top);
	a[i] = 0;
}

void	rules_reverse_rot_all(int *a, int *b)
{
	rules_reverse_rot(a);
	rules_reverse_rot(b);
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
