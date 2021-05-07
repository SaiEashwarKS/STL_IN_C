#ifndef VECTOR_H
#define VECTOR_H

#include<stdarg.h>
#include<stdlib.h>

#define define_vector(type) \
    \
    struct vector_##type; \
    struct vector_functions_pointers_##type; \
    \
    struct vector_##type {\
            int size; \
            int capacity; \
            type *data; \
            struct vector_functions_pointers_##type* functions; \
        }; \
    typedef struct vector_##type vector_##type; \
    \
    struct vector_functions_pointers_##type {\
        int (*empty)(const vector_##type* vector); \
        int (*size)(const vector_##type* vector); \
        int (*capacity)(const vector_##type* vector); \
        void (*push_back)(vector_##type* vector, type data); \
    }; \
    typedef struct vector_functions_pointers_##type vector_functions_pointers_##type; \
    \
    \
    int empty_##type (const vector_##type* vector); \
    int size_##type (const vector_##type* vector); \
    int capacity_##type (const vector_##type* vector); \
    void push_back_##type(vector_##type* vector, type data); \
    \
    \
     vector_functions_pointers_##type vector_functions_##type = {\
        &empty_##type, \
        &size_##type, \
        &capacity_##type, \
        &push_back_##type \
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
            vector->data[i++] = rhs->data[i++]; \
        } \
        vector->size = rhs->size; \
        vector->capacity = rhs->capacity; \
        return vector; \
    } \

#define vector(type) vector_##type
//#define new_vector(type, n, ...) new_vector_##type(n, ##__VA_ARGS__) 
#define new_vector(type, arg1, ...) _Generic ((arg1), \
                                            int : new_vector_##type, \
                                            vector_##type* : new_vector_copy_##type) (arg1, ##__VA_ARGS__)
#define empty(vector) vector->functions->empty(vector)
#define size(vector) vector->functions->size(vector)
#define capacity(vector) vector->functions->capacity(vector)
#define push_back(vector, data) vector->functions->push_back(vector, data)

#endif