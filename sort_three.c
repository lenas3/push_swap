/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:10:57 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 20:46:53 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void two_element_sort(int *a, int size)
{
    int i;

    i = 0;
    if(a[i] > a[i + 1])
        swap_a(a, size, 1);
    else
        return ;
}

void three_element_sort(int *a, int size)
{
    if(a[0] < a[1] && a[1] < a[2])
        return ;
    else if(a[1] > a[0] && a[2] > a[0] && a[1] > a[2])
    {
        re_rotate_a(a, size, 1);
        swap_a(a, size, 1);
    }
    else if(a[0] > a[1] && a[2] > a[1] && a[2] > a[0])
        swap_a(a, size, 1);
    else if(a[1] > a[0] && a[1] > a[2] && a[0] > a[2])
        re_rotate_a(a, size, 1);
    else if(a[0] > a[1] && a[0] > a[2] && a[2] > a[1])
        rotate_a(a, size, 1);
    else if(a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
    {
        rotate_a(a, size, 1);
        swap_a(a, size, 1);
    }
}

