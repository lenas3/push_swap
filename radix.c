/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:23:05 by asay              #+#    #+#             */
/*   Updated: 2025/11/14 18:50:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int *index_array(int *arr, int size)
{
    int *index;
    int i, j;
    int count;

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


int find_max_move(int *a, int size)
{
    int i;
    int *index;
    int max;
    int count;

    i = 0;
    count = 0;
    index = index_array(a, size);
    max = index[i];
    while(i < size)
    {
        if(index[i] > max)
            max = index[i];
        i++;
    }
    while(max > 0)
    {
        max = max >> 1;
        count++;
    }
    if(count == 0)
        count = 1;
    free(index);
    return count;
}

void radix(int *a, int *b, int *size_a, int *size_b)
{
    int i;
    int index;
    int max_move;
    int len;
    int *ind_arr;
    int k = 0;
    index = 0;

    ind_arr = index_array(a, *size_a);
    while(k < *size_a)
    {
        a[k] = ind_arr[k];
        k++;
    }   
    max_move = find_max_move(ind_arr, *size_a);   
    while(index < max_move)
    {
        i = 0;
        len = *size_a;
        while(i < len)
        {
            if(((a[0] >> index) & 1) == 1)
                rotate_a(a, *size_a, 1);
            else
                push_b(a, b, size_a, size_b);
            i++;
        }
        while(*size_b != 0)
            push_a(a, b, size_a, size_b);
        index++;
    }
    free(ind_arr);
}
