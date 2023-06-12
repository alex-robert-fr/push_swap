#ifndef RULES_H
#define RULES_H

void	rules_swap(int *a, int size, char *str);
void	rules_swap_all(int *a, int *b, int size);
void	rules_push(int *a, int *b, int size, char *str);
void	rules_rot(int *a, int size, char *str);
void	rules_rot_all(int *a, int *b, int size);
void	rules_reverse_rot(int *a, int size, char *str);
void	rules_reverse_rot_all(int *a, int *b, int size);

void	swap_a(int *a, int size);

int		up_array(int *array, int size);
void	down_array(int *array, int top);
void	down_array2(int *array, int top);

#endif
