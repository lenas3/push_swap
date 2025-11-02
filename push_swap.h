#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

void is_valid_char(char *str);
void is_duplicate(int *arr, int size, int *b, char **split);
void quoted_arg(char **argv, char ***str);
void non_quoted_arg(char **argv, int *size, int argc);
void push_a(int *a, int *b, int *a_size, int *b_size);
void push_b(int *a, int *b, int *a_size, int *b_size);
int *find_index(int *arr, int size);
int find_max(int *a, int size);
void radix(int *a, int *b, int *size_a, int *size_b);
void re_rotate_a(int *a, int size, int flag);
void re_rotate_b(int *b, int size, int flag);
void re_rotate_both(int *a, int *b, int size);
void rotate_a(int *a, int size, int flag);
void rotate_b(int *b, int size, int flag);
void rotate_both(int *a, int *b, int size);
int min_element(int *arr, int size);
void place_to_top(int *a, int size);
void five_element_sort(int *a, int *b, int *a_size, int *b_size);
void four_element_sort(int *a, int *b, int *a_size, int *b_size);
void two_element_sort(int *a, int size);
void three_element_sort(int *a, int size);
char	**ft_split(char const *s, char c);
void	swap_a(int *a, int size, int flag);
void	swap_b(int *b, int size, int flag);
void swap_ab(int *a, int *b, int size);
void err_exit();
int ft_doublelen(char **str);
int ft_atoi(const char *str);
void push_arg(int argc, char **argv, int **arr);
void allocate_mem(int **a, int **b, int size_a);
void quoted_size(char **str, int *size);
void sort_main(int *a, int *b, int *size_a, int *size_b);
void free_split(char **res);



#endif