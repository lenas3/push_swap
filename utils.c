/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:46:40 by asay              #+#    #+#             */
/*   Updated: 2025/11/14 18:34:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void err_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_atoi(const char *str)
{
	int i = 0;
	long result = 0;
	int sign = 1;

    while(str[i] &&( str[i] == ' ' ||  str[i] == '\t' || str[i] == '\r' ||
            str[i] == '\f'|| str[i] == '\n' || str[i] == '\v'))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0' || (str[i] < '0' || str[i] > '9'))
        err_exit();
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		limitcontrol(result, sign);
		i++;
	}
	if (str[i] != '\0')
        err_exit();
	return (sign * result);
}

void is_valid_char(char *str, int *b, char **split)
{
    int i;

    i = 0;
	if(!str || str[0] == '\0')
	{
		free_all(NULL, b, split);
		err_exit();
	}
    while(str[i])
    {
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-' || str[i] == '+'))
		{
			free_all(NULL, b, split);
			err_exit();
		}
        i++;
    }
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
			if(arr[i] == arr[j] )
			{
				free_all(arr, b, split);
				err_exit();
			}
			j++;
		}
		i++;
	}
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
}
