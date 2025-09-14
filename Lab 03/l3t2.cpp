#include<iostream>
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
    
    Node* getHead() const {
        return head;
    }
    
    void setHead(Node* newHead) {
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
    
    static Node* mergeSortedLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* head = nullptr;
        Node* tail = nullptr;

        if (a->val < b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        tail = head;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if (a) tail->next = a;
        if (b) tail->next = b;

        return head;
    }
    
    void mergeWith(List& other) {
        head = mergeSortedLists(head, other.getHead());
        other.setHead(nullptr);
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
    list1.insert_back(1);
    list1.insert_back(3);
    list1.insert_back(5);
    list1.insert_back(7);
    
    List list2;
    list2.insert_back(2);
    list2.insert_back(4);
    list2.insert_back(6);
    list2.insert_back(8);
    
    List list3;
    list3.insert_back(10);
    list3.insert_back(20);
    list3.insert_back(30);
    
    List list4;

    cout << "List 1: ";
    list1.print_list();
    
    cout << "List 2: ";
    list2.print_list();
    
    cout << "List 3: ";
    list3.print_list();
    
    cout << "List 4 (empty): ";
    list4.print_list();

    List merged1;
    merged1.setHead(List::mergeSortedLists(list1.getHead(), list2.getHead()));
    cout << "\nMerged List 1 and List 2: ";
    merged1.print_list();
    
    List merged2;
    merged2.setHead(List::mergeSortedLists(list3.getHead(), list4.getHead()));
    cout << "Merged List 3 and List 4 (empty): ";
    merged2.print_list();
    
    List empty1, empty2;
    List merged3;
    merged3.setHead(List::mergeSortedLists(empty1.getHead(), empty2.getHead()));
    cout << "Merged two empty lists: ";
    merged3.print_list();

    return 0;
}