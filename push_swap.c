/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/11/02 15:31:16 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_valid_char(char *str)
{
    int i;

    i = 0;
	if(!str || str[0] == '\0')
		err_exit();
	if (str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
	    err_exit();
    while(str[i])
    {
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
            err_exit();
        i++;
    }
	//write(1, "is_valid_char done \n", 21);
}

void is_duplicate(int *arr, int size, int *b, char **split)
{
	int i;
	int j;

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[i] == arr[j])
			{
				free(arr);
				free(b);
				free_split(split);
				err_exit();
			}
			j++;
		}
		i++;
	}
	return ;
}

void quoted_arg(char **argv, char ***str)
{
	int i;

	i = 0;
	*str = ft_split(argv[1], ' ');
	while((*str)[i])
	{
		is_valid_char((*str)[i]);
		i++;
	}
	//write(1, "quoted_arg done\n", 17);
}

void non_quoted_arg(char **argv, int *size, int argc)
{
	int i;

	i = 1; // argv[1]'den başlasın diye.
	*size = argc - 1;
	while(i < argc)
	{
		is_valid_char(argv[i]);
		i++;
	}
	//write(1, "non_quoted_arg done\n", 21);
}

int main(int argc, char **argv)
{	
	int *a;
	int *b;
	char **split;
	int size_a;
	int size_b;

	if(argc < 2)
		err_exit();
	split  = NULL;
	size_b = 0;
	if(argc == 2)
	{
		quoted_size(argv, &size_a);
		allocate_mem(&a, &b, size_a);
		quoted_arg(argv, &split);
		push_arg(size_a, split, &a);
		is_duplicate(a, size_a, b, split);
	}
	else
	{
		size_a = argc - 1;
		allocate_mem(&a, &b, argc - 1);
		non_quoted_arg(argv, &size_a, argc);
		push_arg(argc - 1, &argv[1], &a);
		is_duplicate(a, size_a, b, split);
	}
	sort_main(a, b, &size_a, &size_b);
	free(a);
	free(b);
	free_split(split);
	return 0;
}
