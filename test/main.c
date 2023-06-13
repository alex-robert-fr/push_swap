#include "ft_printf.h"
#include "greatest.h"
#include "../rules2000.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

TEST test_swap_1(void)
{
	int	swap_a[] = {2, 1, 3, 4};
	int	swap_b[] = {1, 2, 3, 4};

	swap(swap_a, 4);

	ASSERT_MEM_EQ(swap_b, swap_a, sizeof(int) * 4);
	PASS();
}

TEST test_swap_2(void)
{
	int	swap_a[] = {2, 1};
	int	swap_b[] = {1, 2};

	swap(swap_a, 2);

	ASSERT_MEM_EQ(swap_b, swap_a, sizeof(int) * 2);
	PASS();
}

TEST test_swap_3(void)
{
	int	swap_a[] = {2};
	int	swap_b[] = {2};

	swap(swap_a, 1);

	ASSERT_MEM_EQ(swap_b, swap_a, sizeof(int) * 1);
	PASS();
}

TEST test_swap_4(void)
{
	int	swap_a[] = {0};
	int	swap_b[] = {0};

	swap(swap_a, 0);

	ASSERT_MEM_EQ(swap_b, swap_a, sizeof(int) * 1);
	PASS();
}

TEST test_swap_5(void)
{
	int	swap_a[] = {0};
	int	swap_b[] = {0};

	swap(swap_a, -1);

	ASSERT_MEM_EQ(swap_b, swap_a, sizeof(int) * 1);
	PASS();
}


SUITE(swap_suite)
{
	RUN_TEST(test_swap_1);
	RUN_TEST(test_swap_2);
	RUN_TEST(test_swap_3);
	RUN_TEST(test_swap_4);
	RUN_TEST(test_swap_5);
}

TEST test_push_1(void)
{
	int	stack_a[] = {1, 2, 3, 4, 5, 0};
	int	*stack_b = malloc(sizeof(int));
	int	result_a[] = {2, 3, 4, 5, 0, 0};
	int	result_b[] = {1, 0};
	int	*size_a = ft_calloc(1, sizeof(int));
	int	*size_b = ft_calloc(1, sizeof(int));
	*size_a = 5;
	*size_b = 0;

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_a, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_b, stack_b, sizeof(int) * *size_b + 1);

	int	result_c[] = {3, 4, 5, 0, 0};
	int	result_d[] = {2, 1, 0};

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_c, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_d, stack_b, sizeof(int) * *size_b + 1);

	int	result_e[] = {4, 5, 0, 0, 0};
	int	result_f[] = {3, 2, 1, 0};

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_e, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_f, stack_b, sizeof(int) * *size_b + 1);

	PASS();
}

TEST test_push_2(void)
{
	int	stack_a[] = {1, 0};
	int	*stack_b = malloc(sizeof(int));
	int	result_a[] = {0, 0};
	int	result_b[] = {1, 0};
	int	*size_a = ft_calloc(1, sizeof(int));
	int	*size_b = ft_calloc(1, sizeof(int));
	*size_a = 1;
	*size_b = 0;

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_a, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_b, stack_b, sizeof(int) * *size_b + 1);
	PASS();
}

TEST test_push_3(void)
{
	int	stack_a[] = {0};
	int	*stack_b = malloc(sizeof(int));
	int	result_a[] = {0};
	int	result_b[] = {0};
	int	*size_a = ft_calloc(1, sizeof(int));
	int	*size_b = ft_calloc(1, sizeof(int));
	*size_a = 0;
	*size_b = 0;

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_a, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_b, stack_b, sizeof(int) * *size_b + 1);
	PASS();
}

TEST test_push_4(void)
{
	int	stack_a[] = {0, 1, 0};
	int	*stack_b = malloc(sizeof(int));
	int	result_a[] = {1, 0};
	int	result_b[] = {0, 0};
	int	*size_a = ft_calloc(1, sizeof(int));
	int	*size_b = ft_calloc(1, sizeof(int));
	*size_a = 2;
	*size_b = 0;

	push(stack_a, stack_b, size_a, size_b);

	ASSERT_MEM_EQ(result_a, stack_a, sizeof(int) * *size_a + 1);
	ASSERT_MEM_EQ(result_b, stack_b, sizeof(int) * *size_b + 1);
	PASS();
}

SUITE(push_suite)
{
	RUN_TEST(test_push_1);
	RUN_TEST(test_push_2);
	RUN_TEST(test_push_3);
	RUN_TEST(test_push_4);
}

TEST test_rotate_1(void)
{
	int	stack[] = {2, 1, 3, 0};
	int	result[] = {1, 3, 2, 0};
	int size = 3;

	rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_rotate_2(void)
{
	int	stack[] = {2, 1, 0};
	int	result[] = {1, 2, 0};
	int size = 2;

	rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_rotate_3(void)
{
	int	stack[] = {2, 0};
	int	result[] = {2, 0};
	int size = 1;

	rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_rotate_4(void)
{
	int	stack[] = {2, 0, 1, 0};
	int	result[] = {0, 1, 2, 0};
	int size = 3;

	rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

SUITE(rotate_suite)
{
	RUN_TEST(test_rotate_1);
	RUN_TEST(test_rotate_2);
	RUN_TEST(test_rotate_3);
	RUN_TEST(test_rotate_4);
}

TEST test_reverse_rotate_1(void)
{
	int	stack[] = {2, 3, 1, 0};
	int	result[] = {1, 2, 3, 0};
	int size = 3;

	reverse_rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_reverse_rotate_2(void)
{
	int	stack[] = {2, 3, 0};
	int	result[] = {3, 2, 0};
	int size = 2;

	reverse_rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_reverse_rotate_3(void)
{
	int	stack[] = {1, 0, 3, 0};
	int	result[] = {3, 1, 0, 0};
	int size = 3;

	reverse_rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_reverse_rotate_4(void)
{
	int	stack[] = {1, 0};
	int	result[] = {1, 0};
	int size = 1;

	reverse_rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

TEST test_reverse_rotate_5(void)
{
	int	stack[] = {1, 2, 3, 0, 0, 0};
	int	result[] = {3, 1, 2, 0, 0, 0};
	int size = 3;

	reverse_rotate(stack, size);

	ASSERT_MEM_EQ(result, stack, sizeof(int) * size + 1);
	PASS();
}

SUITE(reverse_rotate_suite)
{
	RUN_TEST(test_reverse_rotate_1);
	RUN_TEST(test_reverse_rotate_2);
	RUN_TEST(test_reverse_rotate_3);
	RUN_TEST(test_reverse_rotate_4);
	RUN_TEST(test_reverse_rotate_5);
}

GREATEST_MAIN_DEFS();

int main(int argc, char *argv[])
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(swap_suite);
	RUN_SUITE(push_suite);
	RUN_SUITE(rotate_suite);
	RUN_SUITE(reverse_rotate_suite);
	GREATEST_MAIN_END();
}

