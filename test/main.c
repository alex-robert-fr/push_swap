#include <check.h>
#include "../rules.h"

// Test case
START_TEST(test_swap_rule)
{
	int	a[] = {1, 2, 4, 5};
	int	b[] = {2, 1, 4, 5};
	int	c[] = {1};
	int	d[] = {1};
	size_t size = sizeof(a) / sizeof(a[0]);
	size_t size2 = sizeof(c) / sizeof(c[0]);

	rules_swap(a, 4, "sa");
	rules_swap(c, 1, "sa");
	ck_assert_mem_eq(a, b, size * sizeof(int));
	ck_assert_mem_eq(c, d, size2 * sizeof(int));
}
END_TEST

START_TEST(test_push_rule)
{
	int	a[] = {1, 2, 4, 5};
	int	b[] = {0, 0, 0, 0};
	int	a_result[] = {2, 4, 5, 0};
	int	b_result[] = {1, 0, 0, 0};
	size_t size = sizeof(a) / sizeof(a[0]);

	rules_push(b, a, 4, "pa");
	ck_assert_mem_eq(a, a_result, size);
	ck_assert_mem_eq(b, b_result, size);
}

START_TEST(test_push_rule_hard)
{
	int	a[] = {1, 2, 4, 5, 3, 90};
	int	b[] = {0, 0, 0, 0, 0, 0};
	int	a_result[] = {2, 4, 5, 3, 90, 0};
	int	b_result[] = {1, 0, 0, 0, 0, 0};
	size_t size = sizeof(a) / sizeof(a[0]);

	rules_push(b, a, 6, "pa");
	ck_assert_mem_eq(a, a_result, size);
	ck_assert_mem_eq(b, b_result, size);
}

START_TEST(test_rra)
{
	int	a[] = {1, 2, 4, 5, 3, 90};
	int	a_result[] = {90, 1, 2, 4, 5, 3};
	size_t size = sizeof(a) / sizeof(a[0]);

	rules_reverse_rot(a, 6, "pa");
	ck_assert_mem_eq(a, a_result, size);
}

// Test suite
Suite *my_test_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Test Rules");

    tc = tcase_create("Swap Rule");
    tcase_add_test(tc, test_swap_rule);
    suite_add_tcase(s, tc);
    tc = tcase_create("Push Rule");
    tcase_add_test(tc, test_push_rule);
    tcase_add_test(tc, test_push_rule_hard);
	tc = tcase_create("Reverse Rotate");
	tcase_add_test(tc, test_rra);
    suite_add_tcase(s, tc);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = my_test_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

