#include <stdio.h>
#include "deque.h"
// #include "list.h"

define_deque(double);
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
void printkaro(deque_double* a)
{
	//printf("\nFRONT: %d SIZE:%d BACK:%d\n",a->front,a->size,a->back);
	deque_node_double* i=a->front;
	printf("\n");
	for(int j=0;j<a->size;++j)
	{printf("%lf, ",i->data);i=i->next;}
	printf("\n");
}
int main()
{
	deque(double)* a;//list(int)* b;
	a=new_deque(double,5,11.5);
	//b=new_list(int,5,10);
	printf("\nNON EMPTY: %d\n",empty(a));
	printf("\nSIZE: %d\n",size(a));
	printf("\nMAX SIZE: %d\n",max_size(a));
	printf("\nAT: %lf\n",at(a,4));
	printf("\nFRONT: %lf\n",front(a));
	insert(a,11);
	printf("\nAFTER SIZE: %d\n",size(a));
	printf("\nBACK: %lf\n",back(a));
	//remove(a);
	pop(a);
	printf("\nSIZE: %d\n",size(a));
	printf("\nBACK: %lf\n",back(a));
	//clear(a);
	//printkaro(b);
	printf("\nSIZE: %d\n",size(a));
	printf("HELLO WORLD\n");
	//ITERATOR
	iterator_deque(double)* b;
	b=begin(a);
	printf("\n YO YO IT %lf\n",iterator_deque_deref(b));
	while(iterator_deque_notequal(b,end(a)))
	{
		printf("\nIT %lf\n",iterator_deque_deref(b));
		iterator_deque_forward(b);
	}
	b=rbegin(a);
	printf("\nYO YO IT %lf\n",iterator_deque_deref(b));
	while(iterator_deque_notequal(b,rend(a)))
	{
		printf("\nIT %lf\n",iterator_deque_deref(b));
		iterator_deque_forward(b);
	}
}

