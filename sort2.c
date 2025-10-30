/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:31:19 by asay              #+#    #+#             */
/*   Updated: 2025/10/30 19:31:24 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *copy_array(const int *arr, int size)
{
	char	*dupe;
	size_t	i;

	i = 0;
	if (!dupe)
		return (NULL);
	while (i < size)
	{
		dupe[i] = arr[i];
		i++;
	}
	return (dupe);
}

void sort_array(int *arr, int size)
{
    int i;
    int temp;
    int *dupe;

    i = 0;
    while(i < size - 1)
    {
        if(dupe[i] > dupe[i + 1])
        {
            temp = dupe[i];
            dupe[i] = dupe[i + 1];
            dupe[i + 1] = temp;
            i = 0;
        }
        i++;
    }
}

void index(int *arr, int size)
{
    int i;

    sort_array(arr, size);
    
}