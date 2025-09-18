#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

class MultiLevelList {
private:
    Node* head;

public:
    MultiLevelList() : head(nullptr) {}

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

    void addChild(int parentVal, int childVal) {
        Node* parent = findNode(parentVal);
        if (parent) {
            if (!parent->child) {
                parent->child = new Node(childVal);
            } else {
                Node* temp = parent->child;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = new Node(childVal);
            }
        }
    }

    Node* findNode(int val) {
        return findNodeHelper(head, val);
    }

    Node* findNodeHelper(Node* node, int val) {
        if (!node) return nullptr;
        if (node->data == val) return node;
        
        Node* found = findNodeHelper(node->next, val);
        if (found) return found;
        
        return findNodeHelper(node->child, val);
    }

    void flatten() {
        head = flattenHelper(head);
    }

    Node* flattenHelper(Node* node) {
        if (!node) return nullptr;

        Node* current = node;
        Node* tail = nullptr;

        while (current) {
            Node* next = current->next;
            
            if (current->child) {
                Node* childHead = flattenHelper(current->child);
                Node* childTail = childHead;
                while (childTail && childTail->next) {
                    childTail = childTail->next;
                }
                
                current->next = childHead;
                if (childTail) {
                    childTail->next = next;
                }
                current->child = nullptr;
            }
            
            tail = current;
            current = current->next;
        }
        
        return node;
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

    void displayWithChildren() {
        displayWithChildrenHelper(head, 0);
    }

    void displayWithChildrenHelper(Node* node, int level) {
        if (!node) return;

        for (int i = 0; i < level; i++) cout << "  ";
        cout << node->data << endl;

        if (node->child) {
            displayWithChildrenHelper(node->child, level + 1);
        }

        if (node->next) {
            displayWithChildrenHelper(node->next, level);
        }
    }

    ~MultiLevelList() {
        deleteList(head);
    }

    void deleteList(Node* node) {
        if (!node) return;
        deleteList(node->next);
        deleteList(node->child);
        delete node;
    }
};

int main() {
    MultiLevelList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.addChild(1, 4);
    list.addChild(4, 5);

    cout << "Original multi-level structure:" << endl;
    list.displayWithChildren();

    cout << "\nBefore flattening:" << endl;
    list.display();

    list.flatten();

    cout << "\nAfter flattening:" << endl;
    list.display();

    MultiLevelList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(4);

    list2.addChild(1, 7);
    list2.addChild(7, 11);
    list2.addChild(11, 15);
    list2.addChild(3, 8);
    list2.addChild(8, 12);

    cout << "\n\nSecond example - Original structure:" << endl;
    list2.displayWithChildren();

    list2.flatten();

    cout << "\nAfter flattening:" << endl;
    list2.display();

    return 0;
}