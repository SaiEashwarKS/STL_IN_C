#ifndef LIST_H
#define LIST_H

#include<stdarg.h>
#include<stdlib.h>

#define define_list(type) \
\
    struct list_##type; \
    struct list_functions_pointers_##type; \
    struct list_node_##type; \
    struct iterator_list_##type; \
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
    struct iterator_list_##type {\
        int is_reverse; \
        list_node_##type* iter; \
    }; \
    typedef struct iterator_list_##type iterator_list_##type; \
    \
    struct list_functions_pointers_##type {\
        int (*empty)(const list_##type* list); \
        int (*size)(const list_##type* list); \
        const type (*front)(const list_##type* list); \
        const type (*back)(const list_##type* list); \
        void (*push_front)(list_##type* list, type data); \
        void (*push_back)(list_##type* list, type data); \
        void (*pop_front)(list_##type* list); \
        void (*pop_back)(list_##type* list); \
        list_node_##type* (*insert)(list_##type* list, list_node_##type* node, int n, type data); \
        void (*remove_list) (list_##type* list, type data); \
        void (*remove_if_list) (list_##type* list, int (*pred)(type a)); \
        void (*clear) (list_##type* list); \
        iterator_list_##type* (*find)(list_##type* list, type data); \
        iterator_list_##type* (*find_if)(list_##type* list, int(*pred)(type a)); \
        void (*reverse)(list_##type* list); \
        void (*sort)(list_node_##type** head); \
        void (*sort_by)(list_node_##type** head, int(*pred)(type a, type b)); \
        iterator_list_##type* (*begin)(list_##type* list); \
        iterator_list_##type* (*end)(list_##type* list); \
        iterator_list_##type* (*rbegin)(list_##type* list); \
        iterator_list_##type* (*rend)(list_##type* list); \
        void (*delete)(list_##type** list); \
    }; \
    typedef struct list_functions_pointers_##type list_functions_pointers_##type; \
    \
    \
    int empty_list_##type (const list_##type* list); \
    int size_list_##type (const list_##type* list); \
    const type front_list_##type (const list_##type* list); \
    const type back_list_##type (const list_##type* list); \
    void push_front_list_##type (list_##type*, type data); \
    void push_back_list_##type (list_##type* list, type data); \
    void pop_front_list_##type (list_##type* list); \
    void pop_back_list_##type (list_##type* list); \
    list_node_##type* insert_list_##type(list_##type* list, list_node_##type* node, int n, type data); \
    void remove_list_##type(list_##type* list, type data); \
    void remove_if_list_##type(list_##type* list, int (*pred)(type data)); \
    void clear_list_##type(list_##type* list); \
    iterator_list_##type* find_list_##type(list_##type* list, type data); \
    iterator_list_##type* find_if_list_##type(list_##type* list, int(*pred)(type a)); \
    void reverse_list_##type (list_##type* list); \
    void sort_list_##type (list_node_##type** head); \
    void sort_by_list_##type(list_node_##type** head, int(*pred)(type a, type b)); \
    iterator_list_##type* begin_list_##type(list_##type* list); \
    iterator_list_##type* end_list_##type(list_##type* list); \
    iterator_list_##type* rbegin_list_##type(list_##type* list); \
    iterator_list_##type* rend_list_##type(list_##type* list); \
    void delete_list_##type(list_##type** list); \
    \
    \
     list_functions_pointers_##type list_functions_##type = {\
        &empty_list_##type, \
        &size_list_##type, \
        &front_list_##type, \
        &back_list_##type, \
        &push_front_list_##type, \
        &push_back_list_##type, \
        &pop_front_list_##type, \
        &pop_back_list_##type, \
        &insert_list_##type, \
        &remove_list_##type, \
        &remove_if_list_##type, \
        &clear_list_##type, \
        &find_list_##type, \
        &find_if_list_##type, \
        &reverse_list_##type, \
        &sort_list_##type, \
        &sort_by_list_##type, \
        &begin_list_##type, \
        &end_list_##type, \
        &rbegin_list_##type, \
        &rend_list_##type, \
        &delete_list_##type \
    }; \
    \
    \
    list_##type* new_list_##type(int n, ...); \
    list_##type* new_list_default_##type(); \
    list_##type* new_list_fill_##type(int n, va_list args); \
    list_##type* new_list_copy_##type(list_##type* rhs, ...); \
    list_node_##type* create_node_list_##type(type data); \
    int less_equal_list_##type(type a, type b); \
    list_node_##type* merge_list_##type(list_node_##type* a, list_node_##type* b, int (*pred)(type a, type b)); \
    list_node_##type* split_list_##type(list_node_##type* source); \
    \
    \
    int empty_list_##type (const list_##type* list) \
    {\
        return list->size == 0; \
    } \
    \
    int size_list_##type (const list_##type* list) \
    {\
        return list->size; \
    } \
    \
    const type front_list_##type (const list_##type* list) \
    {\
        return list->head->data; \
    } \
    \
    const type back_list_##type (const list_##type* list) \
    {\
        return list->tail->data; \
    } \
    \
    void push_front_list_##type(list_##type* list, type data) \
    {\
        list_node_##type* new_node = create_node_list_##type(data); \
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
    \
    void push_back_list_##type(list_##type* list, type data) \
    {\
        list_node_##type* new_node = create_node_list_##type(data); \
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
    void pop_front_list_##type(list_##type* list) \
    {\
        if(list->head == NULL) \
            return; \
        list_node_##type* temp = list->head; \
        list->head = temp->next; \
        free(temp); \
        if(list->head == NULL) list->tail = NULL; \
        else \
        {\
            list->head->prev = NULL; \
        } \
        --list->size; \
    } \
    \
    void pop_back_list_##type(list_##type* list) \
    {\
        if(list->tail == NULL) \
            return; \
        list_node_##type* temp = list->tail; \
        list->tail = temp->prev; \
        free(temp); \
        if(list->tail == NULL) list->head = NULL; \
        else \
        {\
            list->tail->next = NULL; \
        } \
        --list->size; \
    } \
    \
    list_node_##type* insert_list_##type(list_##type* list, list_node_##type* node, int n, type data) \
    {\
        list_node_##type* new_node = create_node_list_##type(data); \
        list_node_##type* temp = node; \
        for(int i = 0; i < n; ++i) \
        {\
            new_node->next = temp; \
            new_node->prev = temp->prev; \
            if(temp->prev) \
            {\
                temp->prev->next = new_node; \
            } \
            temp->prev = new_node; \
            if(new_node->prev == NULL) \
            {\
                list->head = new_node; \
            } \
            ++list->size; \
            temp = temp -> prev; \
        } \
        return temp; \
    } \
    \
    void remove_list_##type(list_##type* list, type data) \
    {\
        list_node_##type* temp = list->head; \
        list_node_##type* temp2; \
        int is_deleted = 0; \
        while(temp) \
        {\
            is_deleted = 0; \
            if(temp->data == data) \
            {\
                if(list->head == temp) list->head = temp->next; \
                if(list->tail == temp) list->tail = temp->prev; \
                if(temp->prev) temp->prev->next = temp->next; \
                if(temp->next) temp->next->prev = temp->prev; \
                --list->size; \
                temp2 = temp; \
                temp = temp->next; \
                free(temp2); \
                is_deleted = 1; \
            } \
            if(!is_deleted) temp = temp->next; \
        } \
    } \
    \
    void remove_if_list_##type(list_##type* list, int (*pred)(type data)) \
    {\
        list_node_##type* temp = list->head; \
        while(temp) \
        {\
            if(pred(temp->data)) \
            {\
                remove_list_##type(list, temp->data); \
            } \
            temp = temp->next; \
        } \
    } \
    \
    void clear_list_##type(list_##type* list) \
    {\
        list_node_##type* temp = list->head; \
        list_node_##type* temp2; \
        while(temp) \
        {\
            temp2 = temp; \
            temp = temp -> next; \
            free(temp2); \
        } \
        list->size = 0; \
        list->head = list->tail = NULL; \
    } \
    \
    iterator_list_##type* find_list_##type(list_##type* list, type data) \
    {\
        list_node_##type* temp = list->head; \
        iterator_list_##type* res = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        res->is_reverse = 0; \
        while(temp != NULL) \
        {\
            if(temp->data == data) \
            {\
               res->iter = temp; \
               return res; \
            } \
            temp = temp->next; \
        } \
        return NULL; \
    } \
    \
    iterator_list_##type* find_if_list_##type(list_##type* list, int(*pred)(type a)) \
    {\
        list_node_##type* temp = list->head; \
        iterator_list_##type* res = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        res->is_reverse = 0; \
        while(temp != NULL) \
        {\
            if(pred(temp->data)) \
            {\
               res->iter = temp; \
               return res; \
            } \
            temp = temp->next; \
        } \
        return NULL; \
    } \
    \
    void reverse_list_##type (list_##type* list) \
    {\
        list_node_##type* node = list->head; \
        list_node_##type* temp; \
        while(node) \
        {\
            temp = node->next; \
            node->next = node->prev; \
            node->prev = temp; \
            node = temp; \
        } \
        temp = list->head; \
        list->head = list->tail;\
        list->tail = temp; \
    } \
    \
    void sort_list_##type(list_node_##type** head) \
    {\
        if(*head == NULL || (*head)->next == NULL) \
            return; \
        list_node_##type* temp_head = *head; \
        list_node_##type* second = split_list_##type(temp_head); \
        sort_list_##type(&temp_head); \
        sort_list_##type(&second); \
        *head = merge_list_##type(temp_head, second, &less_equal_list_##type); \
    } \
    \
    void sort_by_list_##type(list_node_##type** head, int (*pred)(type a, type b)) \
    {\
        if(*head == NULL || (*head)->next == NULL) \
            return; \
        list_node_##type* temp_head = *head; \
        list_node_##type* second = split_list_##type(temp_head); \
        sort_list_##type(&temp_head); \
        sort_list_##type(&second); \
        *head = merge_list_##type(temp_head, second, pred); \
    } \
    \
    iterator_list_##type* begin_list_##type(list_##type* list) \
    {\
        iterator_list_##type* it = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        it->is_reverse = 0; \
        it->iter = list->head; \
        return it; \
    } \
    iterator_list_##type* end_list_##type(list_##type* list) \
    {\
        iterator_list_##type* it = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        it->is_reverse = 0; \
        it->iter = NULL; \
        return it; \
    } \
    \
    iterator_list_##type* rbegin_list_##type(list_##type* list) \
    {\
        iterator_list_##type* it = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        it->is_reverse = 1; \
        it->iter = list->tail; \
        return it; \
    } \
    iterator_list_##type* rend_list_##type(list_##type* list) \
    {\
        iterator_list_##type* it = (iterator_list_##type*)malloc(sizeof(iterator_list_##type)); \
        it->is_reverse = 1; \
        it->iter = NULL; \
        return it; \
    } \
    \
    void delete_list_##type(list_##type** list) \
    {\
        list_node_##type* temp = (*list)->head; \
        list_node_##type* prev; \
        while(temp != NULL) \
        {\
            prev = temp; \
            temp = temp->next; \
            free(prev); \
        } \
        free(*list); \
        *list = NULL; \
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
            push_front_list_##type(list, data); \
        } \
        return list; \
    } \
    list_##type* new_list_copy_##type(list_##type* rhs, ...) \
    {\
        list_##type* list = new_list_default_##type(); \
        list_node_##type* temp = rhs->head; \
        while(temp != NULL) \
        {\
            push_back_list_##type(list, temp->data); \
            temp = temp->next; \
        } \
        return list; \
    } \
    \
    list_node_##type* create_node_list_##type(type data) \
    {\
        list_node_##type *new_node = (list_node_##type*)malloc(sizeof(list_node_##type)); \
        new_node->data = data; \
        new_node->next = NULL; \
        new_node->prev = NULL; \
        return new_node; \
    } \
    int less_equal_list_##type(type a, type b) \
    {\
        return a <= b; \
    } \
    list_node_##type* merge_list_##type(list_node_##type* a, list_node_##type* b, int (*pred)(type a, type b)) \
    {\
        if(a == NULL) \
            return (b); \
        if(b == NULL) \
            return (a); \
        \
        if(pred(a->data, b->data)) \
        {\
            a->next = merge_list_##type(a->next, b, pred); \
            a->next->prev = a; \
            a ->prev = NULL; \
            return a; \
        } \
        else \
        {\
            b->next = merge_list_##type(a, b->next, pred); \
            b->next->prev = b; \
            b -> prev = NULL; \
            return b; \
        } \
    } \
    \
    list_node_##type* split_list_##type(list_node_##type* source) \
    {\
        list_node_##type* slow = source; \
        list_node_##type* fast = source; \
        \
        while(fast->next && fast->next->next) \
        {\
            fast = fast->next->next; \
            slow = slow->next; \
        }\
        list_node_##type* res = slow->next; \
        slow->next = NULL; \
        return res; \
    } 
    

#define list(type) list_##type

//ctor cannot be a function of list becuase the object doesnt exist yet
#define new_list(type, arg1, ...) _Generic ((arg1), \
                                            int : new_list_##type, \
                                            list_##type* : new_list_copy_##type) (arg1, ##__VA_ARGS__)

//dtor can be a function of list because the list object exists. 
//therefore, the user need not enter the type as an argument in delete like in ctor 
#ifndef DELETE_FUNC
#define DELETE_FUNC
#define delete(list) (list)->functions->delete(&list)
#endif

#ifndef SIZE_FUNC
#define SIZE_FUNC
#define size(list) (list)->functions->size(list)
#endif

#ifndef EMPTY_FUNC
#define EMPTY_FUNC
#define empty(list) (list)->functions->empty(list)
#endif

#ifndef FRONT_FUNC
#define FRONT_FUNC
#define front(list) (list)->functions->front(list)
#endif

#ifndef PUSH_FRONT_FUNC
#define PUSH_FRONT_FUNC
#define push_front(list, data) (list)->functions->push_front(list, data)
#endif

#ifndef PUSH_BACK_FUNC
#define PUSH_BACK_FUNC
#define push_back(list, data) (list)->functions->push_back(list, data)
#endif

#ifndef POP_FRONT_FUNC
#define POP_FRONT_FUNC
#define pop_front(list) (list)->functions->pop_front(list)
#endif

#ifndef POP_BACK_FUNC
#define POP_BACK_FUNC
#define pop_back(list) (list)->functions->pop_back(list)
#endif

#ifndef INSERT_FUNC
#define INSERT_FUNC
#define insert(list,node, n, data) (list)->functions->insert(list, node, n, data)
#endif

#ifndef REMOVE_list_FUNC
#define REMOVE_list_FUNC
#define remove_list(list, data) (list)->functions->remove_list(list, data)
#endif

#ifndef REMOVE_IF_list_FUNC
#define REMOVE_IF_list_FUNC
#define remove_if_list(list, pred) (list)->functions->remove_if_list(list, pred)
#endif

#ifndef CLEAR_FUNC
#define CLEAR_FUNC
#define clear(list) (list)->functions->clear(list)
#endif

#ifndef FIND_FUNC
#define FIND_FUNC
#define find(list, data) (list)->functions->find(list, data)
#endif

#ifndef FIND_IF_FUNC
#define FIND_IF_FUNC
#define find_if(list, pred) (list)->functions->find_if(list, pred)
#endif

#ifndef REVERSE_FUNC
#define REVERSE_FUNC
#define reverse(list) (list)->functions->reverse(list)
#endif

#ifndef SORT_FUNC
#define SORT_FUNC
#define sort(list) (list)->functions->sort(&list->head)
#endif

#ifndef SORT_BY_FUNC
#define SORT_BY_FUNC
#define sort_by(list, pred) (list)->functions->sort_by(&list->head, pred)
#endif

#ifndef BEGIN_FUNC
#define BEGIN_FUNC
#define begin(list) (list)->functions->begin(list)
#endif

#ifndef END_FUNC
#define END_FUNC
#define end(list) (list)->functions->end(list)
#endif

#ifndef RBEGIN_FUNC
#define RBEGIN_FUNC
#define rbegin(list) (list)->functions->rbegin(list)
#endif

#ifndef REND_FUNC
#define REND_FUNC
#define rend(list) (list)->functions->rend(list)
#endif


//iterator
#define iterator_list(type) iterator_list_##type

#define iter_list_deref(it) it->iter->data

#define iter_list_equal(it1, it2) it1->iter == it2->iter

#define iter_list_notequal(it1, it2) it1->iter != it2->iter

#define iter_list_forward(it) it->iter = it->iter!=NULL ? (it->is_reverse ? it->iter->prev : it->iter->next) : NULL

#define iter_list_backward(it) it->iter = it->iter!=NULL ? (it->is_reverse ? it->iter->next : it->iter->prev) : NULL

#endif