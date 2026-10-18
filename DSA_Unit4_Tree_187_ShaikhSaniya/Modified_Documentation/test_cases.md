# Test Cases – AVL Imbalance Detection

## Test Case 1: LL Rotation

Input:
3
30 20 10

Expected Result:
- Imbalance Type: LL
- Rotation: Right Rotation
- Inorder Traversal: 10 20 30
- AVL Verification: PASS


## Test Case 2: RR Rotation

Input:
3
10 20 30

Expected Result:
- Imbalance Type: RR
- Rotation: Left Rotation
- Inorder Traversal: 10 20 30
- AVL Verification: PASS


## Test Case 3: LR Rotation

Input:
3
30 10 20

Expected Result:
- Imbalance Type: LR
- Rotations: Left Rotation followed by Right Rotation
- Inorder Traversal: 10 20 30
- AVL Verification: PASS


## Test Case 4: RL Rotation

Input:
3
10 30 20

Expected Result:
- Imbalance Type: RL
- Rotations: Right Rotation followed by Left Rotation
- Inorder Traversal: 10 20 30
- AVL Verification: PASS


## Test Case 5: Single Node

Input:
1
50

Expected Result:
- No imbalance detected
- Inorder Traversal: 50
- AVL Verification: PASS


## Conclusion

All four rotation cases and the single-node case are tested. The program verifies that the final AVL tree satisfies the balance-factor condition.
