# STL CONTAINERS IN C

## List

### File :
list.h : contains the necessary declarations and definitions for list

### Instructions for client file:
- Include list.h
- To use a list for a particular type, the list has to be defined first before main
- format to define list : define_list(type)
	Eg: define(list)int; define_list(char);

### Execution:
Compile and execute the client file
Ex :  
$ gcc client.c  
$ ./a.out  

### Implementation overview:

List is doubly linked list implementation allowing users to create doubly linked lists to store data of any simple type. 

#### Implementation fields of the list :
|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|head| list_node_##type*|Points to the first element|
|tail| list_node_##type*|Points to the last element|
|size| Integer |Holds the number of elements in the list|
|functions| list_function_pointers_##type |Stores pointers to the allowable list functions|

#### Implementation fields of node :
|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|data| type |Contains the data the user wants to store |
|next| list_node_##type* |Points to the next element|
|prev| list_node_##type* |Points to the previous element|

### CONTAINER PROPERTIES:

**Sequence**  
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

**Doubly-linked list**  
Each element keeps information on how to locate the next and the previous elements, allowing constant time insert and erase operations before or after a specific element (even of entire ranges), but no direct random access.

### MEMBER FUNCTIONS
*Constructor*:

- list(type)* new_list (type, 0) : Default constructor
- list(type)* new_list (type, int n, type data) : Fill constructor. Creates a new list with n elements having data
- list(type)* new_list (type, list(type)*) : Copy constructor. Creates a new list containing the elements of the passed list

*Destructor*:

- void delete (list(type*)) : Destructor

*Iterators*:

- iterator_list(type)* begin (list(type)*) : Return iterator to the first element
- iterator_list(type)* end (list(type)*) : Return iterator to NULL (conceptually beyond the last element) 
- iterator_list(type)* rbegin (list(type)*) : Return reverse iterator to the last element
- iterator_list(type)* rend (list(type)*) : Return reverse iterator to NULL (conceptually beyond the first element)

*Capacity*:

- int empty (const list(type)*) : Return true if list is empty, else returns false
- int size (const list(type)*) : Return the number of elements in the list

*Element access*:

- const type front (list(type)*) : Access first element
- const type back (list(type)*) : Access last element
- iterator_list(type)* find (list(type)*, type) : Returns iterator to the element containing data, returns NULL if element not present


*Modifiers*:

- void push_front (list(type)*, type) : Insert element at beginning
- void push_back (list(type)*, type) : Insert element at end
- void pop_front (list(type)*) : Delete first element
- void pop_back (list(type)*) : Delete last element
- void insert (list(type)*, iterator_list(type)* pos, int n, type data) : Insert n elements having data before pos


*Operations*:

- void remove_list (list(type)*, type) : Remove all elements with specific value
- void remove_if_list (list(type)*, int (*pred)(type)) : Remove elements satisfying condition
- void reverse (list(type)*) : Reverse the list