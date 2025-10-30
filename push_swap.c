/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/10/30 16:30:44 by asay             ###   ########.fr       */
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

void quoted_arg(char **arg, char **str)
{
	int i;

	i = 0;
	str = ft_split(arg[1], ' ');
	while(str[i])
	{
		is_valid_char(str[i]);
		is_duplicate(str[i], i);
		i++;
	}
}

void non_quoted_arg(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		is_valid_char(str[i]);
		is_duplicate(str[i], i);
		i++;
	}
}
#include <stdio.h>

int main(int argc, char **argv)
{	
	int *a;
	int *b;
	char **split;
	int size_a;
	int size_b;

	
	
	b = malloc((ft_doublelen(argv)) * sizeof(int));
	if(!b)
		return ;
	if(argc < 2)
		return (0);
	if(argc == 2)
	{
		quoted_arg(argv, split);
		push_arg(argc, split, a);
	}	
	else
	{
		non_quoted_arg(argv);
		push_arg(argc, argv, a);
	}
	return 0;
}

