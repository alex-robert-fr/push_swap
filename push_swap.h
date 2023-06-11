#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// recurpere arg[1] ou tout les arguments (./push_swap 1 23 43 32 12)
// avoir 2 array alloc

typedef struct s_info {
	int min_number;
	int	max_number;
}	t_info;

// Parsing
int		**init_tab(void *str);
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
int		check_array(int *nums);
// affiche les tableau
void	display(int *a, int *b, char *str, int size);
// algo
void	algo3(int *a, int *b);
void	algo5(int *a, int *b, int size);
void	algo2000(int *a, int *b, int size);
void	radix(int *a, int *b, int size);
int		max_number(int *a, int size);
int		lower_number(int *a, int size);
int		get_position_number(int *tab, int find, int size);
#endif

