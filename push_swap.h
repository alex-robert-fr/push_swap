#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SIZE 3

// recurpere arg[1] ou tout les arguments (./push_swap 1 23 43 32 12)
// avoir 2 array alloc

typedef struct s_info {
	int	nb_move;
	int	min_move;
	int	index_min_move;
}	t_info;

typedef struct s_stack {
	int	*tab;
	int	*size;
}	t_stack;

// Parsing
int		**init_tab(char **str, int is_multi);
// savoir quelle type d'entrer il y a
// compter le nombre de nombres entrer
int		get_size_arg(char *str);
int		get_size_args(char **str);
int		get_size_array(int *array);
// alloc les 2 tableau en fonction de la taille trouver
// inserer les nombres dans l'array A
int		*insert_arg_to_array(char *str, int size);
int		*insert_args_to_array(char **str, int size);
// Verifie les nombre dans l'array A
int		check_array(int *nums, int size);
// affiche les tableau
void	display(int *a, int *b, char *str, int size);
// algo
void	algo2(t_stack *a);
void	algo3(t_stack *a, t_stack *b);
void	algo5(t_stack *a, t_stack *b);
void	algo2000(int *a, int *b, int size);
void	algo3000(int *a, int *b, int size);
void	radix(int *a, int *b, int size);
int		get_position_number(int *tab, int find, int size);




int	find_cheapest_number(int *a, int *b, int *size_a, int *size_b, int index, t_info *info);
int	test_move_one_number(int *a, int *b, int *size_a, int *size_b, int index, t_info *info);
int	*tab_copy(int *original, int size);
int	*int_copy(int original);
int	init_copy_size(int *cp_size_a, int *size_a, int *cp_size_b, int *size_b);






void	algo4000(t_stack *a, t_stack *b, int *size);
t_info	*init_info(t_stack *a, t_stack *b, int *size_b);
t_stack	*init_stack(int *tab, int size);
int		find_cheapest_num(t_stack *a, t_stack *b);
void	move_element(t_stack *a, t_stack *b, int cheapest_num);
int		calculate_cost(int pos_a, t_stack *a, t_stack *b);
int		max_number(t_stack *tab);
int		lower_number(t_stack *tab);
int		min(int a, int b);
int		find_position(int num, t_stack *tab);
int		find_intern_position(int num, t_stack *tab);
#endif

