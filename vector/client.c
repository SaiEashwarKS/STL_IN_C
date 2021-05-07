#include"vector.h"
#include<stdio.h>

define_vector(int);

int main()
{
    vector(int)* a;
    a = new_vector(int, 3, 10);
    //printf("front: %d size: %d\n", front(a), size(a));
    for(int i=0; i< a->size; ++i)
        printf("%d ",a->data[i]);
    push_back(a, 30);
    for(int i=0; i< a->size; ++i)
        printf("%d ",a->data[i]);
}