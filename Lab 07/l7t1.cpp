#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;

    Node(const string &n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentList
{
private:
    Node *head;

    int getMaxScore() const
    {
        if (!head)
            return 0;

        int maxScore = head->score;
        for (Node *curr = head->next; curr; curr = curr->next)
        {
            if (curr->score > maxScore)
            {
                maxScore = curr->score;
            }
        }
        return maxScore;
    }

    void countingSortPass(int place)
    {
        Node *bucket[10] = {nullptr};
        Node *bucketTail[10] = {nullptr};

        Node *curr = head;
        while (curr)
        {
            int digit = (curr->score / place) % 10;
            Node *next = curr->next;
            curr->next = nullptr;

            if (bucket[digit] == nullptr)
            {
                bucket[digit] = bucketTail[digit] = curr;
            }
            else
            {
                bucketTail[digit]->next = curr;
                bucketTail[digit] = curr;
            }
            curr = next;
        }
        head = nullptr;
        Node *tail = nullptr;

        for (int i = 0; i < 10; ++i)
        {
            if (bucket[i])
            {
                if (head == nullptr)
                {
                    head = bucket[i];
                    tail = bucketTail[i];
                }
                else
                {
                    tail->next = bucket[i];
                    tail = bucketTail[i];
                }
            }
        }
    }

public:
    StudentList() : head(nullptr) {}

    ~StudentList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addNode(const string &name, int score)
    {
        Node *newNode = new Node(name, score);
        newNode->next = head;
        head = newNode;
    }

    void radixSort()
    {
        if (!head || !head->next)
            return;

        int maxScore = getMaxScore();

        for (int place = 1; maxScore / place > 0; place *= 10)
        {
            countingSortPass(place);
        }
    }

    bool deleteNode(const string &name)
    {
        if (!head)
            return false;

        if (head->name == name)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Search for the node to delete
        Node *prev = head;
        Node *curr = head->next;

        while (curr)
        {
            if (curr->name == name)
            {
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    void printList() const
    {
        if (!head)
        {
            cout << "List is empty.\n\n";
            return;
        }

        cout << left << setw(20) << "Name" << "Score\n";
        cout << string(30, '-') << "\n";

        for (Node *curr = head; curr; curr = curr->next)
        {
            cout << left << setw(20) << curr->name
                 << curr->score << "\n";
        }
        cout << "\n";
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    int getSize() const
    {
        int count = 0;
        for (Node *curr = head; curr; curr = curr->next)
        {
            count++;
        }
        return count;
    }
};

void displayMenu()
{
    cout << "\n========================================\n";
    cout << "       Student Record System\n";
    cout << "========================================\n";
}

int main()
{
    StudentList studentList;
    studentList.addNode("Ayan", 90);
    studentList.addNode("Zameer", 60);
    studentList.addNode("Sara", 70);
    studentList.addNode("Sohail", 30);
    studentList.addNode("Ahmed", 20);

    displayMenu();

    cout << "Original list:\n";
    studentList.printList();

    cout << "Applying Radix Sort...\n\n";
    studentList.radixSort();

    cout << "After Radix Sort (sorted by score):\n";
    studentList.printList();

    // Interactive deletion
    cout << "Enter a name to delete (type 'quit' to end): ";
    string input;

    while (cin >> input && input != "quit")
    {
        if (studentList.deleteNode(input))
        {
            cout << "Record for '" << input << "' deleted successfully.\n";
        }
        else
        {
            cout << "Record for '" << input << "' not found.\n";
        }

        cout << "\nUpdated list:\n";
        studentList.printList();

        if (studentList.isEmpty())
        {
            cout << "All records have been deleted.\n";
            break;
        }

        cout << "Enter another name to delete (or 'quit' to end): ";
    }

    cout << "\nProgram terminated. All memory cleaned up.\n";

    return 0;
}