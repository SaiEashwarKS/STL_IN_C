Issues : 
va_arg (in new_list_fill_##type) works well only for int
there will be memory leaks when data stored in list is itself allocated memory dynamically

functions intended to be used by users:
    int empty(const list_##type* list);
    int size(const list_##type* list);
    const type front(const list_##type* list);
    const type back(const list_##type* list); 
    void push_front(list_##type* list, type data);
    void push_back(list_##type* list, type data); 
    void pop_front(list_##type* list);
    void pop_back(list_##type* list);
    void delete(list_##type** list);

    list(type)* new_list(type, arg, ...) //if arg is 0 (there can be any number of arguments after 0, they'll be ignored), default ctor is called, 
                                         //if arg is int and non zero, there should be a third argument of type "type" (any arguments after that will be ignored), fill ctor is called
                                         //if arg is of type list(type)* (there can be any number of arguments after arg, they'll be ignored), copy ctor will be called

Overloaded interfaces :
new_list : 
    list(type)* new_list(type, 0) : default
    list(type)* new_list(type, int n, type data) : fill
    list(type)* new_list(type, list(type)* list) : copy