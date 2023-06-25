/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:12:15 by alex              #+#    #+#             */
/*   Updated: 2023/06/25 12:45:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SIZE 3

typedef struct s_info {
	int	nb_move;
	int	min_move;
	int	index_min_move;
}	t_info;
typedef struct s_stack {
	int	*tab;
	int	*size;
}	t_stack;
typedef struct s_rotation_data
{
	t_stack	*a;
	t_stack	*b;
	int		*pos_a;
	int		*pos_b;
	int		*rot_a;
	int		*rot_b;
}				t_rotation_data;
int		**init_tab(char **str, int is_multi);
int		get_size_arg(char *str);
int		*insert_arg_to_array(char *str, int size);
int		check_array(int *nums, int size);
void	algo2(t_stack *a);
void	algo3(t_stack *a, t_stack *b);
void	algo5(t_stack *a, t_stack *b);
int		check_is_valid(char **argv, int multi);
int		is_valid_number(char *num);
int		is_valid(char *num);
int		check_multi_valid(char **argv);
int		check_single_valid(char *argv);
void	algo4000(t_stack *a, t_stack *b, int *size);
t_stack	*init_stack(int *tab, int size);
int		find_cheapest_num(t_stack *a, t_stack *b);
void	move_element(t_stack *a, t_stack *b, int cheapest_num);
int		calculate_cost(int pos_a, t_stack *a, t_stack *b);
int		max_number(t_stack *tab);
int		lower_number(t_stack *tab);
int		min(int a, int b);
int		find_position(int num, t_stack *tab);
int		find_intern_position(int num, t_stack *tab);
void	perform_rotation(t_rotation_data *data);
void	rotate_a_to_position(t_stack *a, int pos_a);
void	rotate_b_to_position(t_stack *b, int pos_b);
int		find_position_for_move(t_stack *a, t_stack *b, int pos_a);
void	free_tmp(int **tmp);
#endif
