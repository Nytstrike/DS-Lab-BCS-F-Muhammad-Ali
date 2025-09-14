#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }

    DoublyNode* convertToDoublyLinkedList() {
        if (!head) return nullptr;

        DoublyNode* dHead = new DoublyNode(head->data);
        DoublyNode* dCurrent = dHead;
        Node* sCurrent = head->next;

        while (sCurrent) {
            DoublyNode* newNode = new DoublyNode(sCurrent->data);
            dCurrent->next = newNode;
            newNode->prev = dCurrent;
            dCurrent = newNode;
            sCurrent = sCurrent->next;
        }
        return dHead;
    }

    Node* convertToCircularLinkedList() {
        if (!head) return nullptr;

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        return head;
    }

    static void displayDoublyLinkedList(DoublyNode* dHead) {
        DoublyNode* temp = dHead;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;

        temp = dHead;
        while (temp && temp->next) {
            temp = temp->next;
        }

        cout << "Backward: ";
        while (temp) {
            cout << temp->data;
            if (temp->prev) cout << " <-> ";
            temp = temp->prev;
        }
        cout << " -> NULL" << endl;
    }

    static void displayCircularLinkedList(Node* cHead) {
        if (!cHead) {
            cout << "Empty circular list" << endl;
            return;
        }

        Node* temp = cHead;
        cout << "Circular: ";
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != cHead) cout << " -> ";
        } while (temp != cHead);
        cout << " -> (back to " << cHead->data << ")" << endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    static void cleanupDoublyLinkedList(DoublyNode* dHead) {
        DoublyNode* temp = dHead;
        while (temp) {
            DoublyNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    cout << "=== SINGLY LINKED LIST CONVERSIONS ===" << endl;
    
    LinkedList list1, list2, list3;
    
    for (int i = 1; i <= 5; i++) {
        list1.insert(i);
    }
    
    list2.insert(10);
    list2.insert(20);
    list2.insert(30);
    
    list3.insert(100);

    cout << "\n=== ORIGINAL SINGLY LINKED LISTS ===" << endl;
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();
    cout << "List 3: ";
    list3.display();

    cout << "\n=== CONVERSION TO DOUBLY LINKED LIST ===" << endl;
    
    DoublyNode* dList1 = list1.convertToDoublyLinkedList();
    cout << "List 1 as Doubly Linked List:" << endl;
    LinkedList::displayDoublyLinkedList(dList1);
    
    DoublyNode* dList2 = list2.convertToDoublyLinkedList();
    cout << "\nList 2 as Doubly Linked List:" << endl;
    LinkedList::displayDoublyLinkedList(dList2);
    
    DoublyNode* dList3 = list3.convertToDoublyLinkedList();
    cout << "\nList 3 as Doubly Linked List:" << endl;
    LinkedList::displayDoublyLinkedList(dList3);

    cout << "\n=== CONVERSION TO CIRCULAR LINKED LIST ===" << endl;
    
    Node* cList1 = list1.convertToCircularLinkedList();
    cout << "List 1 as Circular Linked List:" << endl;
    LinkedList::displayCircularLinkedList(cList1);
    
    Node* cList2 = list2.convertToCircularLinkedList();
    cout << "\nList 2 as Circular Linked List:" << endl;
    LinkedList::displayCircularLinkedList(cList2);
    
    Node* cList3 = list3.convertToCircularLinkedList();
    cout << "\nList 3 as Circular Linked List:" << endl;
    LinkedList::displayCircularLinkedList(cList3);

    LinkedList::cleanupDoublyLinkedList(dList1);
    LinkedList::cleanupDoublyLinkedList(dList2);
    LinkedList::cleanupDoublyLinkedList(dList3);

    return 0;
}