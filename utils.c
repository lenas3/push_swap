/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:46:40 by asay              #+#    #+#             */
/*   Updated: 2025/11/05 23:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void err_exit()
{
	write(1, "Error\n", 6);

	exit(EXIT_FAILURE);
}

int ft_atoi(const char *str)
{
    int i = 0;
    long result = 0;
    int sign = 1;

	while(str[i] &&( str[i] == ' ' ||  str[i] == '\t' || str[i] == '\r' ||
	        str[i] == '\f'|| str[i] == '\n' || str[i] == '\v'))
	    i++;

	while(str[i] == '+' || str[i] == '-')
	{
	    if(str[i] == '-')
	        sign *= -1;
	    i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
	    result = result * 10 + (str[i] - '0');
	    i++;
	}
	if(result * sign < -2147483648 || result * sign > 2147483647)
		err_exit();
	return (sign * result);
}

void push_arg(int argc, char **argv, int **arr)
{
	int i;

	i = 0;
	while(i < argc)
	{
		(*arr)[i] = ft_atoi(argv[i]);
		i++;
	}
	//write(1, "push_arg done\n", 15);
}
