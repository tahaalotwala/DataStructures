# Data Structures Implementation in C

## Overview

This repository contains fundamental data structures implemented from scratch in **C**. The goal of this project is to provide a clear and concise implementation of key data structures that form the foundation of **Data Structures and Algorithms (DSA)**. Each data structure is implemented in isolation to help users understand the underlying principles and functionality before integrating them into larger applications.

These implementations aim to build a strong foundation for understanding DSA concepts, which are critical for solving complex algorithmic problems.

## Data Structures Implemented

The following data structures are implemented in this repository:

### 1. **Stack Using Array (1_Stack_using_array.c)**
   - A **stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.
   - This implementation uses an array to store stack elements, supporting operations like `push`, `pop`, `peek`, and `isEmpty`.
   
### 2. **Linear Queue Using Array (4_LinearQ_UsingArray.c)**
   - A **queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.
   - This implementation uses a static array to represent the queue and provides methods such as `enqueue`, `dequeue`, and `isEmpty`.

### 3. **Circular Queue (5_Circular_Queue.c)**
   - A **circular queue** is a variation of a linear queue where the last element connects back to the first element, creating a circular structure.
   - This implementation solves the problem of unused space that can occur in a linear queue using array-based implementation.

### 4. **Singly Linked List (6_Singly_Linked_List.c)**
   - A **singly linked list** is a linear collection of elements where each element (node) points to the next element in the list.
   - Operations such as insertion, deletion, searching, and traversal are implemented in this linked list.

### 5. **Circular Linked List (7_CircularLL.c)**
   - A **circular linked list** is a variation of the singly linked list where the last node points back to the first node, making the list circular.
   - This implementation supports operations such as insertion, deletion, and traversal.

### 6. **Stack Using Linked List (8_Stack_usingLL.c)**
   - This is a **stack** implemented using a **singly linked list**, which dynamically adjusts its size by allocating memory for each new element.
   - The stack supports `push`, `pop`, and `peek` operations, providing an alternative to the array-based implementation.

### 7. **Binary Search Tree (9_BinarySearchTree.c)**
   - A **binary search tree (BST)** is a tree-based data structure where each node has at most two children, with the left child containing a smaller value and the right child containing a larger value than its parent.
   - This implementation includes operations like `insert`, `search`, `delete`, and `inOrderTraversal` to demonstrate tree-based operations.

## Key Concepts Covered

- **Linear Data Structures**: Understanding the array and linked list-based structures like **stack**, **queue**, and **linked list**.
- **Dynamic Memory Allocation**: Using pointers to create dynamic structures such as linked lists and trees.
- **Tree Data Structures**: Specifically, the **binary search tree** for efficient searching, insertion, and deletion.
- **Circular Structures**: Implementation of **circular queue** and **circular linked list** to overcome specific limitations in their linear counterparts.
  
## Benefits of This Repository

- **Foundation for Data Structures**: This repository provides a hands-on understanding of how data structures work at the low level, aiding in deeper learning for **DSA**.
- **Efficient Algorithms**: The data structures and their operations are optimized for better performance, which helps in understanding the complexity of operations.
- **Code Readability**: The code is written in a clear and readable manner, making it easy for users to follow and modify.
- **Step-by-step Implementation**: Each data structure is implemented in isolation, so users can learn the fundamentals before moving on to more complex structures.

## Future Enhancements

- **Additional Data Structures**: Adding more complex data structures like **heaps**, **graphs**, and **tries** to further expand the DSA foundation.
- **Algorithmic Integration**: Integrating common algorithms like **sorting**, **searching**, and **graph traversal** to demonstrate how these data structures are utilized in problem-solving.
- **Optimization and Refinement**: Further optimizations and refinements to enhance the efficiency of operations like insertion, deletion, and searching, especially for tree-based structures.
