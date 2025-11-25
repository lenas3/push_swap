/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:54:08 by asay              #+#    #+#             */
/*   Updated: 2025/11/25 15:16:39 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**split;
}t_list;

typedef struct s_radix
{
	int	i;
	int	index;
	int	len;
	int	*ind_arr;
	int	max_move;
}t_radix;

void	is_valid_char(char *str, t_list *main);
void	is_duplicate(int *arr, int size, t_list *main);
void	quoted_arg(char **argv, char ***str, t_list *main);
void	push_a(int *a, int *b, int *a_size, int *b_size);
void	push_b(int *a, int *b, int *a_size, int *b_size);
int		*index_array(int *arr, int size);
int		find_max_move(int *a, int size);
void	radix(int *a, int *b, int *size_a, int *size_b);
void	re_rotate_a(int *a, int size, int flag);
void	re_rotate_b(int *b, int size, int flag);
void	rotate_a(int *a, int size, int flag);
void	rotate_b(int *b, int size, int flag);
int		min_element(int *arr, int size);
void	place_to_top(int *a, int size);
void	five_element_sort(int *a, int *b, int *a_size, int *b_size);
void	four_element_sort(int *a, int *b, int *a_size, int *b_size);
void	two_element_sort(int *a, int size);
void	three_element_sort(int *a, int size);
char	**ft_split(char const *s, char c);
void	swap_a(int *a, int size, int flag);
void	swap_b(int *b, int size, int flag);
void	err_exit(void);
int		ft_atoi(const char *str, t_list *main);
void	push_arg(int argc, char **argv, int **arr, t_list *main);
void	allocate_mem(int **a, int **b, int size_a);
void	quoted_size(char **str, int *size);
void	sort_main(int *a, int *b, int *size_a, int *size_b);
void	free_split(char **res);
void	free_all(t_list *main);
int		is_sorted(int *a, int size);
void	limitcontrol(long a, char sign, t_list *main);
int		ft_strlen(char *str);
char	*epur_str(char *str, int i, int j);
int		ft_strcmp(char *s1, char *s2);
void	handle_quoted(t_list *main, char **argv);
void	copy_ind_array(int *a, int *ind_arr, int size);
void	skip_and_sign(const char *str, int *i, int *sign);

#endif