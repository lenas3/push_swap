/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/11/01 21:36:00 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_valid_char(char *str)
{
    int i;

    i = 0;
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
	    err_exit();
    while(str[i])
    {
		if(!(str[i] >= '0' && str[i] <= '9') || str[i] != ' ')
            err_exit();
        i++;
    }
}

int is_duplicate(char *str, char c)
{
	int i;
	int dup;

	i = 0;
	dup = 0;
	while(str[i])
	{
		if(str[i] == c)
			dup++;
		i++;	
	}
	if(dup != 1)
		return 1;
	return 0;
}

void quoted_arg(char **argv, char **str)
{
	int i;

	i = 0;
	str = ft_split(argv[1], ' ');
	while(str[i])
	{
		is_valid_char(str[i]);
		is_duplicate(str[i], i);
		i++;
	}
}

void non_quoted_arg(char **str, int *size, int argc)
{
	int i;

	i = 0;
	*size = argc - 1;
	while(str[i])
	{
		is_valid_char(str[i]);
		is_duplicate(str[i], i);
		i++;
	}
}

int main(int argc, char **argv)
{	
	int *a;
	int *b;
	char **split;
	int *size_a;
	int *size_b;

	split  = NULL;
	size_a = NULL;
	size_b = NULL;
	if(argc < 2)
		return (0);
	if(argc == 2)
	{
		quoted_size(argv, size_a);
		quoted_arg(argv, split);
		allocate_mem(&a, &b, *size_a);
		push_arg(argc, split, a);
	}
	non_quoted_arg(argv, size_a, argc);
	allocate_mem(&a, &b, *size_a);
	push_arg(argc, argv, a);
	sort_main(a, b, size_a, size_b);
	free_all(a, size_a, size_b);
	return 0;
}
