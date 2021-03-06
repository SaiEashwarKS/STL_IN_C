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



int my_compare(int a)
{
    return a > 20;
}

int greater_equal(int a, int b)
{
    return a >= b;
}



int main()
{
    printf("\ndefault ctor\n");
    list(char) *c = new_list(char, 0); //default ctor
    push_back(c, 'a');
    push_back(c, 'b');
    display_char(c);
    printf("\ncopy ctor\n");
    list(char) *c2 = new_list(char, c); //copy ctor
    display_char(c2);
    delete (c); //delete
    if (c == NULL)
        printf("c is null\n");

    printf("\nfill ctor\n");
    list(int) * a;
    a = new_list(int, 2, 10); //fill ctor
    display_int(a);

    //push
    printf("\npush\n");
    push_front(a, 20);
    push_back(a, 30);
    push_back(a, 40);
    display_int(a);

    //pop
    printf("\npop\n");
    pop_front(a);
    display_int(a);
    pop_back(a);
    display_int(a);

    //insert
    printf("\ninsert\n");
    insert(a, iter_list_forward(begin(a)), 1, 20);
    display_int(a);

    //remove
    printf("\nremove\n");
    printf("before removing : ");
    display_int(a);
    remove_list(a, 10);
    remove_list(a, 200);
    printf("after removing 10 and 200 : ");
    display_int(a);

    //remove_if
    printf("\nremove_if\n");
    push_back(a, 10);
    push_back(a, 40);
    printf("before removing : ");
    display_int(a);
    remove_if_list(a, &my_compare);
    printf("after removing using my_compare (remove all elements greater than 20): ");
    display_int(a);

    //find
    printf("\nfind\n");
    printf("list : ");
    display_int(a);
    iterator_list(int)* res = find(a, 200);
    if(res == NULL) printf("200 not found\n");
    res = find(a, 20);
    if(res != NULL) printf("found %d\n", iter_list_deref(res));

    //find_if
    printf("\nfind elements greater than 20\n");
    printf("list : ");
    display_int(a);
    res = find_if(a, &my_compare);
    if(res != NULL) printf("found %d\n", iter_list_deref(res));

    //forward iterator
    push_front(a, 10);
    push_back(a, 30);
    printf("\nforward iterator\n");
    iterator_list(int) *it = begin(a);
    while (iter_list_notequal(it, end(a)))
    {
        printf("%d ", iter_list_deref(it));
        iter_list_forward(it);
    }
    printf("\n");

    //reverse iterator
    printf("\nreverse iterator\n");
    iterator_list(int) *it2 = rbegin(a);
    while (iter_list_notequal(it2, rend(a)))
    {
        printf("%d ", iter_list_deref(it2));
        iter_list_forward(it2);
    }
    printf("\n");

    //reverse
    printf("\nreverse\n");
    printf("a : ");
    display_int(a);
    printf("reverse of a : ");
    reverse(a);
    display_int(a);

    //sort
    printf("\nsort\n");
    printf("Before sort : ");
    display_int(a);
    sort(a);
    printf("after sort : ");
    display_int(a);

    //sort_by
    printf("\nsort in descending\n");
    printf("Before sort : ");
    display_int(a);
    sort_by(a, &greater_equal);
    printf("after sort : ");
    display_int(a);

    //clear
    printf("\nclear\n");
    printf("before clearing : ");
    display_int(a);
    printf("size : %d\n", size(a));
    clear(a);
    printf("after clearing : ");
    display_int(a);
    printf("size : %d\n", size(a));

}