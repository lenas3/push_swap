/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:23:05 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 18:05:57 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*index_array(int *arr, int size)
{
	int	*index;
	int	i;
	int	j;
	int	count;

	index = malloc(sizeof(int) * size);
	if (!index)
		return (NULL);
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	return (index);
}

int	find_max_move(int *a, int size)
{
	int	i;
	int	*index;
	int	max;
	int	count;

	i = 0;
	count = 0;
	index = index_array(a, size);
	max = index[i];
	while (i < size)
	{
		if (index[i] > max)
			max = index[i];
		i++;
	}
	while (max > 0)
	{
		max = max >> 1;
		count++;
	}
	if (count == 0)
		count = 1;
	free(index);
	return (count);
}

void	copy_ind_array(int *a, int *ind_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a[i] = ind_arr[i];
		i++;
	}
}

void	radix(int *a, int *b, int *size_a, int *size_b)
{
	t_radix	r;

	r.index = 0;
	r.ind_arr = index_array(a, *size_a);
	copy_ind_array(a, r.ind_arr, *size_a);
	r.max_move = find_max_move(r.ind_arr, *size_a);
	while (r.index < r.max_move)
	{
		r.i = 0;
		r.len = *size_a;
		while (r.i < r.len)
		{
			if (((a[0] >> r.index) & 1) == 1)
				rotate_a(a, *size_a, 1);
			else
				push_b(a, b, size_a, size_b);
			r.i++;
		}
		while (*size_b != 0)
			push_a(a, b, size_a, size_b);
		r.index++;
	}
	free(r.ind_arr);
}
