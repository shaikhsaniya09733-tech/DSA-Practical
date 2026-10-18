#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int height(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int balanceFactor(Node* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;

    cout << "Rotation: Right Rotation" << endl;
    cout << "Affected nodes: " << y->data
         << " and " << x->data << endl;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;

    cout << "Rotation: Left Rotation" << endl;
    cout << "Affected nodes: " << x->data
         << " and " << y->data << endl;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
    {
        cout << "Duplicate value ignored: " << value << endl;
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = balanceFactor(root);

    // Modification 1: Detect first unbalanced ancestor
    if (bf > 1 || bf < -1)
    {
        cout << "\nFirst unbalanced ancestor: "
             << root->data << endl;
        cout << "Balance factor: " << bf << endl;

        // LL Case
        if (bf > 1 && value < root->left->data)
        {
            cout << "Imbalance type: LL" << endl;
            return rightRotate(root);
        }

        // RR Case
        if (bf < -1 && value > root->right->data)
        {
            cout << "Imbalance type: RR" << endl;
            return leftRotate(root);
        }

        // LR Case
        if (bf > 1 && value > root->left->data)
        {
            cout << "Imbalance type: LR" << endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL Case
        if (bf < -1 && value < root->right->data)
        {
            cout << "Imbalance type: RL" << endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Modification 3: Verify AVL balance conditions
bool verifyAVL(Node* root)
{
    if (root == NULL)
        return true;

    int bf = balanceFactor(root);

    if (bf < -1 || bf > 1)
        return false;

    return verifyAVL(root->left) && verifyAVL(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void displayTree(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

void deleteTree(Node* root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Node* root = NULL;
    int n, value;

    cout << "MODIFIED AVL IMBALANCE DETECTION" << endl;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number of nodes." << endl;
        return 0;
    }

    cout << "Enter " << n << " values:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\n\nBalanced AVL Tree:";
    displayTree(root);

    cout << "\nAVL Balance Verification: ";

    if (verifyAVL(root))
        cout << "PASS - Tree is balanced." << endl;
    else
        cout << "FAIL - Tree is not balanced." << endl;

    deleteTree(root);

    return 0;
}
