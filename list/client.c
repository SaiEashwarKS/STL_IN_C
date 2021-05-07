#include "list.h"
#include <stdio.h>
#include <assert.h>

define_list(int);
define_list(char);

void display_int(list(int) * list)
{
    list_node_int *temp = list->head;
    for (int i = 0; i < size(list); ++i)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_char(list(char) * list)
{
    list_node_char *temp = list->head;
    for (int i = 0; i < size(list); ++i)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("\n1\n");
    list(char) *c = new_list(char, 0); //default ctor
    push_back(c, 'a');
    push_back(c, 'b');
    display_char(c);
    printf("\n2\n");
    list(char) *c2 = new_list(char, c); //copy ctor
    display_char(c2);
    delete (c); //delete
    if (c == NULL)
        printf("c is null\n");

    printf("\n4\n");
    list(int) * a;
    a = new_list(int, 2, 10); //fill ctor
    display_int(a);

    //push
    printf("\n5\n");
    push_front(a, 20);
    push_back(a, 30);
    push_back(a, 40);
    display_int(a);

    //pop
    printf("\n6\n");
    pop_front(a);
    display_int(a);
    pop_back(a);
    display_int(a);

    //insert
    printf("\n7\n");
    insert(a, iter_list_forward(begin(a)), 1, 20);
    display_int(a);

    //remove
    printf("\n8\n");
    remove_list(a, 10);
    remove_list(a, 200);
    display_int(a);

    //find
    assert(find(a, 200) == NULL);
    assert(find(a, 20) != NULL);

    //forward iterator
    push_front(a, 10);
    printf("\n9\n");
    iterator_list(int) *it = begin(a);
    printf("\nforward iteration\n");
    while (iter_list_notequal(it, end(a)))
    {
        printf("%d ", iter_list_deref(it));
        iter_list_forward(it);
    }
    printf("\n");

    //reverse iterator
    printf("\n10\n");
    iterator_list(int) *it2 = rbegin(a);
    printf("\reverse iteration\n");
    while (iter_list_notequal(it2, rend(a)))
    {
        printf("%d ", iter_list_deref(it2));
        iter_list_forward(it2);
    }
    printf("\n");
}