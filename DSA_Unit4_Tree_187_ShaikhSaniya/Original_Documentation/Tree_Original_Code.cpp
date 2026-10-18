#include <iostream>
#include <algorithm>
using namespace std;

// Structure of an AVL tree node
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

// Get height of a node
int height(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

// Calculate balance factor
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Create a new node
Node* createNode(int value)
{
    Node* node = new Node();

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Right rotation for LL imbalance
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotation for RR imbalance
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert a value into the AVL tree
Node* insert(Node* node, int value)
{
    // Perform normal BST insertion
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Calculate balance factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
    {
        cout << "LL Imbalance detected. Right Rotation performed.\n";
        return rightRotate(node);
    }

    // RR Case
    if (balance < -1 && value > node->right->data)
    {
        cout << "RR Imbalance detected. Left Rotation performed.\n";
        return leftRotate(node);
    }

    // LR Case
    if (balance > 1 && value > node->left->data)
    {
        cout << "LR Imbalance detected. Left and Right Rotations performed.\n";

        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data)
    {
        cout << "RL Imbalance detected. Right and Left Rotations performed.\n";

        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Display tree using inorder traversal
void displayInorder(Node* root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        cout << root->data << " ";
        displayInorder(root->right);
    }
}

// Display tree structure
void displayTree(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << "\n";

    displayTree(root->left, space);
}

// Main function
int main()
{
    Node* root = NULL;
    int n, value;

    cout << "AVL Imbalance Detection\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number of nodes.\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    displayInorder(root);

    cout << "\n\nBalanced AVL Tree:\n";
    displayTree(root);

    cout << "\n";
    return 0;
}
