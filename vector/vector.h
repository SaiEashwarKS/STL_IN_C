#ifndef VECTOR_H
#define VECTOR_H

#include<stdarg.h>
#include<stdlib.h>

#define define_vector(type) \
    \
    struct vector_##type; \
    struct vector_functions_pointers_##type; \
    struct iterator_vector_##type; \
    \
    struct vector_##type {\
            int size; \
            int capacity; \
            type *data; \
            struct vector_functions_pointers_##type* functions; \
        }; \
    typedef struct vector_##type vector_##type; \
    \
    struct iterator_vector_##type {\
        int is_reverse; \
        type* iter; \
    }; \
    typedef struct iterator_vector_##type iterator_vector_##type; \
    \
    struct vector_functions_pointers_##type {\
        int (*empty)(const vector_##type* vector); \
        int (*size)(const vector_##type* vector); \
        int (*capacity)(const vector_##type* vector); \
        void (*push_back)(vector_##type* vector, type data); \
        void (*pop_back)(vector_##type* vector); \
        type (*at)(vector_##type* vector, int pos); \
        type (*front)(vector_##type* vector); \
        type (*back)(vector_##type* vector); \
        int (*find)(vector_##type* vector, type data); \
        type* (*begin)(vector_##type* vector); \
        type* (*end)(vector_##type* vector); \
        type* (*rbegin)(vector_##type* vector); \
        type* (*rend)(vector_##type* vector); \
        void (*delete)(vector_##type** vector); \
    }; \
    typedef struct vector_functions_pointers_##type vector_functions_pointers_##type; \
    \
    \
    int empty_##type (const vector_##type* vector); \
    int size_##type (const vector_##type* vector); \
    int capacity_##type (const vector_##type* vector); \
    void push_back_##type(vector_##type* vector, type data); \
    void pop_back_##type(vector_##type* vector); \
    type at_##type(vector_##type* vector, int pos); \
    type front_##type(vector_##type* vector); \
    type back_##type(vector_##type* vector); \
    int find_##type(vector_##type* vector, type data); \
    type* begin_##type(vector_##type* vector); \
    type* end_##type(vector_##type* vector); \
    type* rbegin_##type(vector_##type* vector); \
    type* rend_##type(vector_##type* vector); \
    void delete_##type(vector_##type** vector); \
    \
    \
     vector_functions_pointers_##type vector_functions_##type = {\
        &empty_##type, \
        &size_##type, \
        &capacity_##type, \
        &push_back_##type, \
        &pop_back_##type, \
        &at_##type, \
        &front_##type, \
        &back_##type, \
        &find_##type, \
        &begin_##type, \
        &end_##type, \
        &rbegin_##type, \
        &rend_##type, \
        &delete_##type \
    }; \
    \
    \
    vector_##type* new_vector_##type(int n, ...); \
    vector_##type* new_vector_default_##type(); \
    vector_##type* new_vector_fill_##type(int n, va_list args); \
    vector_##type* new_vector_copy_##type(vector_##type* rhs, ...); \
    \
    \
    int empty_##type (const vector_##type* vector) \
    {\
        return vector->size == 0; \
    } \
    \
    int size_##type (const vector_##type* vector) \
    {\
        return vector->size; \
    } \
    \
    int capacity_##type (const vector_##type* vector) \
    {\
        return vector->capacity; \
    } \
    \
    void push_back_##type(vector_##type* vector, type data) \
    {\
        if(vector->capacity == 0) \
        { \
            vector->capacity = 1; \
            vector->data = (type *)malloc(vector->capacity * sizeof(type)); \
        } \
        else if(vector->size == vector->capacity) \
        { \
            vector->capacity *= 2; \
            vector->data = (type *)realloc(vector->data,vector->capacity * sizeof(type)); \
        } \
        vector->data[vector->size] = data; \
        ++vector->size; \
    } \
    \
    void pop_back_##type(vector_##type* vector) \
    { \
        --vector->size; \
    } \
    \
    type at_##type(vector_##type* vector, int pos) \
    { \
        return vector->data[pos]; \
    } \
    \
    type front_##type(vector_##type* vector) \
    { \
        return vector->data[0]; \
    } \
    \
    type back_##type(vector_##type* vector) \
    { \
        return vector->data[vector->size -1]; \
    } \
    \
    int find_##type(vector_##type* vector, type data) \
    { \
        for(int i=0; i<vector->size; ++i) \
        { \
            if(vector->data[i] == data) \
                return i; \
        } \
        return vector->size; \
    } \
    \
    type* begin_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        it->iter = vector->data; \
        return it->iter; \
    } \
    type* end_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        it->iter = vector->data+vector->size; \
        return it->iter; \
    } \
    \
    type* rbegin_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 1; \
        it->iter = NULL; \
        return it->iter; \
    } \
    type* rend_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 1; \
        it->iter = NULL; \
        return it->iter; \
    } \
    \
    void delete_##type(vector_##type** vector) \
    {\
        if((*vector)->capacity != 0) \
        {\
            free((*vector)->data); \
        } \
        free(*vector); \
        *vector = NULL; \
    } \
    \
    vector_##type* new_vector_##type(int n, ...) \
    {\
        if(n == 0) \
            return new_vector_default_##type(); \
        else \
        {\
            va_list args; \
            va_start (args, n); \
            vector_##type* res = new_vector_fill_##type(n, args); \
            va_end(args); \
            return res; \
        } \
    } \
    vector_##type* new_vector_default_##type() \
    {\
        vector_##type* vector = (vector_##type*)malloc(sizeof(vector_##type)); \
        vector->capacity = 0; \
        vector->size = 0; \
        vector->functions = &vector_functions_##type; \
        return vector; \
    } \
    \
    vector_##type* new_vector_fill_##type(int n, va_list args) \
    {\
        vector_##type* vector = new_vector_default_##type(); \
        type data = va_arg(args, type); \
        for(int i = 0; i < n; ++i) \
        {\
            push_back_##type(vector, data); \
        } \
        return vector; \
    } \
    vector_##type* new_vector_copy_##type(vector_##type* rhs, ...) \
    {\
        vector_##type* vector = new_vector_default_##type(); \
        for(int i=0; i < rhs->size; ++i) \
        { \
            push_back_##type(vector, rhs->data[i]); \
        } \
        return vector; \
    } \

#define vector(type) vector_##type
#define new_vector(type, arg1, ...) _Generic ((arg1), \
                                            int : new_vector_##type, \
                                            vector_##type* : new_vector_copy_##type) (arg1, ##__VA_ARGS__)

#ifndef DELETE_FUNC
#define DELETE_FUNC
#define delete(vector) (vector)->functions->delete(&vector)
#endif

#ifndef SIZE_FUNC
#define SIZE_FUNC
#define size(vector) (vector)->functions->size(vector)
#endif

#ifndef EMPTY_FUNC
#define EMPTY_FUNC
#define empty(vector) (vector)->functions->empty(vector)
#endif

#ifndef CAPACITY_FUNC
#define CAPACITY_FUNC
#define capacity(vector) (vector)->functions->capacity(vector)
#endif

#ifndef PUSH_BACK_FUNC
#define PUSH_BACK_FUNC
#define push_back(vector, data) (vector)->functions->push_back(vector, data)
#endif

#ifndef POP_BACK_FUNC
#define POP_BACK_FUNC
#define pop_back(vector) (vector)->functions->pop_back(vector)
#endif

#ifndef AT_FUNC
#define AT_FUNC
#define at(vector, pos) (vector)->functions->at(vector, pos)
#endif

#ifndef FRONT_FUNC
#define FRONT_FUNC
#define front(vector) (vector)->functions->front(vector)
#endif

#ifndef BACK_FUNC
#define BACK_FUNC
#define back(vector) (vector)->functions->back(vector)
#endif

#ifndef FIND_FUNC
#define FIND_FUNC
#define find(vector, data) (vector)->functions->find(vector, data)
#endif

#ifndef BEGIN_FUNC
#define BEGIN_FUNC
#define begin(vector) (vector)->functions->begin(vector)
#endif

#ifndef END_FUNC
#define END_FUNC
#define end(vector) (vector)->functions->end(vector)
#endif

#ifndef RBEGIN_FUNC
#define RBEGIN_FUNC
#define rbegin(vector) (vector)->functions->rbegin(vector)
#endif

#ifndef REND_FUNC
#define REND_FUNC
#define rend(vector) (vector)->functions->rend(vector)
#endif

//iterator
#define iterator_vector(type) iterator_vector_##type

//#define iter_vector_deref(it) it->iter->data

#define iter_vector_equal(it1, it2) it1->iter == it2->iter
#define iter_vector_notequal(it1, it2) it1->iter != it2->iter
#define iter_vector_forward(it) it->iter = it->iter!=NULL ? (it->is_reverse ? it->iter-1 : it->iter+1) : NULL
#define iter_vector_backward(it) it->iter = it->iter!=NULL ? (it->is_reverse ? it->iter+1 : it->iter-1) : NULL

#endif