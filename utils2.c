/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:45:57 by asay              #+#    #+#             */
/*   Updated: 2025/11/05 19:53:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quoted_size(char **str, int *size)
{
    int i;
    int j;
    int flag;

    i = 0;
    while(str[i])
    {
        j = 0;
        flag = 0;
        while(str[i][j])
        {
            if(((str[i][j] >= '0' && str[i][j] <= '9') 
                || str[i][j] == '+' || str[i][j] == '-') && !flag)
            {
                (*size)++;
                flag = 1;
            }
            else if(str[i][j] == ' ')
                flag = 0;
            j++;
        }
        i++;
    }
}
void allocate_mem(int **a, int **b, int size_a)
{
	*a = malloc(sizeof(int) * size_a);
	if(!*a)
        err_exit();
    *b = malloc(sizeof(int) * size_a);
	if(!*b)
    {
        free(*a);
        err_exit();
        //memory ayrılamama hatasında error yazmak dogru mu?
    }
}

void sort_main(int *a, int *b, int *size_a, int *size_b)
{
    if(*size_a == 1)
        return;
    else if(*size_a == 2)
        two_element_sort(a, *size_a);
    else if(*size_a == 3)
        three_element_sort(a, *size_a);
    else if(*size_a == 4)
        four_element_sort(a, b, size_a, size_b);
    else if(*size_a == 5)
        five_element_sort(a, b, size_a, size_b);
    else
        radix(a, b, size_a, size_b);
    //write(1, "sort_main done\n", 15);
}

void free_split(char **res)
{
    int i;

    i = 0;
    if (!res)
        return;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}
void free_all(int *a, int *b, char **split)
{
    if (a)
        free(a);
    if (b)
        free(b);
    free_split(split);
}