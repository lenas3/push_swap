/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/11/14 18:34:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quoted_arg(char **argv, char ***str)
{
	int i;
	char *tmp;

	i = 0;
	tmp = epur_str(argv[1], 0, 0);
	if (!tmp)
		err_exit();
	*str = ft_split(tmp, ' ');
	free(tmp);
	if (*str == NULL)
        err_exit(); 
    if ((*str)[0] == NULL)
    {
        free_split(*str); 
        err_exit();
    }
	while((*str)[i])
	{
		is_valid_char((*str)[i], NULL, *str);
		i++;
	}
}

void non_quoted_arg(char **argv, int *size, int argc)
{
	int i;

	i = 1;
	*size = argc - 1;
	while(i < argc)
	{
		is_valid_char(argv[i], NULL, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{	
	t_list main;
	char **split;

	if(argc < 2)
		return 0;
	split  = NULL;
	main.size_b = 0;
	main.size_a = 0;
	if(argc == 2)
	{
		quoted_arg(argv, &split);
		quoted_size(split, &main.size_a);
		allocate_mem(&main.a, &main.b, main.size_a);
		push_arg(main.size_a, split, &main.a);
		is_duplicate(main.a, main.size_a, main.b, split);
		is_sorted(main.a, main.size_a, main.b, split);
	}
	else 
	{
		main.size_a = argc - 1;
		allocate_mem(&main.a, &main.b, argc - 1);
		non_quoted_arg(argv, &main.size_a, argc);
		push_arg(argc - 1, &argv[1], &main.a);
		is_duplicate(main.a, main.size_a, main.b, split);
		is_sorted(main.a, main.size_a, main.b, split);	
	}
	
	sort_main(main.a, main.b, &main.size_a, &main.size_b);
	free_all(main.a, main.b, split);
	return 0;
}
