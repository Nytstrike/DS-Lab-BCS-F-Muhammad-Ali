#include <iostream>
#include <list>
#include <string>
using namespace std;

class Hash
{
private:
    int size;
    list<pair<string, string>> *table;

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
        {
            sum += (int)c;
        }
        return sum % size;
    }

public:
    Hash(int s = 10)
    {
        size = s;
        table = new list<pair<string, string>>[size];
    }

    void insert(string key, string value)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                it->second = value;
                cout << "Key '" << key << "' updated with value '" << value << "'" << endl;
                return;
            }
        }
        table[index].push_back(make_pair(key, value));
        cout << "Key '" << key << "' inserted with value '" << value << "'" << endl;
    }

    void remove(string key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                cout << "Key '" << key << "' deleted successfully!" << endl;
                return;
            }
        }
        cout << "Key '" << key << "' not found for deletion!" << endl;
    }

    string search(string key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }
        return "Not found";
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Bucket " << i << ": ";
            if (table[i].empty())
            {
                cout << "Empty";
            }
            else
            {
                for (auto it = table[i].begin(); it != table[i].end(); it++)
                {
                    cout << "[" << it->first << ":" << it->second << "]";
                    if (next(it) != table[i].end())
                    {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    ~Hash()
    {
        delete[] table;
    }
};

int main()
{
    Hash hashTable;
    hashTable.insert("A", "Apple");
    hashTable.insert("B", "Banana");
    hashTable.insert("C", "Strawberry");
    hashTable.insert("A", "Pomegranate");
    cout << "\nSearch operations:" << endl;
    cout << "Search A: " << hashTable.search("A") << endl;
    cout << "Search B: " << hashTable.search("B") << endl;
    cout << "Search X: " << hashTable.search("X") << endl;
    cout << "\nHash table:" << endl;
    hashTable.display();
    cout << "Delete operations:" << endl;
    hashTable.remove("B");
    hashTable.remove("X");
    cout << "\nAfter deleting:" << endl;
    hashTable.display();
    hashTable.insert("D", "Melon");
    hashTable.insert("E", "Mango");
    cout << "Final:" << endl;
    hashTable.display();
    return 0;
}