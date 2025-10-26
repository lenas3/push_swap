#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

void err_exit(void);
void swap_a(int *a, int size, int flag);
void swap_b(int *b, int size, int flag);
void swap_ab(int *a, int *b, int size);
void push_a(int *a, int *b, int a_size, int b_size);
void push_b(int *a, int *b, int a_size, int b_size);
void push_arg(int argc, char **argv, int *arr);
int ft_atoi(const char *str);
int is_duplicate(char c, char *str);
int check_arg(char **argv);
static char	**allfree(char **arr, size_t i);
static int	wordnum(const char *str, char c);
static size_t	word_len(const char *str, char c);
static char	**fill_array(char **result, const char *s, char c);
char	**ft_split(char const *s, char c);
void is_arg_num(char *str);


#endif