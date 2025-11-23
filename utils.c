/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:46:40 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 18:41:01 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_skip_control(t_list *main, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == '\v'))
		i++;
	if (str[i] == '\0' || (str[i] < '0' || str[i] > '9'))
	{
		free_all(main);
		err_exit();
	}
}

int	ft_atoi(const char *str, t_list *main, int i)
{
	long	result;
	int		sign;

	i = 0;
	sign = 0;
	result = 0;
	init_skip_control(main, (char *)str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		limitcontrol(result, sign, main);
		i++;
	}
	if (str[i] != '\0')
	{
		free_all(main);
		err_exit();
	}
	return (sign * result);
}

void	is_valid_char(char *str, t_list *main)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		err_exit();
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == ' ' || str[i] == '-' || str[i] == '+'))
		{
			free_all(main);
			err_exit();
		}
		i++;
	}
}

void	is_duplicate(int *arr, int size, t_list *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free_all(main);
				err_exit();
			}
			j++;
		}
		i++;
	}
}

void	push_arg(int argc, char **argv, int **arr, t_list *main)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		(*arr)[i] = ft_atoi(argv[i], main, 0);
		i++;
	}
}
