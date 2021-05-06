Issues : 
va_arg (in new_list_fill_##type) works well only for int
there will be memory leaks when data stored in list is itself allocated memory dynamically

Overloaded interfaces :
new_list : 
    list(type)* new_list(type, 0) : default
    list(type)* new_list(type, int n, type data) : fill
    list(type)* new_list(type, list(type)* list) : copy