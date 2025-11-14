#include "push_swap.h"

void is_sorted(int *a, int size, int *b, char **split)
{
    int i;

    i = 0;
    while (i < size - 1 && (a[i] < a[i + 1]))
        i++;
    
    if (i == size - 1)
    {
        free_all(a, b, split);
        exit(0);
    }
}

void limitcontrol(long a, char sign)
{
    if (sign == 1 && a > 2147483647)
            err_exit();
    if (sign == -1 && a > 2147483648)
            err_exit();
}

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *epur_str(char *str, int i, int j)
{
    int len;
    char *res;

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









