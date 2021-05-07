# DEQUE

## IMPLEMENTATION OVERVIEW

Deque stands for doubly ended queue. The deque (of a particular type) we have implemented is defined as a simple structure with 5 fields.


|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|back|deque_node_##type*|Points to the last filled location|
|front|deque_node_##type*|Points to the first filled location|
|size|integer|Holds the number of elements in the deque|
|maxie|integer|Holds the maximum number of elements that can be stored in the deque|
|functions|Struct functions_deque_##type|Stores pointers to the allowable deque functions|


deque_node_##type -> a linked list like data structure to store the data.

|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|next|deque_node_##type*|Points to the next element in the deque|
|prev|deque_node_##type*|Points to the previous element in the deque|
|data|type|Holds the data part of the element|


## MEMBER FUNCTIONS

**Constructor:** Can be constructed via construct deque container or copy constructor.

**Iterators:**

- begin -> points to the first element of queue
- end -> points to a location past the last element

**Capacity:**

- size -> shows the current size of the deque
- max_size -> shows the max size of the deque. We have given the value of 100001.
- empty -> returns if the deque is empty.

**Element Access:**

- at -> returns the element at the given valid location.
- front -> returns the first element in the deque
- back -> returns the last element in the deque

**Modifiers:**

- insert -> to insert at the end of the deque
- clear -> just clears the deque by making the size=0 and pointers to NULL.
- pop -> removes the first element in the deque

**USAGE**

I have 2 header files with similar function definitions and declarations.

- `deque.h` -> is a linked list type implementation of a deque.
- `queue.h` -> stores the elements in an array storing elements of the given type.

Both these header files have `stdlib` and `stdarg` header files already included.

To use in a C file:

1) Just include the header file of your choice (either `queue.h` or `deque.h`) in your code.
2) In the global scope define the type of deque you need.
	Example: define_queue(int): Where we are intending to use a deque storing elements of type int.
3) To use a deque: 
- Declare a pointer as deque(type)* var_name. Example: deque(int)* a.
- Initialize it by calling ```new_deque(type,<argi>,<optional argument>)```. Example : a = new_deque(int,5,6)-> initializes a deque with first 5 elements as 6
	- 'argi'
		- can be an integer to denote intial number of elements followed by the optional argument to represent which values need to be stored.
		- can be a pointer to some other deque.
- Then other functions can be called as fun_name(pointer). Example: size(a)

