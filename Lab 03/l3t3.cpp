#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class List
{
    Node *head;

public:
    List() : head(nullptr) {}

    Node *getHead() const
    {
        return head;
    }

    void setHead(Node *newHead)
    {
        head = newHead;
    }

    void insert_back(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    void insert_start(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void print_list()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->val;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void reverseKGroup(int k)
    {
        head = reverseKGroup(head, k);
    }

    Node *reverseKGroup(Node *head, int k)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        Node *temp = head;
        for (int i = 0; i < k; i++)
        {
            if (!temp)
                return head; //return as is
            temp = temp->next;
        }

        // Reversing k nodes
        while (curr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the remaining list and connect it
        if (next)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }

    ~List()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    List list1;

    // list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    for (int i = 1; i <= 8; i++)
    {
        list1.insert_back(i);
    }

    List list2;
    // list: 10 -> 20 -> 30
    list2.insert_back(10);
    list2.insert_back(20);
    list2.insert_back(30);

    List list3;
    //list: 100
    list3.insert_back(100);

    List list4;
    //Empty list: NULL

    cout << "Original List 1: ";
    list1.print_list();

    cout << "Reversing in groups of 3: ";
    list1.reverseKGroup(3);
    list1.print_list();

    cout << "\nOriginal List 2: ";
    list2.print_list();
    cout << "Reversing in groups of 2: ";
    list2.reverseKGroup(2);
    list2.print_list();

    cout << "\nOriginal List 3 (single element): ";
    list3.print_list();
    cout << "Reversing in groups of 5: ";
    list3.reverseKGroup(5);
    list3.print_list();

    cout << "\nOriginal List 4 (empty): ";
    list4.print_list();
    cout << "Reversing in groups of 2: ";
    list4.reverseKGroup(2);
    list4.print_list();

    // should return the same
    List list5;
    for (int i = 1; i <= 4; i++)
    {
        list5.insert_back(i);
    }
    cout << "\nOriginal List 5: ";
    list5.print_list();
    cout << "Reversing in groups of 1: ";
    list5.reverseKGroup(1);
    list5.print_list();

    return 0;
}