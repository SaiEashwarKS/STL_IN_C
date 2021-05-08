#include <stdio.h>
#include "deque.h"
// #include "list.h"
typedef struct user
{
	int id;int age;
}user;
define_deque(user);
//define_list(int);

/*
void printkaro(deque_int* a)//this is for the array type implementation
{
	//printf("\nFRONT: %d SIZE:%d BACK:%d\n",a->front,a->size,a->back);
	int i=a->front;
	printf("\n");
	for(int j=0;j<a->size;++j)
	{printf("%d, ",a->queue[(i+j)%a->maxie]);
	printf("\n");
}
*/
// void printkaro(deque_double* a)
// {
// 	//printf("\nFRONT: %d SIZE:%d BACK:%d\n",a->front,a->size,a->back);
// 	deque_node_double* i=a->front;
// 	printf("\n");
// 	for(int j=0;j<a->size;++j)
// 	{printf("%lf, ",i->data);i=i->next;}
// 	printf("\n");
// }
int main()
{
	deque(user)* a;//list(int)* b;
	user g={5,45};
	a=new_deque(user,5,g);
	//b=new_list(int,5,10);
	printf("\nNON EMPTY: %d\n",empty(a));
	printf("\nSIZE: %d\n",size(a));
	printf("\nMAX SIZE: %d\n",max_size(a));
	printf("\nAT: %d\n",at(a,4).age);
	printf("\nFRONT: %d\n",front(a).age);
	user k={6,46};
	insert(a,k);
	printf("\nAFTER SIZE: %d\n",size(a));
	printf("\nBACK: %d\n",back(a).age);
	//remove(a);
	pop(a);
	printf("\nSIZE: %d\n",size(a));
	printf("\nBACK: %d\n",back(a).age);
	//clear(a);
	//printkaro(b);
	printf("\nSIZE: %d\n",size(a));
	printf("HELLO WORLD\n");
	//ITERATOR
	iterator_deque(user)* b;
	b=begin(a);
	printf("\nFORWARD IT %d\n",iterator_deque_deref(b).age);
	while(iterator_deque_notequal(b,end(a)))
	{
		printf("%d, ",iterator_deque_deref(b).age);
		iterator_deque_forward(b);
	}
	b=rbegin(a);
	printf("\nBACKWARD IT %d\n",iterator_deque_deref(b).age);
	while(iterator_deque_notequal(b,rend(a)))
	{
		printf("%d, ",iterator_deque_deref(b).age);
		iterator_deque_forward(b);
	}
	printf("\n");
}

