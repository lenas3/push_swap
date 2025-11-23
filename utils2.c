/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:45:57 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 18:46:40 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quoted_size(char **str, int *size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (str[i])
	{
		j = 0;
		flag = 0;
		while (str[i][j])
		{
			if (((str[i][j] >= '0' && str[i][j] <= '9')
				|| str[i][j] == '+' || str[i][j] == '-') && !flag)
			{
				(*size)++;
				flag = 1;
			}
			else if (str[i][j] == ' ')
				flag = 0;
			j++;
		}
		i++;
	}
}

void	allocate_mem(int **a, int **b, int size_a)
{
	*a = malloc(sizeof(int) * size_a);
	if (!*a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	*b = malloc(sizeof(int) * size_a);
	if (!*b)
	{
		free(*a);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	sort_main(int *a, int *b, int *size_a, int *size_b)
{
	if (*size_a == 1)
		return ;
	else if (*size_a == 2)
		two_element_sort(a, *size_a);
	else if (*size_a == 3)
		three_element_sort(a, *size_a);
	else if (*size_a == 4)
		four_element_sort(a, b, size_a, size_b);
	else if (*size_a == 5)
		five_element_sort(a, b, size_a, size_b);
	else
		radix(a, b, size_a, size_b);
}

void	free_split(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	free_all(t_list *main)
{
	if (main->a != NULL)
	{
		free(main->a);
		main->a = NULL;
	}
	if (main->b != NULL)
	{
		free(main->b);
		main->b = NULL;
	}
	free_split(main->split);
	main->split = NULL;
}
