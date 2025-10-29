#include "push_swap.h"

void re_rotate_a(int *a, int size, int flag)
{
    int temp;
    int i;

    i = size - 1;
    temp = a[size - 1];  
    while(i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = temp;
    if(flag)
        write(1, "rra\n", 4);
}

void re_rotate_b(int *b, int size, int flag)
{
    int temp;
    int i;

    i = size - 1;
    temp = b[size - 1];  
    while(i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[0] = temp;
    if(flag)
        write(1, "rrb\n", 4);
}

void re_rotate_both(int *a, int *b, int size)
{
    re_rotate_a(a, size, 0);
    re_rotate_b(b, size, 0);
    write(1, "rrr\n", 4);
}