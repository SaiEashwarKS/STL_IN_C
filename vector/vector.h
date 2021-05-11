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
        iterator_vector_##type* (*find)(vector_##type* vector, type data); \
        void (*reserve)(vector_##type* vector, int cap); \
        void (*clear)(vector_##type* vector); \
        iterator_vector_##type* (*insert)(vector_##type* vector, iterator_vector_##type* it, type data); \
        iterator_vector_##type* (*erase)(vector_##type* vector, iterator_vector_##type* it1, iterator_vector_##type* it2); \
        iterator_vector_##type* (*begin)(vector_##type* vector); \
        iterator_vector_##type* (*end)(vector_##type* vector); \
        iterator_vector_##type* (*rbegin)(vector_##type* vector); \
        iterator_vector_##type* (*rend)(vector_##type* vector); \
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
    iterator_vector_##type* find_##type(vector_##type* vector, type data); \
    void reserve_##type(vector_##type* vector, int cap); \
    iterator_vector_##type* insert_##type(vector_##type* vector, iterator_vector_##type* it, type data); \
    iterator_vector_##type* erase_##type(vector_##type* vector, iterator_vector_##type* it1, iterator_vector_##type* it2); \
    void clear_##type(vector_##type* vector); \
    iterator_vector_##type* begin_##type(vector_##type* vector); \
    iterator_vector_##type* end_##type(vector_##type* vector); \
    iterator_vector_##type* rbegin_##type(vector_##type* vector); \
    iterator_vector_##type* rend_##type(vector_##type* vector); \
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
        &reserve_##type, \
        &clear_##type, \
        &insert_##type, \
        &erase_##type, \
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
    iterator_vector_##type* find_##type(vector_##type* vector, type data) \
    { \
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        for(int i=0; i<vector->size; ++i) \
        { \
            if(vector->data[i] == data) \
            { \
                it->iter = vector->data + i; \
                return it; \
            } \
        } \
        it->iter = vector->data + vector->size; \
        return it; \
    } \
    \
    void reserve_##type(vector_##type* vector, int cap) \
    { \
        if(vector->capacity == 0) \
        { \
            vector->capacity = cap; \
            vector->data = (type *)malloc(vector->capacity * sizeof(type)); \
        } \
        else if(vector->capacity < cap) \
        { \
            vector->capacity = cap; \
            vector->data = (type *)realloc(vector->data,vector->capacity * sizeof(type)); \
        } \
    } \
    \
    void clear_##type(vector_##type* vector) \
    { \
        vector->size = 0; \
    } \
    \
    iterator_vector_##type* insert_##type(vector_##type* vector, iterator_vector_##type* it, type data) \
    { \
        int pos = 0; \
        iterator_vector_##type* it2 = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it2->is_reverse = 0; \
        it2->iter = vector->data; \
        while(it2->iter < it->iter && pos<vector->size) \
        { \
            ++it2->iter; \
            ++pos; \
        } \
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
        int i=vector->size; \
        while(i != pos) \
        { \
            vector->data[i] = vector->data[i-1]; \
            --i; \
        } \
        vector->data[pos] = data; \
        ++vector->size; \
        it2->iter = vector->data; \
        return it2; \
    } \
    \
    iterator_vector_##type* erase_##type(vector_##type* vector, iterator_vector_##type* it1, iterator_vector_##type* it2) \
    { \
        int pos = 0; \
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        it->iter = vector->data; \
        while(it->iter < it1->iter && pos<vector->size) \
        { \
            ++it2->iter; \
            ++pos; \
        } \
        int count = 0; \
        while(it->iter < it2->iter) \
        { \
            ++count; \
            ++it->iter; \
        } \
        while(pos<vector->size-count) \
        { \
            vector->data[pos] = *(it2->iter); \
            ++pos; \
            ++it2->iter; \
        } \
        vector->size -= count; \
        return it; \
    } \
    iterator_vector_##type* begin_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        it->iter = vector->data; \
        return it; \
    } \
    iterator_vector_##type* end_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 0; \
        it->iter = vector->data+vector->size; \
        return it; \
    } \
    \
    iterator_vector_##type* rbegin_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 1; \
        it->iter = vector->data+vector->size-1; \
        return it; \
    } \
    iterator_vector_##type* rend_##type(vector_##type* vector) \
    {\
        iterator_vector_##type* it = (iterator_vector_##type*)malloc(sizeof(iterator_vector_##type)); \
        it->is_reverse = 1; \
        it->iter = vector->data-1; \
        return it; \
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

#ifndef RESERVE_FUNC
#define RESERVE_FUNC
#define reserve(vector, cap) (vector)->functions->reserve(vector, cap)
#endif

#ifndef CLEAR_FUNC
#define CLEAR_FUNC
#define clear(vector) (vector)->functions->clear(vector)
#endif

#ifndef INSERT_FUNC
#define INSERT_FUNC
#define insert(vector, it, data) (vector)->functions->insert(vector, it, data)
#endif

#ifndef ERASE_FUNC
#define ERASE_FUNC
#define erase(vector, it1, it2) (vector)->functions->erase(vector, it1, it2)
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

#define iter_vector_deref(it) *it->iter
#define iter_vector_equal(it1, it2) it1->iter == it2->iter
#define iter_vector_notequal(it1, it2) it1->iter != it2->iter
#define iter_vector_forward(it) it->iter = it->is_reverse ? it->iter-1 : it->iter+1 
#define iter_vector_backward(it) it->iter = it->is_reverse ? it->iter+1 : it->iter-1
#define iter_vector_add(it, n) it->iter = it->iter+n
#define iter_vector_subtract(it, n) it->iter = it->iter-n
#define iter_vector_lesser(it1, it2) it1->iter < it2->iter
#define iter_vector_greater(it1, it2) it1->iter > it2->iter
#define iter_vector_lesser_equal(it1, it2) it1->iter <= it2->iter
#define iter_vector_greater_equal(it1, it2) it1->iter >= it2->iter 

#endif