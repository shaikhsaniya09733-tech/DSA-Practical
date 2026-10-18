# Algorithm: Modified AVL Imbalance Detection

1. Start the program.
2. Create an empty AVL tree.
3. Enter the number of nodes and their values.
4. Insert each value using Binary Search Tree insertion rules.
5. Update the height of each node.
6. Calculate the balance factor of each node.
7. Find the first unbalanced ancestor.
8. Display the unbalanced node and its balance factor.
9. Identify the imbalance type:
   - LL: Perform Right Rotation.
   - RR: Perform Left Rotation.
   - LR: Perform Left Rotation followed by Right Rotation.
   - RL: Perform Right Rotation followed by Left Rotation.
10. Record the rotation type and affected node values.
11. Repeat the process for all inserted values.
12. Verify that every node has a balance factor of -1, 0, or +1.
13. Display the inorder traversal and balanced AVL tree.
14. Stop the program.
