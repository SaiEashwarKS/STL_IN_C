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
    printf("\ninsert\n");
    iterator_vector(int) *it4 = begin(a);
    iter_vector_add(it4, 4);
    it4 = insert(a, it4, 50);
    iter_vector_add(it4, 3);
    it4 = insert(a, it4, 40);
    display_int(a);

    //find
    printf("\nfind\n");
    display_int(a);
    iterator_vector(int) *it5 = find(a, 50);
    if(iter_vector_notequal(it5, end(a)))
        printf("Found 50\n");
    else printf("50 not found\n");
    it5 = find(a, 70);
    if(iter_vector_notequal(it5, end(a)))
        printf("Found 70\n");
    else printf("70 not found\n");

    //at
    printf("\nat\n");
    display_int(a);
    printf("Element at position 2: %d\n", at(a, 2));

    //size
    printf("\nsize\n");
    display_int(a);
    printf("Size of a: %d\n", size(a));

    //capacity
    printf("\ncapacity\n");
    printf("capacity of a: %d\n", capacity(a));

    //reserve
    printf("\nreserve\n");
    printf("reserve 16\n");
    reserve(a, 16);
    printf("capacity of a: %d\n", capacity(a));

    //front&back
    printf("\nfront & back\n");
    display_int(a);
    printf("front of a: %d\nback of a: %d\n", front(a), back(a));

    //forward iterator
    printf("\nforward iterator\n");
    iterator_vector(int) *it = begin(a);
    while (iter_vector_notequal(it, end(a)))
    {
        printf("%d ", iter_vector_deref(it));
        iter_vector_forward(it);
    }
    printf("\n");

    //reverse iterator
    printf("\nreverse iterator\n");
    iterator_vector(int) *it2 = rbegin(a);
    while (iter_vector_notequal(it2, rend(a)))
    {
        printf("%d ", iter_vector_deref(it2));
        iter_vector_forward(it2);
    }
    printf("\n");

    //random access iterator
    printf("\nrandom access iterator\n");
    iterator_vector(int) *it3 = begin(a);
    while(iter_vector_lesser(it3, end(a)))
    {
        printf("%d ", iter_vector_deref(it3));
        iter_vector_forward(it3);
    }
    printf("\n");
    it3 = begin(a);
    iter_vector_add(it3, 3);
    printf("it+3: %d\n", iter_vector_deref(it3));
    iter_vector_subtract(it3, 2);
    printf("it-2: %d\n", iter_vector_deref(it3));

    //erase
    printf("\nerase\n");
    printf("before erasing : ");
    display_int(a);
    it2 = begin(a);
    it3 = begin(a);
    iter_vector_add(it3, 3);
    erase(a, it2, it3);
    printf("after erasing from 0 to 3 : ");
    display_int(a);

    //clear
    printf("\nclear\n");
    printf("Vector: ");
    display_int(a);
    printf("After clear: ");
    clear(a);
    display_int(a);
}