/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:03:17 by asay              #+#    #+#             */
/*   Updated: 2025/10/23 22:31:35 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_arg(int argc, char **argv, int *arr)
{
	int i;

	i = 0;
	while(argc > 0)
	{
		arr[argc - 1] = ft_atoi(argv[i]);
		i++;
		argc--;
	}
}

int is_duplicate(char c, char *str)
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

int check_arg(char **argv)
{
	int i;
	long num; // neden long oldugunu arastır!!

	i = 0;
	while(argv[i])
	{
		num = ft_atoi(argv[i]);
		if(num < -2147483648 || num > 2147483647)
			err_exit();
		if(is_validnum(num)) // argümanın geçerl bir sayı oldugunu kontrol edecek bir fonksiyon yazılacak!!
			err_exit();			 
		if(is_duplicate(num, argv) == 1)
			err_exit();
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return (0);

	int a[argc - 1];
	push_arg(argc, argv, a);
}