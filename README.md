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

# Searching Algorithms

## Overview
Searching algorithms are designed to retrieve information stored within some data structure. These algorithms are fundamental to computer science and are used in various applications, from databases to machine learning.

## Types of Searching Algorithms

### 1. Linear Search
Linear search is the simplest search algorithm. It checks each element in the list until it finds the target element or reaches the end of the list.

#### Time Complexity
- Best case: O(1) (element is at the first position)
- Average case: O(n)
- Worst case: O(n) (element is not in the list or at the last position)

#### Space Complexity
- O(1) (iterative)

### 2. Binary Search
Binary search is a more efficient search algorithm that works on sorted arrays. It repeatedly divides the search interval in half and compares the target value to the middle element.

### Time Complexity
* Best case: O(1) (element is at the middle)
* Average case: O(log n)
* Worst case: O(log n) (element is not in the list)
### Space Complexity
* O(1) (iterative)
* O(log n) (recursive, due to call stack)


# Sorting Algorithms

Sorting is a fundamental operation in computer science, used to arrange data in a specific order. Various sorting algorithms are designed to efficiently sort data in different scenarios. This section covers Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Merge Sort.

## 1. Bubble Sort

### Algorithm
Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

### Steps
1. Compare each pair of adjacent elements from the beginning of the list.
2. If a pair is in the wrong order, swap them.
3. Repeat the process for each element, excluding the last one each time, since the largest element will have "bubbled" to the end.

### Pseudocode
```
function bubbleSort(array):
n = length(array)
for i from 0 to n-1:
for j from 0 to n-i-2:
if array[j] > array[j+1]:
swap(array[j], array[j+1])
```

### Time Complexity
- Best case: O(n) (when the array is already sorted)
- Average case: O(n^2)
- Worst case: O(n^2)

### Space Complexity
- O(1)

## 2. Selection Sort
### Algorithm
Selection Sort divides the list into a sorted and an unsorted part. It repeatedly selects the smallest (or largest) element from the unsorted part and moves it to the end of the sorted part.

### Steps
1. Find the minimum element in the unsorted part.
2. Swap it with the first element of the unsorted part.
3. Move the boundary of the sorted part one element forward.
4. Repeat the process until the entire array is sorted.
### Pseudocode
```
function selectionSort(array):
    n = length(array)
    for i from 0 to n-1:
        minIndex = i
        for j from i+1 to n-1:
            if array[j] < array[minIndex]:
                minIndex = j
        swap(array[minIndex], array[i])
```
### Time Complexity
* Best case: O(n^2)
* Average case: O(n^2)
* Worst case: O(n^2)
### Space Complexity
* O(1)

## 3. Insertion Sort
### Algorithm
Insertion Sort builds the sorted array one item at a time. It takes each element from the input and finds its correct position in the sorted part.

### Steps
1. Start with the second element, as the first element is considered sorted.
2. Compare the current element with the elements in the sorted part and shift the sorted elements to the right to create the correct position for the current element.
3. Insert the current element in its correct position.
4. Repeat the process for all elements.

### Pseudocode
```
    function insertionSort(array):
    n = length(array)
    for i from 1 to n-1:
        key = array[i]
        j = i-1
        while j >= 0 and array[j] > key:
            array[j+1] = array[j]
            j = j-1
        array[j+1] = key
```
### Time Complexity
* Best case: O(n)
* Average case: O(n^2)
* Worst case: O(n^2)
### Space Complexity
* O(1)

## 4. Quick Sort
### Algorithm
Quick Sort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

### Steps
1. Choose a pivot element.
2. Partition the array into two parts: elements less than the pivot and elements greater than the pivot.
3. Recursively apply the above steps to the sub-arrays.
4. Combine the sub-arrays and the pivot into a single sorted array.

### Pseudocode
```
function quickSort(array, low, high):
    if low < high:
        pivotIndex = partition(array, low, high)
        quickSort(array, low, pivotIndex - 1)
        quickSort(array, pivotIndex + 1, high)

function partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j from low to high - 1:
        if array[j] < pivot:
            i = i + 1
            swap(array[i], array[j])
    swap(array[i + 1], array[high])
    return i + 1
```
### Time Complexity
* Best case: O(n log n)
* Average case: O(n log n)
* Worst case: O(n log n)
### Space Complexity
* O(n)

## 5. Merge Sort
### Algorithm
Merge Sort is a divide-and-conquer algorithm. It works by recursively dividing the array into two halves, sorting each half, and then merging them back together.

### Steps
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the sorted halves back together.
### Pseudocode
```
function mergeSort(array):
    if length of array <= 1:
        return array
    mid = length of array / 2
    leftHalf = mergeSort(first half of array)
    rightHalf = mergeSort(second half of array)
    return merge(leftHalf, rightHalf)

function merge(leftHalf, rightHalf):
    result = empty array
    while leftHalf is not empty and rightHalf is not empty:
        if first element of leftHalf <= first element of rightHalf:
            append first element of leftHalf to result
            remove first element from leftHalf
        else:
            append first element of rightHalf to result
            remove first element from rightHalf
    append remaining elements of leftHalf to result
    append remaining elements of rightHalf to result
    return result
```
### Time Complexity
* Best case: O(n log n)
* Average case: O(n log n)
* Worst case: O(n log n)
### Space Complexity
* O(n)
  
