#ifndef RULES_H
#define RULES_H

void	rules_swap(int *a);
void	rules_swap_all(int *a, int *b);
void	rules_push(int *a, int *b);
void	rules_rot(int *a);
void	rules_rot_all(int *a, int *b);
void	rules_reverse_rot(int *a);
void	rules_reverse_rot_all(int *a, int *b);

int		up_array(int *array);
void	down_array(int *array, int top);

#endif
