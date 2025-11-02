/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:23:05 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 20:41:02 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *find_index(int *arr, int size)
{
    int i;
    int j;
    int *index;
    int count;

    i = 0;
    count = 0;
    index = malloc(sizeof(int) * (size));
    if(!index)
        return (NULL);
    while(i < size)
    {
        j = 0;
        while(j < size)
        {
            if(arr[i] > arr[j])
            {
                index[i] = count;
                count++;
            }
            j++;
        }
        i++;
    }
    //write(1, "find_index done\n", 17);
    return (index);
}

int find_max(int *a, int size)
{
    int i;
    int *index;
    int max;
    int count;

    i = 0;
    count = 0;
    index = find_index(a, size);
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
    //write(2, "find_max done\n", 15);
    return count;
}

void radix(int *a, int *b, int *size_a, int *size_b)
{
    int i;
    int max;

    i = 0;
    max = find_max(a, *size_a);
    while(i < max)
    {
        if(((max >> i) & 1) == 1)
            rotate_a(a, *size_a, 1);
        if(((max >> i) & 1) == 0)
        {
            push_b(a, b, size_a, size_b);
            (*size_a)--;
            (*size_b)++;
        }
    }
    while(*size_b > 0)
    {
        push_a(a, b, size_a, size_b);
        (*size_a)++;
        (*size_b)--;
    }
    //write(1, "radix done\n", 12);
}
