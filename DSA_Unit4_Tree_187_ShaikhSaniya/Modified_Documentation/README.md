# Modified Documentation

## Topic
AVL Imbalance Detection Using C++

## Original Problem Statement
Write a C++ program to detect LL, RR, LR, and RL imbalances during AVL tree insertion, identify the rotation required, and display the balanced tree.

## Selected Modifications

### Modification 1: First Unbalanced Ancestor
Display the first unbalanced ancestor and its balance factor during insertion.

### Modification 2: Rotation Details
Record the rotation type and the affected node values.

### Modification 3: Testing and Balance Verification
Test all four rotation cases (LL, RR, LR, RL) and verify the final AVL tree balance conditions.

## Approach
The program inserts values into an AVL tree, updates node heights, calculates balance factors, detects imbalances, and performs the required rotations. It also displays rotation details and checks whether the final tree is balanced.

## Complexity Analysis
- Insertion: O(log n) on an AVL tree.
- Searching: O(log n) on an AVL tree.
- Space Complexity: O(n) for storing n nodes.
