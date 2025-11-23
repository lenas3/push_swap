/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:59:50 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 18:12:51 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *a, int size, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(int *b, int size, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = b[0];
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size - 1] = temp;
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_both(int *a, int *b, int size_a, int size_b)
{
	rotate_a(a, size_a, 0);
	rotate_b(b, size_b, 0);
	write(1, "rr\n", 3);
}
