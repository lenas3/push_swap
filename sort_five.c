/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:31:19 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 01:43:46 by marvin           ###   ########.fr       */
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
    if(min <= size / 2)
    {
        while(min-- > 0)
            rotate_a(a, size, 1);
    }
    if(min > size / 2)
    {
        while(min++ > size)
            re_rotate_a(a, size, 1);
    }
}
void sort_five(int *a, int *b, int a_size, int b_size)
{
    int i;

    i = 0;
    if(a_size == 4)
    {
        min_element(a, a_size);
        place_to_top(a, a_size);
        push_b(a, b, a_size, b_size); 
        three_sort(a, b, a_size);
        push_a(a, b, a_size, b_size);
        return ;
    }
    else 
    {
        while(i++ < 2)
        {
            min_element(a, a_size);
            place_to_top(a, a_size);
            push_b(a, b, a_size, b_size); 
        }
        three_sort(a, b, a_size);
        push_a(a, b, a_size, b_size);
        push_a(a, b, a_size, b_size);
        return ;   
    }   
}
// push_a ve push_b kullanıldıktan sonra a_size ve b_size güncellenmeli.