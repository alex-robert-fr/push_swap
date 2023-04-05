#include "rules.h"
#include "libft.h"
#include "push_swap.h"

void	rules_swap_a(int *a)
{
	a[1] = a[0] + a[1];
	a[0] = a[1] - a[0];
	a[1] = a[1] - a[0];
}

void	rules_swap_b(int *b)
{
	b[1] = b[0] + b[1];
	b[0] = b[1] - b[0];
	b[1] = b[1] - b[0];
}

void	rules_swap_a_and_b(int *a, int *b)
{
	rules_swap_a(a);
	rules_swap_b(b);
}

// prend le 1er nb dans A en decalant le reste vers le haut et le met dans B en decalant le reste vers le bas
void	rules_push_b(int *a, int *b)
{
	down_array(b, a[0]);
	up_array(a);
}

void	up_array(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		array[i] = array[i+1];
		i++;
	}
}
 void	down_array(int *array, int top)
{
	int	i;

	//22 
	//0
	//0

	i = 0;
	while (array[i])
		i++;
	//i = 1

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
//	else
//	{
//		while (array[i - 1])
//		{
//			array[i] = array[i - 1];
//			i++;
//			if (i == 3)
//				break;
//		}
//		array[0] = top;
//	}
	
}
