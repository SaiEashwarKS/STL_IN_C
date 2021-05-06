#include"list.h"
#include<stdio.h>

define_list(int);
define_list(char);

void display_int(list(int)* list)
{
    list_node_int* temp = list->head;
    for(int i = 0; i < size(list); ++i)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_char(list(char)* list)
{
    list_node_char* temp = list->head;
    for(int i = 0; i < size(list); ++i)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    list(int)* a;
    a = new_list(int, 3, 10);
    //printf("front: %d size: %d\n", front(a), size(a));
    display_int(a);
    push_front(a, 20);
    push_back(a, 30);
    display_int(a);

    list(char)* c = new_list(char, 0);
    display_char(c);
    push_back(c, 'a');
    push_back(c, 'b');
    push_front(c, 'c');
    display_char(c);
}