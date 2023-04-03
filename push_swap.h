#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// recurpere arg[1] ou tout les arguments (./push_swap 1 23 43 32 12)
// avoir 2 array alloc

// Parsing
int		**init_tab(void *str, int one_arg);
// savoir quelle type d'entrer il y a
// compter le nombre de nombres entrer
int		get_size_arg(char *str);
int		get_size_args(char **str);
// alloc les 2 tableau en fonction de la taille trouver
// inserer les nombres dans l'array A
int		*insert_arg_to_array(char *str, int size);
int		*insert_args_to_array(char **str, int size);
// Verifie les nombre dans l'array A
int		check_array(int *nums);
// exit
//void	ft_exit()
#endif

