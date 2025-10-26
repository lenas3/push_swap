/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:46:40 by asay              #+#    #+#             */
/*   Updated: 2025/10/26 20:10:44 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void err_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    char *s;

    while(str[i] && str[i] == ' ' ||  str[i] == '\t' || str[i] == '\r' ||
            str[i] == '\f'|| str[i] == '\n' || str[i] == '\v')
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
    return (sign * result);
}

void is_arg_num(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9') || str[i] != ' ')
            return ;
        i++;
    }
}