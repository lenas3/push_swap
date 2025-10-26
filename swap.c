/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:51:43 by asay              #+#    #+#             */
/*   Updated: 2025/10/26 19:55:54 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *a, int size, int flag)
{
	int temp;

	if(size < 2 || !a || !a[1])
		return ;
	temp = a[size];
	a[size] = a[size - 1];
	a[size - 1] = temp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(int *b, int size, int flag)
{
	if(size < 2 || !b || !b[1])
		return ;
	int temp;
	temp = b[size];
	b[size] = b[size - 1];
	b[size - 1] = temp;
	if (flag)
		write(1, "sb\n", 3);
}

void swap_ab(int *a, int *b, int size)
{
	swap_a(a, size, 0);
	swap_b(b, size, 0); // 0'la çağırıyorum ki buradan çağırdığımda sa sb yazdırılmasın.
	write(1, "ss\n", 3);
}

