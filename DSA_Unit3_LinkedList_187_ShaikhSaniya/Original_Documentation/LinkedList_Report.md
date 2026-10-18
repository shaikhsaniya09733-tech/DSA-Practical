# SMART CANTEEN ORDER MANAGEMENT SYSTEM
## DSA Unit III – Linked List Project

---

## 1. Introduction

A Smart Canteen Order Management System is a simple C++ application used to manage food orders in a college canteen.

The system uses a Singly Linked List to store and manage student food orders dynamically. It allows users to add new orders, display pending orders, search for a particular order, and delete completed orders.

This project demonstrates the practical use of linked lists in Data Structures and Algorithms.

## 2. Problem Statement

Implement a Singly Linked List to maintain student food orders.

The system should perform the following operations:

1. Insert a new order at the beginning.
2. Insert a new order at the end.
3. Display all pending orders.
4. Search for a specific order using its Order ID.
5. Delete a completed order using its Order ID.

The system is implemented using C++ and demonstrates the practical application of a Singly Linked List in managing canteen orders.

## 3. Objectives

The main objectives of this project are:

1. To understand the concept of a Singly Linked List.
2. To implement insertion and deletion operations.
3. To search for a food order using its Order ID.
4. To display all pending orders.
5. To understand dynamic memory allocation in C++.
6. To apply data structures to a real-life problem.

## 4. Data Structure Used

### Singly Linked List

A Singly Linked List is a linear data structure consisting of nodes. Each node contains data and a pointer to the next node.

In this project, each node stores the following information:

- Order ID
- Student Name
- Food Item
- Pointer to the Next Node

### Structure of a Node

Each node contains:

1. `orderId` – Stores the unique order identification number.
2. `studentName` – Stores the name of the student.
3. `foodItem` – Stores the name of the ordered food item.
4. `next` – Stores the address of the next node.

The `head` pointer points to the first node of the linked list. If the list is empty, the head pointer is NULL.

## 5. Algorithm

1. Start the program.
2. Initialize the head pointer to NULL.
3. Display the menu of operations.
4. Accept the user's choice.
5. Perform the selected operation:
   - Insert a new order at the beginning.
   - Insert a new order at the end.
   - Display all pending orders.
   - Search for an order using Order ID.
   - Delete a completed order using Order ID.
6. Repeat the menu until the user selects Exit.
7. Free the allocated memory.
8. Stop the program.

## 6. Flowchart

The flowchart represents the sequence of operations performed by the Smart Canteen Order Management System.

The program starts by initializing the linked list. It then displays a menu and accepts the user's choice. According to the selected operation, the program inserts, displays, searches, or deletes an order.

The menu is displayed repeatedly until the user selects the Exit option. Finally, the allocated memory is released, and the program terminates.

**Flowchart:** Refer to `Original_Flowchart.png` uploaded in this folder.

## 7. Working of the Program

The program provides a menu-driven interface to manage canteen orders.

### 7.1 Insert Order at the Beginning

This operation adds a new order at the beginning of the linked list.

The new node is created and linked to the current first node. The head pointer is then updated to point to the new node.

### 7.2 Insert Order at the End

This operation adds a new order at the end of the linked list.

A new node is created. If the list is empty, the head pointer points to the new node. Otherwise, the program traverses the list and connects the last node to the new node.

### 7.3 Display Pending Orders

This operation displays all orders stored in the linked list.

The program starts from the head pointer and visits each node until it reaches NULL. It displays the Order ID, Student Name, and Food Item of every order.

If the list is empty, an appropriate message is displayed.

### 7.4 Search Order by ID

This operation searches for a particular order using its Order ID.

The program traverses the linked list and compares the entered Order ID with the ID stored in each node. If a match is found, the order details are displayed. Otherwise, a message indicates that the order was not found.

### 7.5 Delete Completed Order

This operation removes a completed order from the linked list using its Order ID.

The program searches for the specified order and adjusts the links to remove the corresponding node. The memory occupied by the deleted node is released.

The program also handles deletion from the beginning of the list and deletion when the list is empty.

### 7.6 Exit

When the user selects Exit, the program releases the dynamically allocated memory and terminates.

## 8. Programming Language and Concepts Used

### Programming Language: C++

The project is developed using C++.

The following concepts are used:

1. **Structures:** To define the data members of each node.
2. **Pointers:** To connect nodes in the linked list.
3. **Dynamic Memory Allocation:** To create nodes when required.
4. **Functions:** To perform individual operations.
5. **Loops:** To display the menu repeatedly and traverse the list.
6. **Conditional Statements:** To select operations and handle different cases.
7. **Linked List:** To store and manage orders dynamically.

## 9. Advantages

1. **Dynamic Size:** The linked list can grow or shrink as orders are added or deleted.
2. **Easy Insertion:** New orders can be inserted at the beginning or end.
3. **Easy Deletion:** Completed orders can be removed when required.
4. **Searching:** Orders can be searched using their Order ID.
5. **Memory Utilization:** Memory is allocated dynamically as new nodes are created.
6. **Real-Life Application:** The project demonstrates the use of linked lists in canteen order management.

## 10. Applications

The concepts used in this project can be applied to:

1. College canteen order systems.
2. Restaurant order management.
3. Food delivery order tracking.
4. Token-based service systems.
5. Basic billing and order-processing applications.

## 11. Conclusion

We successfully implemented a Smart Canteen Order Management System using a Singly Linked List in C++.

The project demonstrates insertion at the beginning and end, displaying pending orders, searching for an order using its Order ID, and deleting completed orders.

Through this project, we understood the practical implementation of linked lists, pointers, dynamic memory allocation, and basic data structure operations.

The project shows how a simple data structure can be used to solve a real-life order management problem.
