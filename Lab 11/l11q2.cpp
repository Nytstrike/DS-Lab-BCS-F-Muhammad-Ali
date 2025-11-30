#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    string meaning;
    Node *next;
    Node(string w, string m) : word(w), meaning(m), next(NULL) {}
};

class Dictionary
{
private:
    Node **table;
    int size;

    int hashFunction(string word)
    {
        int sum = 0;
        for (char c : word)
        {
            sum += (int)c;
        }
        return sum % size;
    }

public:
    Dictionary(int s = 100)
    {
        size = s;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }

    void Add_Record(string word, string meaning)
    {
        int index = hashFunction(word);

        Node *newNode = new Node(word, meaning);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Word '" << word << "' added successfully!" << endl;
    }

    void Word_Search(string word)
    {
        int index = hashFunction(word);
        Node *temp = table[index];

        while (temp != NULL)
        {
            if (temp->word == word)
            {
                cout << "search key " << word << ": " << temp->meaning << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Word '" << word << "' not found in dictionary!" << endl;
    }

    void Print_Dictionary()
    {
        bool isEmpty = true;
        for (int i = 0; i < size; i++)
        {
            Node *temp = table[i];
            if (temp != NULL)
            {
                isEmpty = false;
                cout << "index " << i << ": ";
                while (temp != NULL)
                {
                    cout << "(" << temp->word << ", " << temp->meaning << ")";
                    if (temp->next != NULL)
                        cout << " -> ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
        if (isEmpty)
        {
            cout << "Dictionary is empty!" << endl;
        }
    }

    void Delete_Word(string word)
    {
        int index = hashFunction(word);
        Node *temp = table[index];
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->word == word)
            {
                if (prev == NULL)
                {
                    table[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "key " << word << " deleted successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Error: Word '" << word << "' not found for deletion!" << endl;
    }

    ~Dictionary()
    {
        for (int i = 0; i < size; i++)
        {
            Node *temp = table[i];
            while (temp != NULL)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
};

int main()
{
    Dictionary dict;
    cout << "ASCII Code-Based Dictionary App" << endl;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "Computer Science");
    cout << "\nSearching words:" << endl;
    dict.Word_Search("AB");
    dict.Word_Search("CD");
    dict.Word_Search("XYZ");
    cout << "\nComplete Dictionary:" << endl;
    dict.Print_Dictionary();
    cout << "\nDeleting word:" << endl;
    dict.Delete_Word("EF");
    cout << "\nDictionary after deletion:" << endl;
    dict.Print_Dictionary();
    return 0;
}