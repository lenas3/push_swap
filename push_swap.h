#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

void is_valid_char(char *str);
int is_duplicate(char *str, char c);
void quoted_arg(char **arg, char **str);
void non_quoted_arg(char **str);
void push_a(int *a, int *b, int a_size, int b_size);
void push_b(int *a, int *b, int a_size, int b_size);
void rotate_a(int *a, int size, int flag);
void rotate_b(int *b, int size, int flag);
void rotate_both(int *a, int *b, int size);
static char	**allfree(char **arr, size_t i);
static int	wordnum(const char *str, char c);
static size_t	word_len(const char *str, char c);
static char	**fill_array(char **result, const char *s, char c);
char	**ft_split(char const *s, char c);
void	swap_a(int *a, int size, int flag);
void	swap_b(int *b, int size, int flag);
void swap_ab(int *a, int *b, int size);
void err_exit();
int ft_doublelen(char **str);
void free_all(int *stack, int size);
int ft_atoi(const char *str);
void push_arg(int argc, char **argv, int *arr);

#endif