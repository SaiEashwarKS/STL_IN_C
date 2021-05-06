#ifndef DEQUE_H
#define DEQUE_H

#include<stdarg.h>
#include<stdlib.h>

//we give an initial definition for a datatype `type`
#define define_deque(type)\
\
	//declaration so that we can use it in the deque list
\
	struct functions_deque_##type;\
	typedef functions_deque_##type deque_funcs_##type;\
\
	/*\
	Here we define the main queue. We are allowing contiguous storage.\
	We initialize a ----|
					back (integer)->points to the first free location\
					front (integer)->points to the first filled location\
					size (integer)->holds the size of the array\
					maxie (integer)->will be max_size of the queue. We will initialize to 100000\
					queue (type)->array of elements of datatype `type`\
					funcallow (struct functions_deque_##type)->stores pointers to the allowable deque functions.\
	*/\
\
	typedef struct deque_##type\
	{\
		int front;int back;int size;\
		int maxie;\
		type queue[100001]\
		deque_funcs_##type* funcallow;\
	}deque_##type;\
\
	/*\
	We define all functions here\
	*/\
\
	typedef functions_deque_##type\
	{\
		//Capacity functions
\
		int (*size)(const deque_##type);\
		int (*max_size)(const deque_##type);\
		int (*empty)(const deque_##type);\
\
		//element access functions
\
		type (*at)(const deque_##type,int);\
		type (*front_ele)(const deque_##type);\
		type (*back_ele)(const deque_##type);\
		\
		//modifiers \
		//push_back is similar to insert, so both functions will reach here
		\
		void (*insert)(deque_##type,type);\
		void (*remove)(deque_##type);\
	};\

	//declares all the functions
	\
	int qsize_##type(const deque_##type* dec); \
	int qmax_size_##type(const deque_##type* dec); \
	int qempty_##type(const deque_##type* dec); \
	type qat_##type(const deque_##type* dec,int pos);\
	type qfront_ele_##type(const deque_##type* dec);\
	type qback_ele_##type(const deque_##type* dec);\
	void qinsert_##type(deque_##type* dec,type elem);\
	void qremove_##type(deque_##type* dec);\
\
	//Make a simmple function obj and point them to the declared functions
	\
	deque_funcs_##type funobj={\
		&qsize_##type, \
		&qmax_size_##type, \
		&qempty_##type, \
		&qat_##type,\
		&qfront_ele_##type,\
		&qback_ele_##type,\
		&qinsert_##type,\
		&qremove_##type\
	};\
\
	int qsize_##type(const deque_##type* dec)\
	{\
		return dec->size;\
	} \
\
	int qmax_size_##type(const deque_##type* dec)\
	{\
		return dec->maxie-1;\
	} \
\
	int qempty_##type(const deque_##type* dec)\
	{\
		return dec->size==0;\
	} \
\
	type qat_##type(const deque_##type* dec,int pos)\
	{\
		if (pos>=0 && pos<dec->size)\
			return dec->queue[(dec->front+pos)%(dec->maxie)];\
	}\
\
	type qfront_ele_##type(const deque_##type* dec)\
	{\
		if (dec->size)\
			return dec->queue[(dec->front)%(dec->maxie)];\
	}\
\
	type qback_ele_##type(const deque_##type* dec)\
	{\
		if (dec->size)\
			return dec->queue[(dec->back-1+dec->maxie)%(dec->maxie)];\
	}\
\
	void qinsert_##type(deque_##type* dec,type ele)\
	{\
		if (dec->size==dec->maxie-1)\
			return;\
		if (dec->size==0)\
		{\
			dec->front=0;\
			dec->back=0;\
		}\
		dec->queue[dec->back]=ele;\
		dec->back=(dec->back+1)%(dec->maxie);\
		++dec->size;\
	}\
\
	void qremove_##type(deque_##type* dec)\
	{\
		if (dec->size==0)\
		{\
			dec->front=-1;\
			dec->back=-1;\
			return;\
		}\
		dec->front=(dec->front+1)%(dec->maxie);\
		--dec->size;\
	}\
\
	deque_##type* new_deque_zero_##type()\
	{\
		deque_##type* queue = malloc(sizeof(deque_##type));\
		queue->front=-1;queue->back=-1;\
		queue->size=0;\
		queue->maxie=100001;\
		queue->funcallow=&funobj;\
		return queue;\
	}\
\
	deque_##type* new_deque_##type(int n, ...)\
	{\
		if (n==0)\
			return new_deque_zero_##type();\
		else\
		{\
			va_list args;\
			va_start(args,n);\
			type data = va_arg(args,type);\
			va_end(args);\
			deque_##type* queue = new_deque_zero_##type();\
			for (int i=0;i<n;++i)\
			{\
				qinsert_##type(queue,data);\
			}\
			return queue;\
		}\
	}\
\
	deque_##type* copy_deque_##type(deque_##type* deque2, ...)\
	{\
		deque_##type* queue = new_deque_zero_##type();\
		int firstloc=deque2->front;\
		for(int i=0;i<deque2->size;++i)\
		{\
			qinsert_##type(queue,deque2->queue[firstloc]);\
			firstloc=(firstloc+1)%(deque2->maxie);\
		}\
		return queue;\
	} \

#define deque(type) deque_##type
#define new_deque(type,argi,...) _Generic((argi),\
									  int: new_deque_##type,\
									  deque_##type*: copy_deque_##type)(argi,##__VA_ARGS__)
#define empty(queue) queue->funcallow->empty(queue)
#define size(queue) queue->funcallow->size(queue)
#define max_size(queue) queue->funcallow->max_size(queue)
#define at(queue,position) queue->funcallow->at(queue,position)
#define front(queue) queue->funcallow->front(queue)
#define back(queue) queue->funcallow->back(queue)
#define insert(queue,elem) queue->funcallow->insert(queue,elem)
#define pop(queue) queue->funcallow->remove(queue)
#define clear(queue) queue->size=0;queue->front=-1;queue->back=-1

#endif