/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:03 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 20:36:38 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(int *a, int *b, int *a_size, int *b_size)
{
	int temp;

	if(b_size == 0)
		return ;
	temp = b[*b_size - 1];
	b[*b_size - 1] = 0;
	a[*a_size - 1] = temp;
	a_size++;
	b_size--;
	write(1, "pa\n", 3);
}

void push_b(int *a, int *b, int *a_size, int *b_size)
{
	int temp;
	if(a_size == 0)
		return ;
	temp = a[*a_size - 1];
	a[*a_size - 1] = 0;
	b[*b_size - 1] = temp;
	a_size--;
	b_size++;
	write(1, "pb\n", 3);
}

