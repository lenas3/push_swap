/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:46:57 by asay              #+#    #+#             */
/*   Updated: 2025/11/23 18:50:58 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(int *a, int size, t_list *main)
{
	int	i;

	i = 0;
	while (i < size - 1 && (a[i] < a[i + 1]))
		i++;
	if (i == size - 1)
	{
		free_all(main);
		return (0);
	}
	return (1);
}

void	limitcontrol(long a, char sign, t_list *main)
{
	if (sign == 1 && a > 2147483647)
	{
		free_all(main);
		err_exit();
	}
	if (sign == -1 && a > 2147483648)
	{
		free_all(main);
		err_exit();
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*epur_str(char *str, int i, int j)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			res[j++] = str[i++];
		else
		{
			if (j > 0)
				res[j++] = ' ';
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	if (j > 0 && res[j - 1] == ' ')
		j--;
	res[j] = '\0';
	return (res);
}
