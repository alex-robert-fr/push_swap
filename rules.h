#ifndef RULES_H
#define RULES_H

void	rules_swap_a(int *a);
void	rules_swap_b(int *b);
void	rules_swap_a_and_b(int *a, int *b);
void	rules_push_a(int *a, int *b);
void	rules_push_b(int *a, int *b);
void	rules_rot_a(int *a);
void	rules_rot_b(int *b);
void	rules_rot_a_and_b(int *a, int *b);
void	rules_reverse_rot_a(int *a);
void	rules_reverse_rot_b(int *b);
void	rules_reverse_rot_a_and_b(int *a, int *b);

void	up_array(int *array);
void	down_array(int *array, int top);

#endif
