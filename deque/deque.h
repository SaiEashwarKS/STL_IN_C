#ifndef DEQUE_H
#define DEQUE_H

#include<stdarg.h>
#include<stdlib.h>

//we give an initial definition for a datatype `type`
#define define_deque(type) \
\
	struct functions_deque_##type; \
	\
	typedef struct deque_node_##type\
	{\
		struct deque_node_##type* next;\
		struct deque_node_##type* prev;\
		type data;\
	}deque_node_##type;\
	deque_node_##type* create_denode_##type(type data)\
	{\
		deque_node_##type* temp = malloc(sizeof(deque_node_##type));\
		temp->next=NULL;\
		temp->prev=NULL;\
		temp->data=data;\
		return temp;\
	}\
	 \
	typedef struct deque_##type \
	{ \
		deque_node_##type* front;deque_node_##type* back;\
		int size;int maxie; \
		struct functions_deque_##type* functions; \
	}deque_##type; \
\
	struct functions_deque_##type \
	{ \
		int (*size)(const deque_##type*); \
		int (*max_size)(const deque_##type*); \
		int (*empty)(const deque_##type*); \
		type (*at)(const deque_##type*,int);\
		type (*front)(const deque_##type*);\
		type (*back)(const deque_##type*);\
		void (*insert)(deque_##type*,type);\
		void (*remove)(deque_##type*);\
		deque_node_##type* (*begin)(const deque_##type*);\
		deque_node_##type* (*end)(const deque_##type*);\
	};\
\
	typedef struct functions_deque_##type deque_funcs_##type;\
	\
	int qsize_##type(const deque_##type* dec); \
	int qmax_size_##type(const deque_##type* dec); \
	int qempty_##type(const deque_##type* dec); \
	type qat_##type(const deque_##type* dec,int pos);\
	type qfront_ele_##type(const deque_##type* dec);\
	type qback_ele_##type(const deque_##type* dec);\
	void qinsert_##type(deque_##type* dec,type elem);\
	void qremove_##type(deque_##type* dec);\
	deque_node_##type* qbegin_##type(const deque_##type*);\
	deque_node_##type* qend_##type(const deque_##type*);\
\
	deque_funcs_##type funobj={\
		&qsize_##type, \
		&qmax_size_##type, \
		&qempty_##type, \
		&qat_##type,\
		&qfront_ele_##type,\
		&qback_ele_##type,\
		&qinsert_##type,\
		&qremove_##type,\
		&qbegin_##type,\
		&qend_##type\
	};\
\
	int qsize_##type(const deque_##type* dec)\
	{\
		return dec->size;\
	} \
\
	int qmax_size_##type(const deque_##type* dec)\
	{\
		return dec->maxie;\
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
			{\
				int i=0;\
				deque_node_##type* temp=dec->front;\
				\
				while(i<pos)\
					{\
						++i;\
						temp=temp->next;\
					}\
				return temp->data;\
			}\
	}\
\
	type qfront_ele_##type(const deque_##type* dec)\
	{\
		if (dec->size)\
			return dec->front->data;\
	}\
\
	type qback_ele_##type(const deque_##type* dec)\
	{\
		if (dec->size)\
			return dec->back->data;\
	}\
\
	void qinsert_##type(deque_##type* dec,type ele)\
	{\
		if (dec->size==dec->maxie)\
			return;\
		if (dec->size==0)\
		{\
			dec->back=create_denode_##type(ele);\
			dec->front=dec->back;\
		}\
		else\
		{\
			dec->back->next=create_denode_##type(ele);\
			dec->back->next->prev=dec->back;\
			dec->back=dec->back->next;\
		}\
		++dec->size;\
	}\
\
	void qremove_##type(deque_##type* dec)\
	{\
		if (dec->size==0)\
		{\
			dec->front=NULL;\
			dec->back=NULL;\
			return;\
		}\
		dec->front=dec->front->next;\
		--dec->size;\
	}\
	deque_node_##type* qbegin_##type(const deque_##type* dec)\
	{\
		if (dec->size==0)\
			return NULL;\
		return dec->front;\
	}\
	deque_node_##type* qend_##type(const deque_##type* dec)\
	{\
		if (dec->size==0)\
			return NULL;\
		return dec->back->next;\
	}\
\
	deque_##type* new_deque_zero_##type()\
	{\
		deque_##type* queue = malloc(sizeof(deque_##type));\
		queue->front=NULL;queue->back=NULL;\
		queue->size=0;\
		queue->maxie=100001;\
		queue->functions=&funobj;\
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
		deque_node_##type* firstloc=deque2->front;\
		for(int i=0;i<deque2->size;++i)\
		{\
			qinsert_##type(queue,firstloc->data);\
			firstloc=firstloc->next;\
		}\
		return queue;\
	} \

#define deque(type) deque_##type
#define new_deque(type,argi,...) _Generic((argi),\
									  int: new_deque_##type,\
									  deque_##type*: copy_deque_##type)(argi,##__VA_ARGS__)
#ifndef EMPTY_FUNC
#define EMPTY_FUNC							  
#define empty(queue) (queue)->functions->empty(queue)
#endif

#ifndef BEGIN_FUNC
#define BEGIN_FUNC							  
#define begin(queue) (queue)->functions->begin(queue)
#endif

#ifndef END_FUNC
#define END_FUNC							  
#define end(queue) (queue)->functions->end(queue)
#endif


#ifndef SIZE_FUNC
#define SIZE_FUNC
#define size(queue) (queue)->functions->size(queue)
#endif

#ifndef MAX_SIZE_FUNC
#define MAX_SIZE_FUNC
#define max_size(queue) (queue)->functions->max_size(queue)
#endif

#ifndef AT_FUNC
#define AT_FUNC
#define at(queue,position) (queue)->functions->at(queue,position)
#endif

#ifndef FRONT_FUNC
#define FRONT_FUNC
#define front(queue) (queue)->functions->front(queue)
#endif

#ifndef BACK_FUNC
#define BACK_FUNC
#define back(queue) (queue)->functions->back(queue)
#endif

#ifndef INSERT_FUNC
#define INSERT_FUNC
#define insert(queue,elem) (queue)->functions->insert(queue,elem)
#endif

#ifndef POP_FUNC
#define POP_FUNC
#define pop(queue) (queue)->functions->remove(queue)
#endif

#ifndef CLEAR_FUNC
#define CLEAR_FUNC
#define clear(queue) (queue)->size=0;queue->front=NULL;queue->back=NULL
#endif

#endif