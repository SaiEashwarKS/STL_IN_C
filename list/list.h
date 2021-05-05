#ifndef LIST_H
#define LIST_H

#include<stdarg.h>
#include<stdlib.h>

#define define_list(type) \
\
    struct list_##type; \
    struct list_functions_pointers_##type; \
    struct list_node_##type; \
    \
    struct list_##type {\
        struct list_node_##type *head; \
        struct list_node_##type *tail; \
        int size; \
        struct list_functions_pointers_##type* functions; \
    }; \
    typedef struct list_##type list_##type; \
    \
    struct list_node_##type {\
        type data; \
        struct list_node_##type *next; \
        struct list_node_##type *prev; \
    }; \
    typedef struct list_node_##type list_node_##type; \
    \
    struct list_functions_pointers_##type {\
        int (*empty)(const list_##type* list); \
        int (*size)(const list_##type* list); \
        const type (*front)(const list_##type* list); \
        const type (*back)(const list_##type* list); \
        void (*push_front)(list_##type* list, type data); \
        void (*push_back)(list_##type* list, type data); \
    }; \
    typedef struct list_functions_pointers_##type list_functions_pointers_##type; \
    \
    \
    int empty_##type (const list_##type* list); \
    int size_##type (const list_##type* list); \
    const type front_##type (const list_##type* list); \
    const type back_##type(const list_##type* list); \
    void push_front_##type(list_##type*, type data); \
    void push_back_##type(list_##type* list, type data); \
    \
    \
     list_functions_pointers_##type list_functions_##type = {\
        &empty_##type, \
        &size_##type, \
        &front_##type, \
        &back_##type, \
        &push_front_##type, \
        &push_back_##type \
    }; \
    \
    \
    list_##type* new_list_##type(int n, ...); \
    list_##type* new_list_default_##type(); \
    list_##type* new_list_fill_##type(int n, va_list args); \
    list_node_##type* create_node_##type(type data); \
    \
    \
    int empty_##type (const list_##type* list) \
    {\
        return list->size == 0; \
    } \
    \
    int size_##type (const list_##type* list) \
    {\
        return list->size; \
    } \
    \
    const type front_##type (const list_##type* list) \
    {\
        return list->head->data; \
    } \
    \
    const type back_##type (const list_##type* list) \
    {\
        return list->tail->data; \
    } \
    \
    void push_front_##type(list_##type* list, type data) \
    {\
        list_node_##type* new_node = create_node_##type(data); \
        if(list->head == NULL) \
        {\
            list->head = new_node; \
            list->tail = new_node; \
        } \
        else \
        {\
            list_node_##type* temp = list->head; \
            new_node->next = temp; \
            temp->prev = new_node; \
            list->head = new_node; \
        } \
        ++list->size; \
    } \
    void push_back_##type(list_##type* list, type data) \
    {\
        list_node_##type* new_node = create_node_##type(data); \
        if(list->tail == NULL) \
        {\
            list->head = new_node; \
            list->tail = new_node; \
        } \
        else \
        {\
            list_node_##type* temp = list->tail; \
            new_node->prev = list->tail; \
            temp->next = new_node; \
            list->tail = new_node; \
        } \
        ++list->size; \
    } \
    \
    \
    list_##type* new_list_##type(int n, ...) \
    {\
        if(n == 0) \
            return new_list_default_##type(); \
        else \
        {\
            va_list args; \
            va_start (args, n); \
            list_##type* res = new_list_fill_##type(n, args); \
            va_end(args); \
            return res; \
        } \
    } \
    list_##type* new_list_default_##type() \
    {\
        list_##type* list = (list_##type*)malloc(sizeof(list_##type)); \
        list->head = NULL; \
        list->tail = NULL; \
        list->size = 0; \
        list->functions = &list_functions_##type; \
        return list; \
    } \
    \
    list_##type* new_list_fill_##type(int n, va_list args) \
    {\
        list_##type* list = new_list_default_##type(); \
        type data = va_arg(args, type); \
        for(int i = 0; i < n; ++i) \
        {\
            push_front_##type(list, data); \
        } \
        return list; \
    } \
    \
    list_node_##type* create_node_##type(type data) \
    {\
        list_node_##type *new_node = (list_node_##type*)malloc(sizeof(list_node_##type)); \
        new_node->data = data; \
        new_node->next = NULL; \
        new_node->prev = NULL; \
        return new_node; \
    } \

#define list(type) list_##type
#define new_list(type, n, ...) new_list_##type(n, ##__VA_ARGS__)
#define empty(list) list->functions->empty(list)
#define size(list) list->functions->size(list)
#define front(list) list->functions->front(list)
#define push_front(list, data) list->functions->push_front(list, data)
#define push_back(list, data) list->functions->push_back(list, data)

#endif