#include"list.h"
#include<stdio.h>

define_list(int);

int main()
{
    list(int)* a;
    a = new_list(int, 3, 10);
    printf("front: %d size: %d\n", front(a), size(a));
    push_front(a, 20);
    printf("front: %d size: %d\n", front(a), size(a));
}