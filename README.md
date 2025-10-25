# DSA-Basic_to_hard_level
Hi everyone this github is here with all the different data structures of DSA,their algorithms and some solutions to problems.I hope this might help you guys...


![Roadmap](images/Roadmap)

---

## BEST DSA Playlist  ( you can choose any one of them)

1.) Striver's A2Z DSA Course/Playlist: [Striver's A2Z DSA Course/Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz)
2.) Kunal Kushwaha's DSA Playlist (Java):[Kunal's Playlist](https://www.youtube.com/playlist?list=PL9gnSGHSqcnr_DxHsP7AW9ftq0AtAyYqJ)
3.) Love Babbar's(C++): [Love Babbar's Playlist](https://www.youtube.com/playlist?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA)
4.) Apna College/Apni Kaksha Playlists (C++ and Java): [Apna College Playlist](https://www.youtube.com/playlist?list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt)


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

## 3.10 Tree Data Structure

Having covered the basics of linear data structures, let's delve into non-linear structures, starting with the Tree.

The Tree data structure resembles an inverted tree from nature, featuring a root and leaves. The root is the initial node, and the leaves are at the bottom-most level. Notably, there's only one path between any two nodes in a tree.

<!-- img -->

Based on the maximum number of children a node can have:

- **Binary Tree:** Each node can have a maximum of 2 children.
- **Ternary Tree:** Each node can have a maximum of 3 children.
- **N-ary Tree:** A node can have at most N children.

Additional classifications based on node configuration include:

- **Complete Binary Tree:** All levels are filled, except possibly for the last level, which is filled from the left as much as possible.
- **Perfect Binary Tree:** All levels are filled.
- **Binary Search Tree:** A special binary tree where smaller nodes are on the left, and higher value nodes are on the right.
- **Ternary Search Tree:** Similar to a binary search tree, but with nodes having at most 3 children.

<details open>
  <summary><b>Resources: Trees</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Tree Data Structure</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/tree-data-structure/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Heaps (priority queue)</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/binary-heap/"><b>viterbi-web.usc.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Heaps</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/heap?slide=1"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Priority Queues: Lecture Notes</b></p></td>
      <td><a target="_blank" href="https://www.cs.cmu.edu/~wlovas/15122-r11/lectures/15-priorqs.pdf"><b>cs.cmu.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>UNION-FIND DISJOINT SETS (UFDS)</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/ufds"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>DISJOINT-SET DATA STRUCTURES</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/Disjoint-set%20Data%20Structures"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Disjoint set (Union-Find): Lecture Notes</b></p></td>
      <td><a target="_blank" href="https://people.cs.georgetown.edu/jthaler/ANLY550/lec6.pdf"><b>harvard.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Segment Trees: MIN SEGMENT TREE</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/segmenttree?slide=1"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>RANGE MINIMUM QUERY AND LOWEST COMMON ANCESTOR</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Segment Trees</b></p></td>
      <td><a target="_blank" href="https://www.iarcs.org.in/inoi/online-study-material/topics/segment-tree.php"><b>iarcs.org.in</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>BINARY INDEXED TREES: TopCoder</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Binary Index Tree (Fenwick tree)</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/fenwicktree?slide=1"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Binary Index Tree: ICO</b></p></td>
      <td><a target="_blank" href="https://www.iarcs.org.in/inoi/online-study-material/topics/binary-index-tree.php"><b>iarcs.org.in</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Trees (traversals)</b></p></td>
      <td><a target="_blank" href="https://people.eecs.berkeley.edu/~vazirani/s99cs170/notes/dynamic2.pdf"><b>berkeley.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Dynamic programming on trees</b></p></td>
      <td><a target="_blank" href="https://www.iarcs.org.in/inoi/online-study-material/topics/dp-trees.php"><b>iarcs.org.in</b></a></td>
    </tr>
  </tbody>
</table>
</details>

<details open>
  <summary><b>Practice Problems: Trees</b></summary>
  <table>
  <tbody>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/tree/"><b>Leetcode: Practice Trees</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/heap-priority-queue/"><b>Leetcode: Practice Heap (Priority Queue)</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/union-find/"><b>Leetcode: Practice Segment Tree</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/segment-tree/"><b>Leetcode: Practice Union Find</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/binary-indexed-tree/"><b>Leetcode: Practice Binary Indexed Tree</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/depth-first-search/"><b>Leetcode: Practice Depth-First Search</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/breadth-first-search/"><b>Leetcode: Practice Breadth-First Search</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/binary-search-tree/"><b>Leetcode: Practice Binary Search Tree</b></a></td>
    </tr>
    <tr>
      <td><a target="_blank" href="https://leetcode.com/tag/trie/"><b>Leetcode: Practice Trie</b></a></td>
    </tr>
  </tbody>
</table>
</details>

[**Back To Top ⬆️**](#index)

## 3.11 Graph Data Structure

Moving on to another crucial non-linear structure, let's explore the Graph. Unlike the Tree, a Graph lacks a specific root or leaf node and allows traversal in any order.

A Graph is a non-linear structure composed of a finite set of vertices (or nodes) and a set of edges connecting pairs of nodes. It proves invaluable in solving various real-life problems. Graphs can take different forms based on edge orientation and node characteristics.

<!-- img -->

Key concepts to explore:

- **Types of Graphs:** Varying types based on connectivity or weights of nodes.
- **Introduction to BFS and DFS:** Algorithms for traversing through a graph.
- **Cycles in a Graph:** Series of connections leading to a loop.
- **Topological Sorting in the Graph**
- **Minimum Spanning Tree in Graph**

<details open>
  <summary><b>Resources: Graphs</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Graph Data Structure And Algorithms</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Depth First Search or DFS for a Graph</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>GRAPH TRAVERSAL (DFS/BFS)</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/dfsbfs"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Dijkstra’s shortest path algorithm<h/b></p></td>
      <td><a target="_blank" href="http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>SINGLE-SOURCE SHORTEST PATHS</b></p></td>
      <td><a target="_blank" href="https://visualgo.net/en/sssp"><b>visualgo.net</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Bellman Ford Algorithm</b></p></td>
      <td><a target="_blank" href="http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>One Source Shortest Path</b></p></td>
      <td><a target="_blank" href="https://compprog.wordpress.com/2007/11/29/one-source-shortest-path-the-bellman-ford-algorithm/"><b>compprog.wordpress.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Minimum spanning tree</b></p></td>
      <td><a target="_blank" href="https://www.cs.princeton.edu/courses/archive/fall19/cos226/lectures/43MinimumSpanningTrees.pdf"><b>cs.princeton.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Articulation points</b></p></td>
      <td><a target="_blank" href="https://www.iarcs.org.in/inoi/online-study-material/topics/articulation-points.php"><b>iarcs.org.in</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Strongly connected components</b></p></td>
      <td><a target="_blank" href="https://www.iarcs.org.in/inoi/online-study-material/topics/scc.php"><b>iarcs.org.in</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Topological Sorting</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/topological-sorting/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Euler Paths and Euler Circuits</b></p></td>
      <td><a target="_blank" href="https://jlmartin.ku.edu/~jlmartin/courses/math105-F11/Lectures/chapter5-part2.pdf"><b>jlmartin.ku.edu</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Fast Modulo Multiplication</b></p></td>
      <td><a target="_blank" href="https://discuss.codechef.com/t/a-tutorial-on-fast-modulo-multiplication-exponential-squaring/2899"><b>codechef.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Algos for Calculating nCr % M</b></p></td>
      <td><a target="_blank" href="https://discuss.codechef.com/t/best-known-algos-for-calculating-ncr-m/896"><b>codechef.com</b></a></td>
    </tr>
  </tbody>
</table>
</details>

<details open>
  <summary><b>Practice Problems: Graphs</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Two Closest</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/PAIRCLST"><b>codechef.com: PAIRCLST</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Special Shortest Walk</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/SPSHORT"><b>codechef.com: SPSHORT</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Robot Control</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/problemset/problem/346/D"><b>codeforces.com: 346/D</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Arbitrage</b></p></td>
      <td><a target="_blank" href="https://www.spoj.com/problems/ARBITRAG/"><b>spoj.com: ARBITRAG</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Cost</b></p></td>
      <td><a target="_blank" href="https://www.spoj.com/problems/HIGHWAYS/"><b>spoj.com: HIGHWAYS</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Police Query</b></p></td>
      <td><a target="_blank" href="https://www.spoj.com/problems/POLQUERY/"><b>spoj.com: POLQUERY</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Visiting Friends</b></p></td>
      <td><a target="_blank" href="https://www.spoj.com/problems/MCO16405/"><b>codechef.com: MCO16405</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Chef and Roads</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/CL16BF/"><b>codechef.com: CL16BF</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Codechef Password Recovery</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/CHEFPASS/"><b>codechef.com: CHEFPASS</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Tanya and Password</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/contest/508/problem/D"><b>codeforces.com: contest/508/problem/D</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>One-Way Reform</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/contest/723/problem/E"><b>codeforces.com: contest/723/problem/E</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Problem Statement for NetworkSecurity</b></p></td>
      <td><a target="_blank" href="https://community.topcoder.com/stat?c=problem_statement&pm=10736"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Leetcode: Interview Practice</b></p></td>
      <td><a target="_blank" href="https://leetcode.com/tag/graph/"><b>Leetcode: Practice Graphs</b></a></td>
    </tr>
  </tbody>
</table>
</details>

[**Back To Top ⬆️**](#index)

## 3.12 Recursion

Recursion stands out as a vital algorithm leveraging the concept of code reusability and repeated code usage. Its significance extends to being the foundation for many other algorithms, including:

<!-- img -->

- Tree Traversals
- Graph Traversals
- Divide and Conquer Algorithms
- Backtracking Algorithms

To explore Recursion thoroughly, refer to the following articles/links:

<details open>
  <summary><b>Resources: Recursion</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>AN INTRODUCTION TO RECURSION PART ONE</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/An%20Introduction%20to%20Recursion%20Part%20One"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
    <tr>
      <td><p>◌ <b>AN INTRODUCTION TO RECURSION PART TWO</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/An%20Introduction%20to%20Recursion%20Part%20Two"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Introduction to Recursion</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Backtracking, Memoization & Dynamic Programming!</b></p></td>
      <td><a target="_blank" href="https://loveforprogramming.quora.com/Backtracking-Memoization-Dynamic-Programming"><b>loveforprogramming.quora.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Recursion Interview Questions & Tips</b></p></td>
      <td><a target="_blank" href="https://interviewing.io/recursion-interview-questions"><b>interviewing.io</b></a></td>
    </tr>
  </tbody>
</table>
</details>

<details open>
  <summary><b>Practice Problems: Recursion</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Connecting Soldiers</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/NOKIA"><b>codechef.com: NOKIA</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Fit Squares in Triangle</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/TRISQ"><b>codechef.com: TRISQ</b></a></td>
    </tr>
    <tr>
    <tr>
      <td><p>◌ <b>Leetcode: Interview Practice</b></p></td>
      <td><a target="_blank" href="https://leetcode.com/tag/recursion/"><b>Leetcode: Practice Recursion</b></a></td>
    </tr>
  </tbody>
</table>
</details>

## 3.13 Backtracking Algorithm

Derived from Recursion, the Backtracking algorithm allows for retracing if a recursive solution fails, exploring alternative solutions. It systematically tries out all possible solutions to find the correct one.

Backtracking is an algorithmic technique that incrementally builds a solution, removing failed solutions that don't meet problem constraints.

<!-- img -->

Key problems to tackle in Backtracking algorithms:

- **Knight’s Tour Problem**
- **Rat in a Maze**
- **N-Queen Problem**
- **Subset Sum Problem**
- **M-Coloring Problem**
- **Hamiltonian Cycle**
- **Sudoku**

<details open>
  <summary><b>Resources: Backtracking</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Backtracking Algorithms</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/backtracking-algorithms/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
    <tr>
      <td><p>◌ <b>Recursion and Backtracking</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/blog/entry/118843"><b>codeforces.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Backtracking:the essential part of dynamic programming</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/blog/entry/102888"><b>codeforces.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Backtracking, Memoization & Dynamic Programming!</b></p></td>
      <td><a target="_blank" href="https://loveforprogramming.quora.com/Backtracking-Memoization-Dynamic-Programming"><b>loveforprogramming.quora.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Backtracking Archives</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/category/dsa/algorithm/backtracking/"><b>geeksforgeeks.org</b></a></td>
    </tr>
  </tbody>
</table>
</details>

<details open>
  <summary><b>Practice Problems: Backtracking</b></summary>
  <table>
  <tbody>
  <tr>
      <td><p>◌ <b>Leetcode: Interview Practice</b></p></td>
      <td><a target="_blank" href="https://leetcode.com/tag/backtracking/"><b>Leetcode: Practice Backtracking</b></a></td>
    </tr>
  </tbody>
</table>
</details>

[**Back To Top ⬆️**](#index)

## 3.14 Dynamic Programming

Dynamic Programming stands as a crucial algorithm, serving as an optimization over plain recursion. It becomes particularly valuable when a recursive solution involves repeated calls for the same inputs, allowing for optimization.

<!-- img -->

> Those who cannot remember the past are condemned to repeat it.
> </br> <div align="right">- <i>Dynamic Programming</i><div>

Key concepts to explore in Dynamic Programming:

- **Tabulation vs Memoization**
- **Optimal Substructure Property**
- **Overlapping Subproblems Property**
- **Bitmasking and Dynamic Programming**
- **Bitmasking and Dynamic Programming**
- **Digit DP**

### Basic DP

<details open>
  <summary><b>Resources: Basic Dynamic Programming</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Demystifying Dynamic Programming</b></p></td>
      <td><a target="_blank" href="https://www.freecodecamp.org/news/demystifying-dynamic-programming-3efafb8d4296"><b>freecodecamp.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>DP Tutorial and Problem List</b></p></td>
      <td><a target="_blank" href="https://codeforces.com/blog/entry/67679"><b>codeforces.com</b></a></td>
    </tr>
    <tr>
    <tr>
      <td><p>◌ <b>DYNAMIC PROGRAMMING: FROM NOVICE TO ADVANCED</b></p></td>
      <td><a target="_blank" href="https://www.topcoder.com/thrive/articles/Dynamic%20Programming:%20From%20Novice%20to%20Advanced"><b>topcoder.com</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Dynamic Programming</b></p></td>
      <td><a target="_blank" href="https://www.geeksforgeeks.org/dynamic-programming/"><b>geeksforgeeks.org</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Backtracking, Memoization & Dynamic Programming!</b></p></td>
      <td><a target="_blank" href="https://loveforprogramming.quora.com/Backtracking-Memoization-Dynamic-Programming"><b>loveforprogramming.quora.com</b></a></td>
    </tr>
  </tbody>
</table>
</details>

<details open>
  <summary><b>Practice Problems: Basic Dynamic Programming</b></summary>
  <table>
  <tbody>
    <tr>
      <td><p>◌ <b>Alternating subarray prefix</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/ALTARAY"><b>codechef.com: ALTARAY</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Subtraction Game 2</b></p></td>
      <td><a target="_blank" href="https://www.codechef.com/problems/AMSGAME2"><b>codechef.com: AMSGAME2</b></a></td>
    </tr>
    <tr>
      <td><p>◌ <b>Striver DP Series</b></p></td>
      <td><a target="_blank" href="https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/"><b>takeuforward.org</b></a></td>
    </tr>
    <tr>
    <tr>
      <td><p>◌ <b>Leetcode: Interview Practice</b></p></td>
      <td><a target="_blank" href="https://leetcode.com/tag/dynamic-programming/"><b>Leetcode: Practice Dynamic Programming</b></a></td>
    </tr>
  </tbody>
</table>
</details>


## CHEAT SHEET FOR TIME AND SPACE COMPLEXITIES:
https://www.bigocheatsheet.com/
