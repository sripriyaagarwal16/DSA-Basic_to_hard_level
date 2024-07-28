# DSA-Basic_to_hard_level
Hi everyone this github is here with all the different data structures of DSA,their algorithms and some solutions to problems.I hope this might help you guys...


![Roadmap](images/Roadmap)

---

# Arrays

## What is an Array?
An array is a data structure that can store a fixed-size sequence of elements of the same type. Each element in an array is accessed by its index, which is an integer that indicates the position of the element within the array. Arrays are useful for organizing data that can be processed in a sequence, such as lists of numbers, strings, or other objects.

## Need for Array Data Structures
Arrays are essential for several reasons:
1. **Efficient Data Access**: Arrays provide constant-time access to elements using their index.
2. **Memory Efficiency**: Arrays allocate a contiguous block of memory for elements, which can lead to better cache performance.
3. **Simplicity**: Arrays are simple to implement and use for a wide range of problems.
4. **Data Organization**: Arrays help organize data in a structured manner, making it easier to perform operations like searching, sorting, and iterating.

## Types of Arrays
1. **One-dimensional Array**: A linear sequence of elements.
2. **Multi-dimensional Array**: Arrays with more than one dimension, like 2D arrays (matrices) or 3D arrays.
3. **Dynamic Arrays**: Arrays that can resize themselves during runtime (e.g., `std::vector` in C++).

## Array Operations
1. **Initialization**: Declaring and initializing an array.
2. **Accessing Elements**: Accessing elements using their index.
3. **Modifying Elements**: Changing the value of elements.
4. **Traversing**: Iterating through all elements.
5. **Insertion**: Adding elements at a specific position.
6. **Deletion**: Removing elements from a specific position.
7. **Searching**: Finding elements based on certain criteria.
8. **Sorting**: Rearranging elements in a specific order.

# Stack

## What is a Stack?
A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed.

## Key Operations
1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove the element from the top of the stack.
3. **Peek/Top**: Get the value of the top element without removing it.
4. **isEmpty**: Check if the stack is empty.

## Stack Representation
A stack can be represented using arrays, linked lists, or dynamic data structures in various programming languages. The most common methods involve using arrays or linked lists.


# Queue

## What is a Queue?
A queue is a linear data structure that follows the First In, First Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. Queues are commonly used in scenarios where order needs to be preserved, such as task scheduling, handling requests in a web server, and breadth-first search in graphs.

## Key Operations
1. **Enqueue**: Add an element to the end of the queue.
2. **Dequeue**: Remove the element from the front of the queue.
3. **Front/Peek**: Get the value of the front element without removing it.
4. **isEmpty**: Check if the queue is empty.
5. **isFull**: Check if the queue is full (only applicable to array-based queues).
6. **Size**: Get the current size of the queue.

## Queue Representation
A queue can be represented using arrays, linked lists, or dynamic data structures in various programming languages. The most common methods involve using arrays or linked lists.

# Linked List

## What is a Linked List?
A linked list is a linear data structure where each element, called a node, contains two parts:
1. **Data**: The value stored in the node.
2. **Pointer**: A reference to the next node in the sequence.

Unlike arrays, linked lists do not store elements in contiguous memory locations. This allows for efficient insertions and deletions.

## Why Use a Linked List?
Linked lists are useful because:
- They allow for dynamic memory allocation.
- They provide efficient insertions and deletions compared to arrays.
- They can easily grow in size without requiring a large block of memory.

## Types of Linked Lists
1. **Singly Linked List**: Each node points to the next node.
2. **Doubly Linked List**: Each node points to both the next and the previous node.
3. **Circular Linked List**: The last node points to the first node, forming a circle.



## Singly Linked List

### What is a Singly Linked List?
A singly linked list is a type of linked list in which each node contains two parts:
1. **Data**: The value stored in the node.
2. **Pointer**: A reference to the next node in the sequence.

In a singly linked list, each node points to the next node in the list, and the last node points to `nullptr` indicating the end of the list.

### Why Use a Singly Linked List?
Singly linked lists are useful because:
- They allow for dynamic memory allocation.
- They provide efficient insertions and deletions compared to arrays.
- They can easily grow in size without requiring a large block of contiguous memory.

### Basic Operations on Singly Linked Lists
1. **Insertion**: Adding a new node to the list.
2. **Deletion**: Removing a node from the list.
3. **Traversal**: Visiting each node in the list.
4. **Search**: Finding a node with a given value.

