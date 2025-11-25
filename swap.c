/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:51:43 by asay              #+#    #+#             */
/*   Updated: 2025/11/25 14:36:19 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *a, int size, int flag)
{
	int	temp;

	if (size < 2 || !a)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(int *b, int size, int flag)
{
	int	temp;

	if (size < 2 || !b || !b[1])
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	if (flag)
		write(1, "sb\n", 3);
}
