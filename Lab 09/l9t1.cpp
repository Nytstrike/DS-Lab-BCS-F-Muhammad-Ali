#include <iostream>
using namespace std;
//question 2

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

class AVL
{
    Node *root;

    int get_height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    void update_height(Node *node)
    {
        int l_h = get_height(node->left);
        int r_h = get_height(node->right);
        node->height = 1 + max(l_h, r_h);
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        update_height(x);
        update_height(y);
        return y;
    }

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        else
        {
            return node;
        }
        update_height(node);
        return node;
    }

    void inorder(Node *node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void rotate_root_left()
    {
        root = rotate_left(root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVL t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    t.insert(55);
    t.rotate_root_left();
    t.display();
    return 0;
}