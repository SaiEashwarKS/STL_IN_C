**DEQUE**

**IMPLEMENTATION OVERVIEW**

Deque stands for doubly ended queue. The deque (of a particular type) we have implemented is defined as a simple structure with 5 fields.


|Field_Name|Data Type|Usage|
| :---: | :---: | :---: |
|back|deque_node_##type*|Points to the last filled location|
|front|deque_node_##type*|Points to the first filled location|
|size|integer|Holds the number of elements in the deque|
|maxie|integer|Holds the maximum number of elements that can be stored in the deque|
|functions|Struct functions_deque_##type|Stores pointers to the allowable deque functions|


