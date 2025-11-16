/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/11/16 19:06:21 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quoted_arg(char **argv, char ***str, t_list *main)
{
	int i;
	char *tmp;

	i = 0;
	tmp = epur_str(argv[1], 0, 0);
	*str = ft_split(tmp, ' ');
	free(tmp);
	if (*str == NULL)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
    if ((*str)[0] == NULL)
    {
        free(*str); 
		write(1, "Error\n", 6);
		exit(1);
	}
	while((*str)[i])
	{
		is_valid_char((*str)[i], main);
		i++;
	}
}

void non_quoted_arg(char **argv, int *size, int argc)
{
	int i;
	(void)argv;
	i = 1;
	*size = argc - 1;
	// while(i < argc)
	// {
	// 	is_valid_char(argv[i]);
	// 	i++;
	// }
}

int main(int argc, char **argv)
{	
	t_list main;

	if(argc < 2)
		return 0;
	main.split = NULL;
	main.a = NULL;
	main.b = NULL;
	main.size_b = 0;
	main.size_a = 0;
	if(argc == 2)
	{
		quoted_arg(argv, &main.split, &main);
		quoted_size(argv, &main.size_a);
		allocate_mem(&main.a, &main.b, main.size_a);
		push_arg(main.size_a, main.split, &main.a, &main);
		is_duplicate(main.a, main.size_a, &main);
		if(!(is_sorted(main.a, main.size_a)))
			return 0;
	}
	else 
	{
		main.size_a = argc - 1;
		allocate_mem(&main.a, &main.b, argc - 1);
		non_quoted_arg(argv, &main.size_a, argc);
		push_arg(argc - 1, &argv[1], &main.a, &main);
		is_duplicate(main.a, main.size_a, &main);
		if(!(is_sorted(main.a, main.size_a)))
			return 0;	
	}
	
	sort_main(main.a, main.b, &main.size_a, &main.size_b);
	free_all(&main);
	return 0;
}
