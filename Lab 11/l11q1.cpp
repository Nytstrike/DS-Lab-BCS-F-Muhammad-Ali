#include <iostream>
#include <string>
#include<utility>
using namespace std;
// class HashNode {
//     pair<string,string> Node;
//     HashNode *next;
//     HashNode(string key,string value){
//         Node = make_pair(key,value);
//         next = NULL;
//     }
// };
class HashNode
{
public:
    string key;
    string value;
    HashNode *next;

    HashNode(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable
{
private:
    HashNode **table;
    int capacity;
    int size;

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
        {
            sum += (int)c;
        }
        return sum % capacity;
    }

public:
    HashTable(int cap = 10)
    {
        capacity = cap;
        size = 0;
        table = new HashNode *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, string value)
    {
        int index = hashFunction(key);
        HashNode *newNode = new HashNode(key, value);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            HashNode *current = table[index];
            while (current != NULL)
            {
                if (current->key == key)
                {
                    current->value = value;
                    delete newNode;
                    return;
                }
                if (current->next == NULL)
                    break;
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    string search(string key)
    {
        int index = hashFunction(key);
        HashNode *current = table[index];
        while (current != NULL)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return "Not found";
    }

    void remove(string key)
    {
        int index = hashFunction(key);
        HashNode *current = table[index];
        HashNode *prev = NULL;
        while (current != NULL)
        {
            if (current->key == key)
            {
                if (prev == NULL)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket " << i << ": ";
            HashNode *current = table[i];
            if (current == NULL)
            {
                cout << "Empty";
            }
            else
            {
                while (current != NULL)
                {
                    cout << "[" << current->key << ": " << current->value << "]";
                    if (current->next != NULL)
                    {
                        cout << " -> ";
                    }
                    current = current->next;
                }
            }
            cout << endl;
        }
        cout << "Total size: " << size << endl
             << endl;
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            HashNode *current = table[i];
            while (current != NULL)
            {
                HashNode *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();
    cout << "Search results:" << endl;
    cout << "Search A: " << myhash.search("A") << endl;
    cout << "Search B: " << myhash.search("B") << endl;
    cout << "Search D: " << myhash.search("D") << endl;
    cout << endl;
    myhash.remove("B");
    cout << "After removing B:" << endl;
    myhash.display();
    myhash.insert("D", "ddddd");
    myhash.insert("E", "eeeee");
    myhash.insert("F", "fffff");
    cout << "After adding more elements:" << endl;
    myhash.display();
    return 0;
}