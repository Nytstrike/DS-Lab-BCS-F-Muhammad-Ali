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

    void insert_back(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
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

    // Helper function to reverse a linked list
    Node* reverseList(Node* node)
    {
        Node* prev = nullptr;
        Node* current = node;
        Node* next = nullptr;
        
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Finding the middle of the linked list using slow and fast pointers
        Node *slow = head;
        Node *fast = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *secondHalf = reverseList(slow);
        Node *firstHalf = head;
        Node *tempSecondHalf = secondHalf;


        bool isPalin = true;
        while (tempSecondHalf != nullptr)
        {
            if (firstHalf->val != tempSecondHalf->val)
            {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            tempSecondHalf = tempSecondHalf->next;
        }
        reverseList(secondHalf);

        return isPalin;
    }

    void print_list()
    {
        Node *parser = head;

        while (parser != nullptr)
        {
            cout << parser->val;
            if (parser->next != nullptr)
                cout << " -> ";
            parser = parser->next;
        }
        cout << endl;
    }

    ~List()
    {
        Node *parser = head;
        while (parser != nullptr)
        {
            Node *nextNode = parser->next;
            delete parser;
            parser = nextNode;
        }
    }
};

int main()
{
    //initializing all lists
    List l1, l2, l3;
    l1.insert_back(1);
    l1.insert_back(2);
    l1.insert_start(1);
    l1.insert_start(2);
    
    l2.insert_back(3);
    l2.insert_start(4);
    l2.insert_start(3);
    l3.insert_back(4);
    l3.insert_back(5);
    l3.insert_back(1);
    l1.print_list();
    cout<<"\n";
    cout << "Is List 1 a palindrome: " << (l1.isPalindrome() ? "Yes" : "No") << endl;
cout<<"\n";
    l2.print_list();
cout<<"\n";
    cout << "Is List 2 a palindrome: " << (l2.isPalindrome() ? "Yes" : "No") << endl;
    l3.print_list();
    cout << "Is List 3 a palindrome: " << (l3.isPalindrome() ? "Yes" : "No") << endl;
cout<<"\n";

    return 0;
}
