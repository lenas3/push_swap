/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:31:19 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 20:47:22 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_element(int *arr, int size)
{
    int i;
    int min_index;

    i = 0;
    min_index = 0;
    while(i < size)
    {
        if(arr[i] < arr[min_index])
            min_index = i;
        i++;
    }
    return (min_index);
}

void place_to_top(int *a, int size)
{
    int min;

    min = min_element(a, size);
    if(min == 0)
        return ;
    if(min <= size / 2)
    {
        while(min-- > 0)
            rotate_a(a, size, 1);
    }
    else
    {
        while(min++ < size)
            re_rotate_a(a, size, 1);
    }
}

void five_element_sort(int *a, int *b, int *a_size, int *b_size)
{
    int i;

    i = 0;
    while(i++ < 2)
    {
        min_element(a, *a_size);
        place_to_top(a, *a_size);
        push_b(a, b, a_size, b_size);
        b_size++;
        a_size--;
    }
    three_element_sort(a, *a_size);
    push_a(a, b, a_size, b_size);
    a_size++;
    b_size--;
    push_a(a, b, a_size, b_size);
    a_size++;
    b_size--;
}

void four_element_sort(int *a, int *b, int *a_size, int *b_size)
{
        min_element(a, *a_size);
        place_to_top(a, *a_size);
        push_b(a, b, a_size, b_size); 
        b_size++;
        a_size--;
        three_element_sort(a, *a_size);
        push_a(a, b, a_size, b_size);
        a_size++;
        b_size--;
}
