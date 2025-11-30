//question 3

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
       this->data= data;
        left = right = NULL;
        height = 1;
    }
};

int height(Node *n)
{
    if (!n)
    {
        return 0;
    }
    return n->height;
}

int balance(Node *n)
{
    return height(n->left) - height(n->right);
}

void update(Node *n)
{
    int lh = height(n->left);
    int rh = height(n->right);
    n->height = 1 + (lh > rh ? lh : rh);
}

Node *rotate_right(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    update(y);
    update(x);
    return x;
}

Node *rotate_left(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    update(x);
    update(y);
    return y;
}

Node *insert(Node *n, int v)
{
    if (!n)
    {
        return new Node(v);
    }

    if (v < n->data)
    {
        n->left = insert(n->left, v);
    }
    else if (v > n->data)
    {
        n->right = insert(n->right, v);
    }
    else
    {
        return n;
    }

    update(n);
    int b = balance(n);
    if (b > 1 && v < n->left->data)
    {
        return rotate_right(n);
    }
    if (b < -1 && v > n->right->data)
    {
        return rotate_left(n);
    }
    if (b > 1 && v > n->left->data)
    {
        n->left = rotate_left(n->left);
        return rotate_right(n);
    }
    if (b < -1 && v < n->right->data)
    {
        n->right = rotate_right(n->right);
        return rotate_left(n);
    }
    return n;
}

void inorder(Node *n)
{
    if (!n)
        return;
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}

void print_balance(Node *n)
{
    if (!n)
        return;
    print_balance(n->left);
    cout << "Node " << n->data << " BF = " << balance(n) << endl;
    print_balance(n->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    root = insert(root, 12);
    cout << "\nbalance Factors:\n";
    print_balance(root);
    cout << "\nheight of Tree: " << height(root) << endl;
    cout << "\nFinal AVL Tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
