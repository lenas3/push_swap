/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:03 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 17:59:40 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int *a, int *b, int *a_size, int *b_size)
{
	int	temp;
	int	i;

	if (*b_size == 0)
		return ;
	i = 0;
	temp = b[0];
	while (i < *b_size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*b_size)--;
	i = *a_size;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	(*a_size)++;
	write(1, "pa\n", 3);
}

void	push_b(int *a, int *b, int *a_size, int *b_size)
{
	int	temp;
	int	i;

	if (*a_size == 0)
		return ;
	temp = a[0];
	i = 0;
	while (i < *a_size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*a_size)--;
	i = *b_size;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	(*b_size)++;
	write(1, "pb\n", 3);
}
