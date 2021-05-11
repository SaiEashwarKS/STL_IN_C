## Vector

### File :
vector.h : contains the necessary declarations and definitions for vector

### Instructions for client file:
- Include vector.h
- To use a vector for a particular type, the vector has to be defined first before main
- format to define vector : define_vector(type)
	Eg: define_vector(int); define_vector(char);

### Execution:
Compile and execute the client file
Ex :  
$ gcc client.c  
$ ./a.out  

### Implementation overview:

Vectors are sequence containers representing dynamic arrays with the ability to resize itself automatically. 

#### Implementation fields of the vector :
|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|size| Integer|Number of elements in the vector|
|capacity| Integer|Size of the storage space currently allocated for the vector, expressed in terms of elements|
|data| type*|An array to store elements|
|functions| vector_function_pointers_##type |Stores pointers to the allowable vector functions|

#### Implementation fields of iterator :

|*Field_Name*|*Data Type*|*Usage*|
| :---: | :---: | :---: |
|iter| type* |Points to an element in the vector |
|is_reverse| Integer |Specifies if the iterator is forward or reverse|


### CONTAINER PROPERTIES:

**Sequence**  
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

**Dynamic array**  
Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively fast addition/removal of elements at the end of the sequence.


### MEMBER FUNCTIONS

*Constructor*:

- vector(type)* new_vector (type, 0) : Default constructor
- vector(type)* new_vector (type, int n, type data) : Fill constructor. Creates a new vector with n elements having data
- vector(type)* new_vector (type, vector(type)*) : Copy constructor. Creates a new vector containing the elements of the passed vector

*Destructor*:

- void delete (vector(type*)) : Destructor

*Iterators*:

- iterator_vector(type)* begin (vector(type)*) : Return iterator to the first element
- iterator_vector(type)* end (vector(type)*) : Returns an iterator referring to the past-the-end element in the vector.
- iterator_vector(type)* rbegin (vector(type)*) : Return reverse iterator to the last element
- iterator_vector(type)* rend (vector(type)*) : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector

*Capacity*:

- int empty (const vector(type)*) : Return true if vector is empty, else returns false
- int size (const vector(type)*) : Return the number of elements in the vector
- int capacity (const vector(type)*) : Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.

*Element access*:

- const type front (vector(type)*) : Access first element
- const type back (vector(type)*) : Access last element
- iterator_vector(type)* find (vector(type)*, type) : Returns iterator to the first element containing data, returns end of vector if not found

*Modifiers*:

- void push_back (vector(type)*, type) : Insert element at end
- void pop_back (vector(type)*) : Delete last element
- void insert (vector(type)*, iterator_vector(type)* it, type data) : Insert element having data at the iterator
- iterator_vector(type)* erase (vector(type)*, type, iterator_vector(type)* it1, iterator_vector(type)* it2) : Removes from the vector a range of elements [it1,it2). Returns an iterator pointing to the new location of the element that followed the last element erased
- void clear (vector(type*)) : Clears all the elements and size becomes 0

*Operations*:

- void at (vector(type)*, int) : Returns value of element at that position in the vector
- void reserve (vector(type)*, int) : Requests that vector capacity be at least enough to contain given no. of  elements

*Methods on Iterators*:

- type* iter_vector_deref (iterator(vector)*) : Returns element data at the iterator
- int iter_vector_equal (iterator(vector)*, iterator(vector)*) : Returns true if both iterators point to the same element, else false
- int iter_vector_notequal (iterator(vector)*, iterator(vector)*) : Return true if both iterators do not point to the same element, else false
- iterator(vector)* iter_vector_forward (iterator(vector)*) : Return the iterator to next element
- iterator(vector)* iter_vector_backward (iterator(vector)*) : Return the iterator to previous element
- iterator(vector)* iter_vector_add (iterator(vector)*, int) : Return resulting iterator after adding an integer number to a given iterator
- iterator(vector)* iter_vector_subtract (iterator(vector)*, int) : Return resulting iterator after adding an integer number to a given iterator
- int iter_vector_lesser (iterator(vector)*, iterator(vector)*) : Returns true if first iterator is lesser than the second one, else false
- int iter_vector_greater (iterator(vector)*, iterator(vector)*) : Returns true if first iterator is greater than the second one, else false
- int iter_vector_lesser_equal (iterator(vector)*, iterator(vector)*) : Returns true if first iterator is lesser than or equal to the second one, else false
- int iter_vector_greater_equal (iterator(vector)*, iterator(vector)*) : Returns true if first iterator is greater than or equal to the second one, else false

