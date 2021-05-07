#include"vector.h"
#include<stdio.h>

define_vector(int);
define_vector(char);

void display_int(vector(int) *vector)
{
    for(int i=0; i< vector->size; ++i)
    {
        printf("%d ",vector->data[i]);
    }
    printf("\n");
}

void display_char(vector(char) *vector)
{
    for(int i=0; i< vector->size; ++i)
    {
        printf("%c ",vector->data[i]);
    }
    printf("\n");
}

int main()
{
    printf("\ndefault ctor\n");
    vector(char) *c = new_vector(char, 0); //default ctor
    push_back(c, 'a');
    push_back(c, 'b');
    display_char(c);
    printf("\ncopy ctor\n");
    vector(char) *c2 = new_vector(char, c); //copy ctor
    display_char(c2);

    //delete
    printf("\ndelete\n");
    delete (c);
    if (c == NULL)
        printf("c is null\n");

    printf("\nfill ctor\n");
    vector(int) * a;
    a = new_vector(int, 2, 10); //fill ctor
    display_int(a);

    //push
    printf("\npush\n");
    push_back(a, 30);
    push_back(a, 40);
    display_int(a);

    //pop
    printf("\npop\n");
    display_int(a);
    pop_back(a);
    display_int(a);

    //insert
    //printf("\ninsert\n");
    //insert(a, iter_list_forward(begin(a)), 1, 20);
    //display_int(a);

    //at
    printf("\nfind\n");
    display_int(a);
    printf("Find 50: %d\n", find(a, 50));

    /*//erase
    printf("\nerase\n");
    printf("before removing : ");
    display_int(a);
    remove_list(a, 10);
    remove_list(a, 200);
    printf("after removing 10 and 200 : ");
    display_int(a);*/

    //at
    printf("\nat\n");
    display_int(a);
    printf("Elelment at position 2: %d\n", at(a, 2));

    //size
    printf("\nsize\n");
    display_int(a);
    printf("Size of a: %d\n", size(a));

    //size
    printf("\ncapacity\n");
    printf("capacity of a: %d\n", capacity(a));

    //at
    printf("\nat\n");
    display_int(a);
    printf("Elelment at position 2: %d\n", at(a, 2));

    //front&back
    printf("\nfront & back\n");
    display_int(a);
    printf("front of a: %d\nback of a: %d\n", front(a), back(a));

    //forward iterator
    push_back(a, 40);
    printf("\nforward iterator\n");
    iterator_vector(int) *it = begin(a);
    printf("forward iteration\n");
    while (iter_list_notequal(it, end(a)))
    {
        printf("%d ", *it);
        iter_list_forward(it);
    }
    printf("\n");
}